#pragma once
#include "item_widget.h"

namespace Ui {
    class add_note_widget;
} // namespace Ui

class QTableWidgetItem;
class add_note_widget :public item_widget
{
    Q_OBJECT
public:
    add_note_widget(QWidget* parent = 0);
    ~add_note_widget();

    void update();
protected:
    void timerEvent(QTimerEvent *event);
    bool eventFilter(QObject *target, QEvent *event);

private:
    void update_date();
    void update_type_combox();
    void update_day_table();

private slots:
    void slot_date_changed();
    void slot_add_note_bt_clicked();
    void slot_add_type_bt_clicked();
    void on_bt_remove_note_clicked();
    void slot_tableWidget_day_itemChanged(QTableWidgetItem *item);
private:
    Ui::add_note_widget* ui;
    int m_valueSelectAllTimer;//金额输入框获得焦点全选定时器
    int m_noteSelectAllTimer;//消费记录输入框获得焦点全选定时器
};