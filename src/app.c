#include <gtk/gtk.h>
#include "gui.h"
#include "vnc.h"

int main(int argc, char *argv[]){
  gtk_init(&argc, &argv);

  gui_init();
  vnc_init();

  gtk_box_pack_start(GTK_BOX(viewVnc), GTK_WIDGET(vnc), TRUE, TRUE, 0);

  g_signal_connect(connectBtn, "clicked", G_CALLBACK(gui_show_ip_entry), NULL);
  g_signal_connect(unlockBtn, "clicked", G_CALLBACK(vnc_connect), ip_address);
  g_signal_connect(cancelBtn, "clicked", G_CALLBACK(vnc_disconnect), NULL);
  g_signal_connect(window, "destroy", G_CALLBACK(vnc_disconnect), NULL);
  g_signal_connect(vnc, "vnc-initialized", G_CALLBACK(gui_show_vnc), NULL);
  g_signal_connect(vnc, "vnc-auth-failure", G_CALLBACK(gui_show_ip_entry),NULL);
  g_signal_connect(vnc, "vnc-error", G_CALLBACK(gui_show_ip_entry),NULL);

  gui_start();
  return 0;
}
