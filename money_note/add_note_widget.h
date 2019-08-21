#pragma once
#include "item_widget.h"

namespace Ui {
    class add_note_widget;
} // namespace Ui

class add_note_widget :public item_widget
{
    Q_OBJECT
public:
    add_note_widget(QWidget* parent = 0);
    ~add_note_widget();

    void update();

private:
    void update_date();
    void update_type_combox();
    void update_day_table();

private slots:
    void slot_date_changed();
    void slot_add_note_bt_clicked();
    void slot_add_type_bt_clicked();
private:
    Ui::add_note_widget* ui;
};