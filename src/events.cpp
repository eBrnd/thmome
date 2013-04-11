#include "events.h"

#include <iostream>
#include <gdk/gdk.h>

void Events::handleKeyEvent(guint keyval) {
	std::cout << "Handle Event! Key pressed: " << gdk_keyval_name(keyval) << std::endl;
}
