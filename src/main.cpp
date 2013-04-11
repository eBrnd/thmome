#include <iostream>
#include <gtk/gtk.h>

#include "core.h"

int main(int argc, char** args)
{
	gtk_init(&argc, &args);
	Core::inst();
	gtk_main();
	return 0;
}
