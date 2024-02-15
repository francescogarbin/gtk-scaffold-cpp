#include <cstdio>
#include <iostream>
#include <glib.h>
#include <gtkmm.h>
#include "application.h"

using namespace std;

int main()
{
    g_debug("cardmatch application starting...");
	auto app = App::create();
	const auto status = app->run();
	return status;
}
