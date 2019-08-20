#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_main_dlg.h"

class main_dlg : public QMainWindow
{
    Q_OBJECT

public:
    main_dlg(QWidget *parent = Q_NULLPTR);
private slots:
    void slot_home_bt_clicked();
    void slot_upper_bt_clicked();
private:
    Ui::main_dlgClass ui;
};
