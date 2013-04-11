#include "window.h"

#include <iostream>

#include "events.h"
#include "core.h"

// TODO find out if you can use members of anything for this...
void button_callback(GtkWidget* widget, GdkEventButton* event, gpointer callback_data)
{
	Core::inst()->getEventHandler()->handleEvent();
}


Window::Window() {
	init();
}

void Window::init() {
	GtkWidget* window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

	GtkWidget* main_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);

	// binary display status indicators / controllers
	GtkWidget* binary_lb = gtk_label_new("Binary mode:");

	GtkWidget* dual_rb = gtk_radio_button_new_with_label(NULL, "dual");
	GtkWidget* twok_rb = gtk_radio_button_new_with_label(gtk_radio_button_get_group(GTK_RADIO_BUTTON(dual_rb)), "2k");
	GtkWidget* float_rb = gtk_radio_button_new_with_label(gtk_radio_button_get_group(GTK_RADIO_BUTTON(dual_rb)), "float");

	GtkWidget* binary_status_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_pack_start(GTK_BOX(binary_status_box), binary_lb, TRUE, TRUE, 0);
	gtk_box_pack_end(GTK_BOX(binary_status_box), twok_rb, TRUE, TRUE, 0);
	gtk_box_pack_end(GTK_BOX(binary_status_box), float_rb, TRUE, TRUE, 0);
	gtk_box_pack_end(GTK_BOX(binary_status_box), dual_rb, TRUE, TRUE, 0);

	gtk_box_pack_start(GTK_BOX(main_box), binary_status_box, FALSE, TRUE, 0);

	gtk_container_add(GTK_CONTAINER(window), main_box);
	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

	gtk_widget_show_all(window);
}
