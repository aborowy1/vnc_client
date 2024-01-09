#ifndef VNC_H
#define VNC_H

#include <gtk/gtk.h>
#include <vncdisplay.h>
#include <vncutil.h>
#include <glib.h>

extern GtkWidget *vnc;

void vnc_init();
void vnc_connect(GtkWidget *button, GString *ip_address);
void vnc_disconnect();

#endif



