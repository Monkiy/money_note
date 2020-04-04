#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_main_dlg.h"

class QAction;
class main_dlg : public QMainWindow
{
    Q_OBJECT

public:
    main_dlg(QWidget *parent = Q_NULLPTR);
private slots:
    void on_act_home_triggered();
    void on_act_upper_triggered();
private:
    Ui::main_dlgClass ui;
};
