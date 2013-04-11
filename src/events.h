#ifndef EVENTS
#define EVENTS

#include <gtk/gtk.h>

class Events {
	public:
		Events() { };
		~Events() { };

		void handleKeyEvent(guint keyval);

	private:
};

#endif
