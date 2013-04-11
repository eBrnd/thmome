#ifndef CORE
#define CORE

#include "window.h"
#include "events.h"

class Core {
	public:
		Events* getEventHandler();

		static Core* inst();

	private:
		Core();
		~Core();
		static Core* instance;

		Window* window;
		Events* eventHandler;
};

#endif
