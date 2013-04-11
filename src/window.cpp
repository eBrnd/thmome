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

	GtkWidget* button = gtk_button_new_with_label("Push me!");
	g_signal_connect(G_OBJECT(button), "button_press_event", G_CALLBACK(button_callback), NULL);

	gtk_container_add(GTK_CONTAINER(window), button);

	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

	gtk_widget_show_all(window);
}
