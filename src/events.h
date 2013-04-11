#ifndef EVENTS
#define EVENTS

#include <gtk/gtk.h>
#include <map>
#include <string>
#include <functional>

class Events {
	public:
		Events();
		~Events() { };

		void handleKeyEvent(guint keyval);
		void keyCommandExecute(gchar* keyname);
		void keyCommandInitialize();

	private:
		std::map<std::string, std::function<void ()> > actions;
};

#endif
