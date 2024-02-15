#ifndef APPLICATION_H
#define APPLICATION_H

#include <gtkmm.h>
#include "app_window.h"

#define APPLICATION_TAG "org.francescogarbin.gtkscaffoldcpp"

class App : public Gtk::Application
{
  public:
    static Glib::RefPtr<App> create();

  protected:
    App();
    void on_activate() override;
    void on_hide_window(AppWindow* app_window);
    Gtk::Window* create_app_window();
};

#endif

