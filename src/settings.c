#include "settings.h"

#include "global.h"

void
settings_apply (G_GNUC_UNUSED GtkButton * button,
                gpointer user_data);
void
settings_close (G_GNUC_UNUSED GtkButton * button,
                gpointer user_data);

void
show_settings (G_GNUC_UNUSED GSimpleAction * action,
               G_GNUC_UNUSED GVariant * parameter,
               G_GNUC_UNUSED gpointer user_data)
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
