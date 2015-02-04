#include <glib.h>
#include <gtk/gtk.h>
#include <gdk/gdkx.h>
#include <libxklavier/xklavier.h>
#include <libappindicator/app-indicator.h>

#include "global.h"
#include "about.h"
#include "settings.h"
#include "indicator.h"

void
reset_settings (XklEngine * engine);
GdkFilterReturn
handle_xevent (GdkXEvent * xev, G_GNUC_UNUSED void * event, gpointer data);
void
xkb_state_changed (XklEngine * engine, XklEngineStateChange change,
                   gint group, gboolean G_GNUC_UNUSED restore);
void
xkb_config_changed (XklEngine * engine);

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

  /* Create indicator */
  indicator = create_indicator ();

  /* Set icon to current lang */
  update_icon (engine, -1);

  gtk_main ();
  return 0;
}
