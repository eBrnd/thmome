#ifndef WINDOW
#define WINDOW

#include <gtk/gtk.h>

class Window {
	public:
		Window();
		~Window() { };

	private:
		void buildWindow();
		void connectInput();

		GtkWidget* window;
};

#endif
