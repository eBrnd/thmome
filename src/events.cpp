#include "events.h"

#include <iostream>
#include <gdk/gdk.h>

Events::Events() {
	keyCommandInitialize();
}

void Events::handleKeyEvent(guint keyval) {
	keyCommandExecute(gdk_keyval_name(keyval));
}

void Events::keyCommandExecute(gchar* keyname) {
	std::string adsf(keyname);
	std::map<std::string, std::function<void ()> >::iterator action = actions.find(keyname);
	if(action != actions.end())
		(action->second)();
}

void Events::keyCommandInitialize() {
	actions["a"] = [](){ std::cout << "a" << std::endl; };
}
