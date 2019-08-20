#pragma once
#include "item_widget.h"

namespace Ui {
    class month_pie_chart_widget;
} // namespace Ui

class month_pie_chart_widget :public item_widget
{
    Q_OBJECT
public:
    month_pie_chart_widget(QWidget* parent = 0);
    ~month_pie_chart_widget();

    void update();

private slots:
private:
    Ui::month_pie_chart_widget* ui;
};