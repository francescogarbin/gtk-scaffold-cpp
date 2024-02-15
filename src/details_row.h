#ifndef DETAILS_ROW_H
#define DETAILS_ROW_H

#include <gtkmm.h>

class DetailsRow : public Gtk::ListBoxRow
{
  public:
    DetailsRow();
    DetailsRow(const Glib::ustring& field, const Glib::ustring& value);
    Glib::ustring get_field_text();
    Glib::ustring  get_value_text();
    void set_field_text(const Glib::ustring& text);
    void set_value_text(const Glib::ustring& value);

  protected:
    Gtk::Label field;
    Gtk::Label value;
    void build_ui();
};

#endif
