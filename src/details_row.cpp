#include "details_row.h"

DetailsRow::DetailsRow()
: ListBoxRow()
{
    this->field = Gtk::Label("field_label");
    this->value = Gtk::Label("value_label");
    build_ui();
}

DetailsRow::DetailsRow(const Glib::ustring& field, const Glib::ustring& value)
: ListBoxRow()
{
    this->field = Gtk::Label(field);
    this->value = Gtk::Label(value);
    build_ui();
}

Glib::ustring DetailsRow::get_field_text()
{
    Glib::ustring ret = this->field.get_text();
    return ret;
}

Glib::ustring DetailsRow::get_value_text()
{
    Glib::ustring ret = this->value.get_text();
    return ret;
}

void DetailsRow::set_field_text(const Glib::ustring& text)
{
    this->field.set_text(text);
}

void DetailsRow::set_value_text(const Glib::ustring& text)
{
    this->value.set_text(text);
}

void DetailsRow::build_ui()
{
    auto box = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::VERTICAL);
    box->append(this->field);
    box->append(this->value);
    set_child(*box);
}

