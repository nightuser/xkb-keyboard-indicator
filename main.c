#include <glib.h>
#include <gtk/gtk.h>
#include <gdk/gdkx.h>
#include <libxklavier/xklavier.h>
#include <libappindicator/app-indicator.h>

AppIndicator * indicator;
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
    app_indicator_set_icon (indicator, "unknown");
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
  GtkWidget * dialog;

  dialog_builder = gtk_builder_new_from_resource ("/ru/nightuser/xki/about-dialog.ui");
  dialog = GTK_WIDGET (gtk_builder_get_object (dialog_builder,
                                             "AboutDialog"));

  g_signal_connect_swapped (dialog, "response",
                            G_CALLBACK (gtk_widget_destroy),
                            dialog);

  gtk_widget_show (dialog);
}

void
show_settings (G_GNUC_UNUSED GSimpleAction * action,
               G_GNUC_UNUSED GVariant * parameter,
               G_GNUC_UNUSED gpointer * user_data)
{
  g_message ("Unimplemented");
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
  // todo: reset settings
  // problem: circular signals; arrays comparison isn't a good idea
  g_signal_handler_block (engine, xkb_config_changed_handler);
  reset_settings (engine);
  g_signal_handler_unblock (engine, xkb_config_changed_handler);
}

int
main (int argc, char ** argv)
{
  XklEngine * engine;
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
                                 "unknown",
                                 APP_INDICATOR_CATEGORY_APPLICATION_STATUS);
  app_indicator_set_status (indicator, APP_INDICATOR_STATUS_ACTIVE);
  app_indicator_set_menu (indicator, menu);

  /* Set icon to current lang */
  update_icon (engine, -1);

  gtk_main ();
  return 0;
}
