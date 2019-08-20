#include "main_dlg.h"
#include "widget_list.h"
#include "money_note_widget.h"

main_dlg::main_dlg(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    setWindowState(Qt::WindowMaximized);
    widgets.set_parent_param(this,ui.verticalLayout_main);
    widgets.push_widget(new money_note_widget());
}

void main_dlg::slot_home_bt_clicked()
{
    widgets.go_home();
}

void main_dlg::slot_upper_bt_clicked()
{
    widgets.go_upper();
}
