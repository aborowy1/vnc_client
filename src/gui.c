#include "gui.h"

GtkBuilder *builder;
GtkWidget *window;

GtkWidget *ipEntry1;
GtkWidget *ipEntry2;
GtkWidget *ipEntry3;
GtkWidget *ipEntry4;
GtkWidget *passwordEntry;

GtkStack *mainStack;
GtkStack *connectingStack;

GtkWidget *connectBtn;
GtkWidget *unlockBtn;
GtkWidget *cancelBtn;

GString *ip_address;
GString *password;

GtkWidget *viewVnc;

//update ip_address value
void gui_get_ip_address(){
  g_string_printf(ip_address, "%s.%s.%s.%s",    gtk_entry_get_text(GTK_ENTRY(ipEntry1)),
                                                gtk_entry_get_text(GTK_ENTRY(ipEntry2)),
                                                gtk_entry_get_text(GTK_ENTRY(ipEntry3)),
                                                gtk_entry_get_text(GTK_ENTRY(ipEntry4)));
}

//check if provided ip address is correct - correct if not
void gui_ip_check(GtkWidget *ipEntryX){
  GString *input;
  input = g_string_new(gtk_entry_get_text(GTK_ENTRY(ipEntryX)));

  for(int i =0; i<= input->len; i++){
    if(!isdigit(input->str[i])){
      input->str[i] = '\0';
      gtk_entry_set_text(GTK_ENTRY(ipEntryX), input->str);
      gtk_editable_set_position(GTK_EDITABLE(ipEntryX), -1);
    }
  }

  if(atoi(input->str) > 255){
    input->str[input->len-1] = '\0';
    gtk_entry_set_text(GTK_ENTRY(ipEntryX),input->str);
  }

  if(input->len >=2 && input->str[0] == '0'){
    input->str[1] = '\0';
    gtk_entry_set_text(GTK_ENTRY(ipEntryX),input->str);
  }

  gui_get_ip_address();

  if (  gtk_entry_get_text_length(GTK_ENTRY(ipEntry1))  != 0 &&
        gtk_entry_get_text_length(GTK_ENTRY(ipEntry2))  != 0 &&
        gtk_entry_get_text_length(GTK_ENTRY(ipEntry3))  != 0 &&
        gtk_entry_get_text_length(GTK_ENTRY(ipEntry4))  != 0){
    gtk_widget_set_sensitive(GTK_WIDGET(connectBtn), TRUE);
  }
  else{
    gtk_widget_set_sensitive(GTK_WIDGET(connectBtn), FALSE);
  }
}

//show ip entry view
void gui_show_ip_entry(){
  gtk_stack_set_visible_child(GTK_STACK(gtk_builder_get_object(builder, "mainStack")), GTK_WIDGET(gtk_builder_get_object(builder, "viewPrepareToConnect")));
  gtk_stack_set_visible_child(GTK_STACK(gtk_builder_get_object(builder, "connectingStack")), GTK_WIDGET(gtk_builder_get_object(builder, "ip")));
}

//show password entry view
void gui_show_password_entry(){
  gtk_stack_set_visible_child(GTK_STACK(gtk_builder_get_object(builder, "mainStack")), GTK_WIDGET(gtk_builder_get_object(builder, "viewPrepareToConnect")));
  gtk_stack_set_visible_child(GTK_STACK(gtk_builder_get_object(builder, "connectingStack")), GTK_WIDGET(gtk_builder_get_object(builder, "password")));
}

//show connecting view
void gui_show_connecting(){
  gtk_stack_set_visible_child(GTK_STACK(gtk_builder_get_object(builder, "mainStack")), GTK_WIDGET(gtk_builder_get_object(builder, "viewPrepareToConnect")));
  gtk_stack_set_visible_child(GTK_STACK(gtk_builder_get_object(builder, "connectingStack")), GTK_WIDGET(gtk_builder_get_object(builder, "connecting")));
}

//show vnc workspace
void gui_show_vnc(){
  gtk_stack_set_visible_child(GTK_STACK(gtk_builder_get_object(builder, "mainStack")), GTK_WIDGET(gtk_builder_get_object(builder, "viewVnc")));
}

//gui init
void gui_init(){
  ip_address = g_string_new("");
  password = g_string_new("");

  builder = gtk_builder_new_from_file("./ui.glade");

  mainStack = GTK_STACK(gtk_builder_get_object(builder, "mainStack"));
  connectingStack = GTK_STACK(gtk_builder_get_object(builder, "connectingStack"));

  viewVnc = GTK_WIDGET(gtk_builder_get_object(builder, "viewVnc"));

  window = GTK_WIDGET(gtk_builder_get_object(builder, "mainWindow"));
  g_signal_connect(window, "destroy", G_CALLBACK(gui_stop), NULL);

  ipEntry1 = GTK_WIDGET(gtk_builder_get_object(builder, "ipEntry1"));
  gtk_widget_modify_font(ipEntry1, pango_font_description_from_string("Ubuntu Medium 20"));
  gtk_entry_set_max_length(GTK_ENTRY(ipEntry1), 3);
  g_signal_connect(ipEntry1, "key-release-event", G_CALLBACK(gui_ip_check), ipEntry1);

  ipEntry2 = GTK_WIDGET(gtk_builder_get_object(builder, "ipEntry2"));
  gtk_widget_modify_font(ipEntry2, pango_font_description_from_string("Ubuntu Medium 20"));
  gtk_entry_set_max_length(GTK_ENTRY(ipEntry2), 3);
  g_signal_connect(ipEntry2, "key-release-event", G_CALLBACK(gui_ip_check), ipEntry2);

  ipEntry3 = GTK_WIDGET(gtk_builder_get_object(builder, "ipEntry3"));
  gtk_widget_modify_font(ipEntry3, pango_font_description_from_string("Ubuntu Medium 20"));
  gtk_entry_set_max_length(GTK_ENTRY(ipEntry3), 3);
  g_signal_connect(ipEntry3, "key-release-event", G_CALLBACK(gui_ip_check), ipEntry3);

  ipEntry4 = GTK_WIDGET(gtk_builder_get_object(builder, "ipEntry4"));
  gtk_widget_modify_font(ipEntry4, pango_font_description_from_string("Ubuntu Medium 20"));
  gtk_entry_set_max_length(GTK_ENTRY(ipEntry4), 3);
  g_signal_connect(ipEntry4, "key-release-event", G_CALLBACK(gui_ip_check), ipEntry4);

  connectBtn = GTK_WIDGET(gtk_builder_get_object(builder, "connectBtn"));
  gtk_widget_set_sensitive(GTK_WIDGET(connectBtn), FALSE);

  passwordEntry = GTK_WIDGET(gtk_builder_get_object(builder, "passwordEntry"));
  gtk_widget_modify_font(passwordEntry, pango_font_description_from_string("Ubuntu Medium 20"));

  unlockBtn = GTK_WIDGET(gtk_builder_get_object(builder, "unlockBtn"));
  g_signal_connect(unlockBtn, "clicked", G_CALLBACK(gui_show_connecting), NULL);

  cancelBtn = GTK_WIDGET(gtk_builder_get_object(builder, "cancelBtn"));
  g_signal_connect(cancelBtn, "clicked", G_CALLBACK(gui_show_ip_entry), NULL);
}

void gui_start(){
  gtk_widget_show_all(window);
  gtk_main();
}

void gui_stop(){
  gtk_main_quit();
}
