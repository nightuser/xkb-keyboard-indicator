#pragma once

#include <glib.h>
#include <gtk/gtk.h>
#include <libxklavier/xklavier.h>

void
show_settings (GSimpleAction * action,
               GVariant * parameter,
               gpointer user_data);
