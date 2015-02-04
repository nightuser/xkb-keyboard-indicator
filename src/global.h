#pragma once

#include <glib.h>
#include <libxklavier/xklavier.h>
#include <libappindicator/app-indicator.h>

AppIndicator * indicator;
XklEngine * engine;
XklConfigRec * config_rec;
GSettings * settings;
gulong xkb_state_changed_handler;
gulong xkb_config_changed_handler;
