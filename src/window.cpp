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
	gtk_box_pack_start(GTK_BOX(binary_status_box), dual_rb, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(binary_status_box), twok_rb, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(binary_status_box), float_rb, TRUE, TRUE, 0);

	gtk_box_pack_start(GTK_BOX(main_box), binary_status_box, FALSE, TRUE, 0);

	// binary display unit
	GtkWidget* binary_display_lb = gtk_label_new("1010 1010 1010 1010 1010 1010 1010 1010");
	gtk_box_pack_start(GTK_BOX(main_box), binary_display_lb, FALSE, TRUE, 0);

	GtkWidget* hexadecimal_display_lb = gtk_label_new("0xAFFEAFFE");
	GtkWidget* octal_display_lb = gtk_label_new("0o24 242 424 242");

	GtkWidget* hex_oct_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_pack_start(GTK_BOX(hex_oct_box), hexadecimal_display_lb, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(hex_oct_box), octal_display_lb, TRUE, TRUE, 0);
	
	gtk_box_pack_start(GTK_BOX(main_box), hex_oct_box, FALSE, TRUE, 0);

  GtkWidget* bin_display_sep = gtk_separator_new(GTK_ORIENTATION_HORIZONTAL);
	gtk_box_pack_start(GTK_BOX(main_box), bin_display_sep, FALSE, TRUE, 5);

	gtk_container_add(GTK_CONTAINER(window), main_box);
	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);


	// main display
	GtkWidget* main_display_lb = gtk_label_new("1234567890");

	gtk_box_pack_start(GTK_BOX(main_box), main_display_lb, FALSE, TRUE, 0);


  GtkWidget* display_input_sep = gtk_separator_new(GTK_ORIENTATION_HORIZONTAL);
	gtk_box_pack_start(GTK_BOX(main_box), display_input_sep, FALSE, TRUE, 5);


	// input area
	GtkWidget* input_buffer_lb = gtk_label_new("9876543210");
	gtk_box_pack_start(GTK_BOX(main_box), input_buffer_lb, FALSE, TRUE, 0);

	GtkWidget* input_mode_lb = gtk_label_new("Input mode:");

	GtkWidget* dec_in_rb = gtk_radio_button_new_with_label(NULL, "Decimal");
	GtkWidget* hex_in_rb = gtk_radio_button_new_with_label(gtk_radio_button_get_group(GTK_RADIO_BUTTON(dec_in_rb)), "Hex");
	GtkWidget* dual_in_rb = gtk_radio_button_new_with_label(gtk_radio_button_get_group(GTK_RADIO_BUTTON(dec_in_rb)), "Dual");

	GtkWidget* input_mode_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
	gtk_box_pack_start(GTK_BOX(input_mode_box), input_mode_lb, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(input_mode_box), dec_in_rb, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(input_mode_box), hex_in_rb, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(input_mode_box), dual_in_rb, TRUE, TRUE, 0);

	gtk_box_pack_start(GTK_BOX(main_box), input_mode_box, FALSE, TRUE, 0);


	// status and command bar
	GtkWidget* status_bar_lb = gtk_label_new("thmome v0.1 ready!");
	gtk_box_pack_end(GTK_BOX(main_box), status_bar_lb, FALSE, TRUE, 0);


	// show all the widgets!
	gtk_widget_show_all(window);
}
