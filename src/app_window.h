#ifndef APP_WINDOW_H
#define APP_WINDOW_H

#include <gtkmm.h>
#include "details_list.h"

#define VERT Gtk::Orientation::VERTICAL
#define HORZ Gtk::Orientation::HORIZONTAL
#define CAPTURE_IDLE_IMG_PATH "/home/francesco/Dev/CardMatch/res/capture-idle.png"
#define BLUEPRINT_IDLE_IMG_PATH "/home/francesco/Dev/CardMatch/res/blueprint-idle.png"

class AppWindow : public Gtk::ApplicationWindow
{
  class Builder
  {
    public:
      explicit Builder(AppWindow &window);
      void build();

    protected:
      AppWindow &w;
  };

  public:
    AppWindow();
    static AppWindow* create();

  protected:
    Gtk::Label blueprint_title;
    Gtk::Label details_title;
    Gtk::Label capture_title;
    Gtk::Statusbar statusbar;
    Gtk::Image capture_image;
    Gtk::Image blueprint_image;
    DetailsList details_list;

    void build_ui();
    void on_clickme_button_clicked();
};

#endif

