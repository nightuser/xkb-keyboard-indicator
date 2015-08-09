#include "about.h"

#include "config.h"

void
show_about (G_GNUC_UNUSED GSimpleAction * action,
            G_GNUC_UNUSED GVariant * parameter,
            G_GNUC_UNUSED gpointer user_data)
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
