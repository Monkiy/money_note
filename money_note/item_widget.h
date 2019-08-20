#pragma once
#include <QWidget>

class item_widget:public QWidget
{
public:
    item_widget(QWidget* parent = 0):
        QWidget(parent)
    {}
    virtual ~item_widget(){}
    virtual void update() = 0;
};