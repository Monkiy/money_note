#pragma once
#include "item_widget.h"

namespace Ui {
    class year_pie_chart_widget;
} // namespace Ui

namespace QtCharts
{
    class QChartView;
}

class year_pie_chart_widget :public item_widget
{
    Q_OBJECT
public:
    year_pie_chart_widget(QWidget* parent = 0);
    ~year_pie_chart_widget();

    void update();
private:
    void init_charts();
    void update_year_table();
    void update_year_charts();

private slots:
private:
    Ui::year_pie_chart_widget* ui;
    QtCharts::QChartView* __charts;
};