#pragma once

#include <glib.h>
#include <libxklavier/xklavier.h>
#include <libappindicator/app-indicator.h>

#include "about.h"
#include "settings.h"

static GActionEntry const menu_entries[] = {
  { "settings", show_settings },
  { "about", show_about },
  { "quit", gtk_main_quit },
};

void
update_icon (XklEngine * engine, gint group);

AppIndicator *
create_indicator ();
