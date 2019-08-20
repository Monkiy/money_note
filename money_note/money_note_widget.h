#pragma once
#include "item_widget.h"

namespace Ui {
    class money_note_widget;
} // namespace Ui

class money_note_widget :public item_widget
{
    Q_OBJECT
public:
    money_note_widget(QWidget* parent = 0);
    ~money_note_widget();

    void update();
private:
    void update_year_table();
    void update_month_table();
    void update_day_table();

private slots:
    void slot_year_line_chart_bt_clicked();
    void slot_month_line_chart_bt_clicked();
    void slot_year_pie_chart_bt_clicked();
    void slot_month_pie_chart_bt_clicked();
    void slot_add_note_bt_clicked();
private:
    Ui::money_note_widget* ui;
};