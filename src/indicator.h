#pragma once

#include <glib.h>
#include <libxklavier/xklavier.h>
#include <libappindicator/app-indicator.h>

#include "global.h"
#include "about.h"
#include "settings.h"

static GActionEntry const menu_entries[] = {
  { .name = "settings", .activate = show_settings },
  { .name = "about", .activate = show_about },
  { .name = "quit", .activate = main_quit },
};

void
update_icon (XklEngine * engine, gint group);

AppIndicator *
create_indicator ();
