#include <iostream>
#include <gtkmm.h>
#include "application.h"

Glib::RefPtr<App> App::create()
{
    return Glib::make_refptr_for_instance<App>(new App());
}

App::App()
: Gtk::Application::Application()
{
    g_debug("App::App() entering...");
    Glib::set_application_name("CardMatch");
}

void App::on_activate()
{
    g_debug("App::on_activate() entering...");
    auto app_window = create_app_window();
    app_window->present();
}

void App::on_hide_window(AppWindow* app_window)
{
    g_debug("App::on_hide_window() entering...");
    delete app_window;
}

Gtk::Window* App::create_app_window()
{
    g_debug("App::create_app_window() entering...");
    auto app_window = new AppWindow();
    add_window(*app_window);
    app_window->signal_hide().connect(sigc::bind(
                    sigc::mem_fun(*this, &App::on_hide_window), app_window));
    return app_window;
}
