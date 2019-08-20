#include "widget_list.h"

item_widget_list & item_widget_list::get_instance()
{
    static item_widget_list list;
    return list;
}

void item_widget_list::push_widget(item_widget * w)
{
    if (__widget_iter != __widget_list.end())
        (*__widget_iter)->hide();
    if (__main_widget)
        w->setParent(__main_widget);
    if (__main_layout)
        __main_layout->addWidget(w);
    __widget_iter = __widget_list.insert(__widget_list.end(), w);
    (*__widget_iter)->show();
    (*__widget_iter)->update();
}

void item_widget_list::go_home()
{
    if (1 >= __widget_list.size())
        return;
    auto iter = __widget_list.begin();
    __widget_iter = iter;
    (*__widget_iter)->show();
    (*__widget_iter)->update();

    ++iter;
    while (iter != __widget_list.end())
    {
        (*iter)->deleteLater();
        iter = __widget_list.erase(iter);
    }
}

void item_widget_list::go_upper()
{
    if (1 >= __widget_list.size())
        return;
    (*__widget_iter)->deleteLater();
    __widget_iter = __widget_list.erase(__widget_iter);
    --__widget_iter;
    (*__widget_iter)->show();
    (*__widget_iter)->update();
}

item_widget_list::item_widget_list() :
    __widget_iter(__widget_list.begin()),
    __main_widget(0),
    __main_layout(0)
{
}
