#include "indicator.h"

#include "global.h"

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

AppIndicator *
create_indicator ()
{
  AppIndicator * indicator;
  GtkBuilder * menu_builder;
  GMenuModel * menu_model;
  GSimpleActionGroup * menu_actions;
  GtkMenu * menu;

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

  return indicator;
}
