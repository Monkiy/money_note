#pragma once
#include "item_widget.h"

namespace Ui {
    class year_line_chart_widget;
} // namespace Ui

class year_line_chart_widget :public item_widget
{
    Q_OBJECT
public:
    year_line_chart_widget(QWidget* parent = 0);
    ~year_line_chart_widget();

    void update();

private slots:
private:
    Ui::year_line_chart_widget* ui;
};