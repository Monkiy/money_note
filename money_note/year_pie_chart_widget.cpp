#include "year_pie_chart_widget.h"
#include "ui_year_pie_chart_widget.h"
#include "money_data.h"

year_pie_chart_widget::year_pie_chart_widget(QWidget* parent) :
    item_widget(parent),
    ui(new Ui::year_pie_chart_widget())
{
    ui->setupUi(this);
}

year_pie_chart_widget::~year_pie_chart_widget()
{
}

void year_pie_chart_widget::update()
{
}
