#include <gtk/gtk.h>
#include "gui.h"
#include "vnc.h"

int main(int argc, char *argv[]){
  gtk_init(&argc, &argv);

  gui_init();
  vnc_init();

  gtk_box_pack_start(GTK_BOX(viewVnc), GTK_WIDGET(vnc), TRUE, TRUE, 0);




  gui_start();
  return 0;
}
