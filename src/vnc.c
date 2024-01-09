#include "vnc.h"

#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

GtkWidget *vnc;
GtkWidget *display;

gboolean connected = FALSE;

void vnc_disconnect(){
  if(connected != FALSE){
    g_print("disconnecting\n");
    vnc_display_close(VNC_DISPLAY(vnc));
  }
  connected = FALSE;
}

static void vnc_initialized(GtkWidget *vncdisplay, GtkWidget *window){
  g_print("vnc_initialized\n");
}


static void vnc_connected(GtkWidget *vncdisplay G_GNUC_UNUSED){
  g_print("vnc_connected\n");
  connected = TRUE;
}

static void vnc_auth_failure(GtkWidget *vncdisplay G_GNUC_UNUSED){
  g_print("vnc_auth_failure\n");
}

static void vnc_auth_credential(GtkWidget *vncdisplay, GValueArray *credList){
  g_print("vnc_auth_credential\n");

  const char **data = g_new0(const char *, credList->n_values);
  for (int i =0; i<credList->n_values;i++){
    GValue *cred = g_value_array_get_nth(credList, i);
    switch (g_value_get_enum(cred)){
      case VNC_DISPLAY_CREDENTIAL_USERNAME:
      case VNC_DISPLAY_CREDENTIAL_PASSWORD:
        data[i] = "solaris";
        break;
      default:
        continue;
    }
  }

  for (int i = 0; i < credList->n_values; i++){
    GValue *cred = g_value_array_get_nth(credList, i);
    if(data[i]){
      vnc_display_set_credential(VNC_DISPLAY(vncdisplay), g_value_get_enum(cred), data[i]);
    }
  }
}


void vnc_connect(GtkWidget *button, GString *ip_address){
  g_print("connecting\n %s\n", ip_address->str);
  gtk_widget_realize(vnc);
  vnc_display_open_host(VNC_DISPLAY(vnc), ip_address->str,"5901");
  vnc_display_set_keyboard_grab(VNC_DISPLAY(vnc), TRUE);
  vnc_display_set_pointer_grab(VNC_DISPLAY(vnc), TRUE);
  vnc_display_set_pointer_local(VNC_DISPLAY(vnc), TRUE);
  vnc_display_set_allow_resize(VNC_DISPLAY(vnc), TRUE);
  vnc_display_set_lossy_encoding(VNC_DISPLAY(vnc), TRUE);
}


void vnc_init(){
  vnc = vnc_display_new();
  g_signal_connect(vnc, "vnc-connected", G_CALLBACK(vnc_connected),NULL);
  g_signal_connect(vnc, "vnc-auth-credential", G_CALLBACK(vnc_auth_credential),NULL);
  g_signal_connect(vnc, "vnc-initialized", G_CALLBACK(vnc_initialized), NULL);
  g_signal_connect(vnc, "vnc-disconnected", G_CALLBACK(vnc_disconnect),NULL);
  g_signal_connect(vnc, "vnc-auth-failure", G_CALLBACK(vnc_auth_failure),NULL);
}

