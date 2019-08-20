#include "month_line_chart_widget.h"
#include "ui_month_line_chart_widget.h"
#include "money_data.h"

month_line_chart_widget::month_line_chart_widget(QWidget* parent) :
    item_widget(parent),
    ui(new Ui::month_line_chart_widget())
{
    ui->setupUi(this);
}

month_line_chart_widget::~month_line_chart_widget()
{
}

void month_line_chart_widget::update()
{
}
