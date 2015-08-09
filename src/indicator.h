#pragma once

#include <glib.h>
#include <libxklavier/xklavier.h>
#include <libappindicator/app-indicator.h>

#include "global.h"
#include "about.h"
#include "settings.h"

static GActionEntry const menu_entries[] = {
  { "settings", show_settings, NULL, NULL, NULL },
  { "about", show_about, NULL, NULL, NULL },
  { "quit", main_quit, NULL, NULL, NULL },
};

void
update_icon (XklEngine * engine, gint group);

AppIndicator *
create_indicator ();
