#include "month_pie_chart_widget.h"
#include "ui_month_pie_chart_widget.h"
#include "money_data.h"
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>

using namespace QtCharts;
#ifdef _DEBUG
#pragma comment(lib,"Qt5Chartsd.lib")
#else
#pragma comment(lib,"Qt5Charts.lib")
#endif

month_pie_chart_widget::month_pie_chart_widget(QWidget* parent) :
    item_widget(parent),
    ui(new Ui::month_pie_chart_widget())
{
    ui->setupUi(this);
    init_charts();
    ui->tableWidget_month_class->verticalHeader()->hide();
    ui->tableWidget_month_class->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

month_pie_chart_widget::~month_pie_chart_widget()
{
}

void month_pie_chart_widget::update()
{
    update_month_table();
    update_month_charts();
}

void month_pie_chart_widget::init_charts()
{
    __charts = new QChartView(this);

    ui->horizontalLayout_chart->addWidget(__charts);
}

void month_pie_chart_widget::update_month_table()
{
    //当月统计
    auto money_list = money_data.poll_money(money_data.get_month(), money_data.get_date());
    float consumer_total = 0.0f;//消费总计
    float wages_total = 0.0f;//工资总计
    list < std::pair<string, float>> class_list;
    for (auto iter = money_list.begin(); iter != money_list.end(); ++iter)
    {
        //统计总金额
        if (iter->money_type != "工资")
            consumer_total += iter->money;
        else
            wages_total += iter->money;
        //统计类别
        auto class_iter = class_list.begin();
        for (; class_iter != class_list.end(); ++class_iter)
        {
            if (class_iter->first == iter->money_type)
                break;
        }
        if (class_iter != class_list.end())
            class_iter->second += iter->money;
        else
        {
            std::pair<string, float> item;
            item.first = iter->money_type;
            item.second = iter->money;
            class_list.push_back(item);
        }
    }

    ui->groupBox_month->setTitle(QString::fromLocal8Bit("本月总计 %1/%2").arg(consumer_total).arg(wages_total));
    int row = 0;
    ui->tableWidget_month_class->setRowCount(class_list.size());
    for (auto class_iter = class_list.begin(); class_iter != class_list.end(); ++class_iter, ++row)
    {
        QTableWidgetItem* item = new QTableWidgetItem();
        item->setText(QString::fromLocal8Bit(class_iter->first.c_str()));
        ui->tableWidget_month_class->setItem(row, 0, item);
        item = new QTableWidgetItem();
        item->setText(QString::fromLocal8Bit("%1").arg(class_iter->second));
        ui->tableWidget_month_class->setItem(row, 1, item);
        item = new QTableWidgetItem();
        if (class_iter->first != "工资")
            item->setText(QString::fromLocal8Bit("%1%").arg(QString::number(100 * class_iter->second / consumer_total, 'f', 2)));
        else
            item->setText(QString::fromLocal8Bit("%1%").arg(QString::number(100, 'f', 2)));
        ui->tableWidget_month_class->setItem(row, 2, item);
    }
}

void month_pie_chart_widget::update_month_charts()
{
    __charts->chart()->removeAllSeries();
    //当月统计
    auto money_list = money_data.poll_money(money_data.get_month(), money_data.get_date());
    list < std::pair<string, float>> class_list;
    for (auto iter = money_list.begin(); iter != money_list.end(); ++iter)
    {
        if (iter->money_type == "工资")
            continue;
        //统计类别
        auto class_iter = class_list.begin();
        for (; class_iter != class_list.end(); ++class_iter)
        {
            if (class_iter->first == iter->money_type)
                break;
        }
        if (class_iter != class_list.end())
            class_iter->second += iter->money;
        else
        {
            std::pair<string, float> item;
            item.first = iter->money_type;
            item.second = iter->money;
            class_list.push_back(item);
        }
    }

    QPieSeries *series = new QPieSeries();

    for (auto class_iter = class_list.begin(); class_iter != class_list.end(); ++class_iter)
    {
        series->append(QString::fromLocal8Bit(class_iter->first.c_str()), class_iter->second);
    }
    series->setLabelsVisible(true);
    __charts->chart()->removeAllSeries();
    __charts->chart()->addSeries(series);

    __charts->chart()->setTitle(QString::fromLocal8Bit("本月消费"));
}
