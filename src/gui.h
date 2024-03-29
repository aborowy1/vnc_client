#ifndef GUI_H
#define GUI_H

#include <gtk/gtk.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

extern GtkWidget *viewVnc;
extern GtkWidget *connectBtn;
extern GtkWidget *unlockBtn;
extern GtkWidget *cancelBtn;
extern GtkWidget *window;

extern GString *ip_address;

void gui_init();
void gui_start();
void gui_stop();
void gui_show_connecting();
void gui_show_ip_entry();
void gui_show_password_entry();
void gui_show_vnc();


#endif
