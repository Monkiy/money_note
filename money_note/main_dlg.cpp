#include "main_dlg.h"
#include "widget_list.h"
#include "money_note_widget.h"

main_dlg::main_dlg(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    ui.toolButton_home->setDefaultAction(ui.act_home);
    ui.toolButton_upper->setDefaultAction(ui.act_upper);
    setWindowState(Qt::WindowMaximized);
    widgets.set_parent_param(this,ui.verticalLayout_main);
    widgets.push_widget(new money_note_widget());
}

void main_dlg::on_act_home_triggered()
{
    widgets.go_home();
}

void main_dlg::on_act_upper_triggered()
{
    widgets.go_upper();
}
