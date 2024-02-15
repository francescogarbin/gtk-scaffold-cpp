#include "app_window.h"

AppWindow::AppWindow()
: Gtk::ApplicationWindow()
{
  build_ui();
}

void AppWindow::build_ui()
{
    g_debug("AppWindow::build_ui() entering...");
    set_title("CardMatch");
    set_default_size(800, 800);
    AppWindow::Builder builder(*this);
    builder.build();
}

void AppWindow::on_clickme_button_clicked()
{
    g_debug("AppWindow::on_clickme_button_clicked()");
}

