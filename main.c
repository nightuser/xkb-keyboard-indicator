#include <glib.h>
#include <gtk/gtk.h>
#include <gdk/gdkx.h>
#include <libxklavier/xklavier.h>
#include <libappindicator/app-indicator.h>

#include "version.h"

AppIndicator * indicator;
XklEngine * engine;
XklConfigRec * config_rec;
GSettings * settings;
gulong xkb_state_changed_handler;
gulong xkb_config_changed_handler;

void
update_icon (XklEngine * engine, gint group);
void
show_about (G_GNUC_UNUSED GSimpleAction * action,
            G_GNUC_UNUSED GVariant * parameter,
            G_GNUC_UNUSED gpointer * user_data);
void
show_settings (G_GNUC_UNUSED GSimpleAction * action,
               G_GNUC_UNUSED GVariant * parameter,
               G_GNUC_UNUSED gpointer * user_data);
void
settings_apply (G_GNUC_UNUSED GtkButton * button,
                gpointer user_data);
void
settings_close (G_GNUC_UNUSED GtkButton * button,
                gpointer user_data);
void
reset_settings (XklEngine * engine);
GdkFilterReturn
handle_xevent (GdkXEvent * xev, G_GNUC_UNUSED void * event, gpointer data);
void
xkb_state_changed (XklEngine * engine, XklEngineStateChange change,
                   gint group, gboolean G_GNUC_UNUSED restore);
void
xkb_config_changed (XklEngine * engine);

GActionEntry const menu_entries[] = {
  { "settings", show_settings },
  { "about", show_about },
  { "quit", gtk_main_quit },
};

void
update_icon (XklEngine * engine, gint group)
{
  if (group == -1)
  {
    group = xkl_engine_get_current_state(engine)->group;
  }
  gchar const ** names = xkl_engine_get_groups_names (engine);
  g_message ("New layout is: %s", names[group]);
  gchar * name = g_strndup (names[group], 2);

  gchar * icon_name = g_strconcat ("indicator-keyboard-", name, NULL);

  GtkIconTheme * icon_theme = gtk_icon_theme_get_default ();
  if (gtk_icon_theme_has_icon(icon_theme, icon_name))
  {
    app_indicator_set_icon (indicator, icon_name);
  }
  else {
    app_indicator_set_icon (indicator, "image-missing");
  }

  g_free (icon_name);
  g_free (name);
}

void
reset_settings (XklEngine * engine)
{
  gchar ** settings_layouts = g_settings_get_strv (settings, "layouts");
  xkl_config_rec_set_layouts (config_rec, (gchar const **) settings_layouts);
  g_free (settings_layouts);

  gchar ** settings_options = g_settings_get_strv (settings, "options");
  xkl_config_rec_set_options (config_rec, (gchar const **) settings_options);
  g_free (settings_options);

  xkl_config_rec_activate (config_rec, engine);
}

void
show_about (G_GNUC_UNUSED GSimpleAction * action,
            G_GNUC_UNUSED GVariant * parameter,
            G_GNUC_UNUSED gpointer * user_data)
{
  GtkBuilder * dialog_builder;
  GtkAboutDialog * dialog;

  dialog_builder = gtk_builder_new_from_resource ("/ru/nightuser/xki/about-dialog.ui");
  dialog = GTK_ABOUT_DIALOG (gtk_builder_get_object (dialog_builder,
                                                     "AboutDialog"));

  g_signal_connect_swapped (GTK_WIDGET (dialog), "response",
                            G_CALLBACK (gtk_widget_destroy),
                            dialog);

  gtk_about_dialog_set_version (dialog, XKI_VERSION);

  gtk_widget_show (GTK_WIDGET (dialog));
}

void
show_settings (G_GNUC_UNUSED GSimpleAction * action,
               G_GNUC_UNUSED GVariant * parameter,
               G_GNUC_UNUSED gpointer * user_data)
{
  GtkBuilder * dialog_builder;
  GtkWidget * dialog;
  GtkWidget * apply_button;
  GtkWidget * close_button;
  GtkEntry * layouts_entry;
  GtkEntry * options_entry;

  dialog_builder = gtk_builder_new_from_resource ("/ru/nightuser/xki/settings-dialog.ui");
  dialog = GTK_WIDGET (gtk_builder_get_object (dialog_builder,
                                               "SettingsDialog"));

  apply_button = GTK_WIDGET (gtk_builder_get_object (dialog_builder,
                                                     "ApplyButton"));
  g_signal_connect (apply_button,
                    "clicked",
                    G_CALLBACK (settings_apply),
                    dialog_builder);

  close_button = GTK_WIDGET (gtk_builder_get_object (dialog_builder,
                                                     "CloseButton"));
  g_signal_connect (close_button,
                    "clicked",
                    G_CALLBACK (settings_close),
                    dialog);

  gchar ** settings_layouts = g_settings_get_strv (settings, "layouts");
  gchar * settings_layouts_str = g_strjoinv (",", settings_layouts);
  layouts_entry = GTK_ENTRY (gtk_builder_get_object (dialog_builder,
                                                     "LayoutsEntry"));
  gtk_entry_set_text (layouts_entry, (gchar const *) settings_layouts_str);
  g_free (settings_layouts_str);
  g_free (settings_layouts);

  gchar ** settings_options = g_settings_get_strv (settings, "options");
  gchar * settings_options_str = g_strjoinv (",", settings_options);
  options_entry = GTK_ENTRY (gtk_builder_get_object (dialog_builder,
                                                     "OptionsEntry"));
  gtk_entry_set_text (options_entry, (gchar const *) settings_options_str);
  g_free (settings_options_str);
  g_free (settings_options);

  gtk_widget_show (dialog);
}

void
settings_apply (G_GNUC_UNUSED GtkButton * button,
                gpointer user_data)
{
  GtkBuilder * dialog_builder;
  GtkEntry * layouts_entry;
  GtkEntry * options_entry;

  dialog_builder = GTK_BUILDER (user_data);

  /* Get, save and apply layouts text */
  layouts_entry = GTK_ENTRY (gtk_builder_get_object (dialog_builder,
                                                     "LayoutsEntry"));
  gchar const * settings_layouts_str = gtk_entry_get_text (layouts_entry);
  gchar ** settings_layouts = g_strsplit (settings_layouts_str, ",", -1);
  g_settings_set_strv (settings, "layouts",
                       (gchar const * const *) settings_layouts);
  xkl_config_rec_set_layouts (config_rec, (gchar const **) settings_layouts);
  g_free (settings_layouts);

  /* Get, save and apply options text */
  options_entry = GTK_ENTRY (gtk_builder_get_object (dialog_builder,
                                                     "OptionsEntry"));
  gchar const * settings_options_str = gtk_entry_get_text (options_entry);
  gchar ** settings_options = g_strsplit (settings_options_str, ",", -1);
  g_settings_set_strv (settings, "options",
                       (gchar const * const *) settings_options);
  xkl_config_rec_set_options (config_rec, (gchar const **) settings_options);
  g_free (settings_options);

  /* Activate settings */
  xkl_config_rec_activate (config_rec, engine);
}

void
settings_close (G_GNUC_UNUSED GtkButton * button,
                gpointer user_data)
{
  GtkWidget * dialog;

  dialog = GTK_WIDGET (user_data);
  gtk_widget_destroy (dialog);
}

GdkFilterReturn
handle_xevent (GdkXEvent * xev, G_GNUC_UNUSED void * event, gpointer data)
{
  XklEngine * engine = (XklEngine *) data;
  XEvent * xevent = (XEvent *) xev;
  xkl_engine_filter_events (engine, xevent);
  return GDK_FILTER_CONTINUE;
}

void
xkb_state_changed (XklEngine * engine, XklEngineStateChange change,
                   gint group, gboolean G_GNUC_UNUSED restore)
{
  if (change == GROUP_CHANGED)
  {
    update_icon (engine, group);
  }
}

void
xkb_config_changed (XklEngine * engine)
{
  g_message ("Config has been changed! Do something with it.");

  /* todo: reset settings */
  /* problem: circular signals; arrays comparison isn't a good idea */

  /*g_signal_handler_block (engine, xkb_config_changed_handler);
  reset_settings (engine);
  g_signal_handler_unblock (engine, xkb_config_changed_handler);*/
}

int
main (int argc, char ** argv)
{
  Display * display;
  GtkBuilder * menu_builder;
  GMenuModel * menu_model;
  GSimpleActionGroup * menu_actions;
  GtkMenu * menu;

  gtk_init (&argc, &argv);

  /* Create engine */
  display = gdk_x11_get_default_xdisplay ();
  engine = xkl_engine_get_instance (display);

  /* Config */
  config_rec = xkl_config_rec_new ();
  xkl_config_rec_get_from_server (config_rec, engine);

  /* Set settings values */
  settings = g_settings_new ("apps.xki");
  reset_settings (engine);

  /* Start listen */
  xkl_engine_start_listen (engine, XKLL_TRACK_KEYBOARD_STATE);

  /* Connect to XKB signals */
  xkb_state_changed_handler = g_signal_connect (engine, "X-state-changed",
                                                G_CALLBACK (xkb_state_changed), NULL);
  xkb_config_changed_handler = g_signal_connect (engine, "X-config-changed",
                                                 G_CALLBACK (xkb_config_changed), NULL);
  gdk_window_add_filter (NULL, (GdkFilterFunc) handle_xevent, engine);

  /* Menu */
  menu_builder = gtk_builder_new_from_resource ("/ru/nightuser/xki/menu.ui");
  menu_model = G_MENU_MODEL (gtk_builder_get_object (menu_builder,
                                                     "IndicatorPopup"));
  menu_actions = g_simple_action_group_new ();
  g_action_map_add_action_entries (G_ACTION_MAP (menu_actions), menu_entries,
                                   G_N_ELEMENTS (menu_entries), NULL);
  menu = GTK_MENU (gtk_menu_new_from_model (menu_model));
  gtk_widget_insert_action_group (GTK_WIDGET (menu), "app",
                                  G_ACTION_GROUP (menu_actions));

  /* Indicator */
  indicator = app_indicator_new ("xkb-keyboard-indicator",
                                 "image-missing",
                                 APP_INDICATOR_CATEGORY_APPLICATION_STATUS);
  app_indicator_set_status (indicator, APP_INDICATOR_STATUS_ACTIVE);
  app_indicator_set_menu (indicator, menu);

  /* Set icon to current lang */
  update_icon (engine, -1);

  gtk_main ();
  return 0;
}
