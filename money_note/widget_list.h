#pragma once
#include <list>
#include <QWidget>
#include <QVBoxLayout>
#include "item_widget.h"

using std::list;

#define widgets item_widget_list::get_instance()

class item_widget_list
{
public:
    static item_widget_list& get_instance();
    inline void set_parent_param(QWidget* w, QVBoxLayout* l)
    {
        __main_widget = w; 
        __main_layout = l;
    }
    void push_widget(item_widget* w);
    void go_home();
    void go_upper();
private:
    item_widget_list();
    item_widget_list(const item_widget_list&);
private:
    list<item_widget*> __widget_list;
    list<item_widget*>::iterator __widget_iter;
    QWidget* __main_widget;
    QVBoxLayout* __main_layout;
};