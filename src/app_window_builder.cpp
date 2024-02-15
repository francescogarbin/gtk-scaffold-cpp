#include <vector>
#include "details_row.h"
#include "app_window.h"

AppWindow::Builder::Builder(AppWindow &window)
: w(window)
{
}

void AppWindow::Builder::build()
{
    w.capture_title = Gtk::Label("capture_title");
    w.blueprint_title = Gtk::Label("blueprint_title");
    w.details_title = Gtk::Label("details_title");
    w.statusbar = Gtk::Statusbar();
    w.statusbar.push("statusbar");

    auto blueprint_box = Gtk::make_managed<Gtk::Box>(VERT);
    blueprint_box->set_expand(true);
    blueprint_box->append(w.blueprint_title);

    auto details_box = Gtk::make_managed<Gtk::Box>(VERT);
    details_box->set_expand(true);
    details_box->append(w.details_title);

    auto blueprint_paned = Gtk::make_managed<Gtk::Paned>(VERT);
    blueprint_paned->set_expand(true);
    blueprint_paned->set_wide_handle(true);
    blueprint_paned->set_start_child(*blueprint_box);
    blueprint_paned->set_end_child(*details_box);

    auto capture_box = Gtk::make_managed<Gtk::Box>(VERT);
    capture_box->set_expand(true);
    capture_box->append(w.capture_title);

    auto content_paned = Gtk::make_managed<Gtk::Paned>(HORZ);
    content_paned->set_expand(true);
    content_paned->set_wide_handle(true);
    content_paned->set_start_child(*capture_box);
    content_paned->set_end_child(*blueprint_paned);

    auto content_box = Gtk::make_managed<Gtk::Box>(VERT);
    content_box->set_expand(true);
    content_box->append(*content_paned);
    content_box->append(w.statusbar);

    auto clickme_button = Gtk::make_managed<Gtk::Button>("Click Me");
    clickme_button->signal_clicked().connect(
                sigc::mem_fun(w, &AppWindow::on_clickme_button_clicked));
    capture_box->append(*clickme_button);

    w.capture_image = Gtk::Image(CAPTURE_IDLE_IMG_PATH);
    w.capture_image.set_expand(true);
    capture_box->append(w.capture_image);

    auto pixbuf = Gdk::Pixbuf::create_from_file(BLUEPRINT_IDLE_IMG_PATH);
    w.blueprint_image = Gtk::Image(pixbuf);
    w.blueprint_image.set_expand(true);
    auto aspect_frame = Gtk::make_managed<Gtk::AspectFrame>();
    aspect_frame->set_child(w.blueprint_image);
    blueprint_box->append(*aspect_frame);

    w.details_list = DetailsList();
    w.details_list.set_expand();
    details_box->append(w.details_list);

    std::vector<Glib::ustring> fields = std::vector<Glib::ustring>();
    fields.push_back("field 1");
    fields.push_back("field 2");
    fields.push_back("field 3");

    std::vector<Glib::ustring> values = std::vector<Glib::ustring>();
    values.push_back("value 1");
    values.push_back("value 2");
    values.push_back("value 3");

    for (unsigned int i; i < fields.size() ; i++)
    {
        auto row = Gtk::make_managed<DetailsRow>();
        row->set_field_text(fields[i]);
        row->set_value_text(values[i]);
        w.details_list.append(*row);
    }

    w.set_child(*content_box);
}
