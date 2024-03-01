#ifndef VNC_H
#define VNC_H

#include <gtk/gtk.h>
#include <vncdisplay.h>
#include <vncutil.h>
#include <glib.h>

#include "gui.h"

extern GtkWidget *vnc;
extern gboolean password_is_needed;
extern GString *password;
extern gboolean connected;

void vnc_init();
void vnc_connect(GtkWidget *button);
void vnc_disconnect();

#endif



