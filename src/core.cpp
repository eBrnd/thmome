#include "core.h"

Core* Core::instance = NULL;

Core* Core::inst() {
	if(!instance)
		instance = new Core();
	
	return instance;
}

Core::Core() : eventHandler(new Events()), window(new Window()) { };

Core::~Core() {
	delete window;
	delete eventHandler;
}

Events* Core::getEventHandler() {
	return eventHandler;
}
