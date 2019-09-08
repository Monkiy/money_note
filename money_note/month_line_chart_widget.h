#pragma once
#include "item_widget.h"

namespace Ui {
    class month_line_chart_widget;
} // namespace Ui

namespace QtCharts
{
    class QChartView;
}

class month_line_chart_widget :public item_widget
{
    Q_OBJECT
public:
    month_line_chart_widget(QWidget* parent = 0);
    ~month_line_chart_widget();

    void update();
private:
    void init_charts();
    void update_month_table();
    void update_month_charts();

private slots:
private:
    Ui::month_line_chart_widget* ui;
    QtCharts::QChartView* __charts;
};