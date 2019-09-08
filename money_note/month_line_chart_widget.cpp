#include "month_line_chart_widget.h"
#include "ui_month_line_chart_widget.h"
#include "money_data.h"
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>

using namespace QtCharts;
#ifdef _DEBUG
#pragma comment(lib,"Qt5Chartsd.lib")
#else
#pragma comment(lib,"Qt5Charts.lib")
#endif

month_line_chart_widget::month_line_chart_widget(QWidget* parent)
    :item_widget(parent)
    ,ui(new Ui::month_line_chart_widget())
{
    ui->setupUi(this); 
    ui->tableWidget_month->verticalHeader()->hide();
    ui->tableWidget_month->setEditTriggers(QAbstractItemView::NoEditTriggers);
    init_charts();
}

month_line_chart_widget::~month_line_chart_widget()
{
}

void month_line_chart_widget::update()
{
    update_month_table();
    update_month_charts();
}

void month_line_chart_widget::init_charts()
{
    __charts = new QChartView(this);

    ui->horizontalLayout_chart->addWidget(__charts);
}

void month_line_chart_widget::update_month_table()
{
    //年度统计
    auto money_list = money_data.poll_money(money_data.get_year(), money_data.get_date());
    float total = 0.0f;
    list<std::pair<int, float>> month_list;
    list < std::pair<string, float>> class_list;
    for (auto iter = money_list.begin(); iter != money_list.end(); ++iter)
    {
        //统计总金额
        total += iter->money;
        //统计月份
        auto month_iter = month_list.begin();
        for (; month_iter != month_list.end(); ++month_iter)
        {
            if (month_iter->first == iter->data / 100)
                break;
        }
        if (month_iter != month_list.end())
            month_iter->second += iter->money;
        else
        {
            std::pair<int, float> item;
            item.first = iter->data / 100;
            item.second = iter->money;
            month_list.push_back(item);
        }
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

    ui->groupBox_year->setTitle(QString::fromLocal8Bit("年度总计 %1").arg(total));
    ui->tableWidget_month->setRowCount(month_list.size());
    int row = 0;
    for (auto month_iter = month_list.begin(); month_iter != month_list.end(); ++month_iter, ++row)
    {
        QTableWidgetItem* item = new QTableWidgetItem();
        item->setText(QString::fromLocal8Bit("%1月").arg(month_iter->first % 10));
        ui->tableWidget_month->setItem(row, 0, item);
        item = new QTableWidgetItem();
        item->setText(QString::fromLocal8Bit("%1").arg(month_iter->second));
        ui->tableWidget_month->setItem(row, 1, item);
    }
}

void month_line_chart_widget::update_month_charts()
{
    __charts->chart()->removeAllSeries();
    //年度统计
    auto money_list = money_data.poll_money(money_data.get_year(), money_data.get_date());
    list<std::pair<int, float>> month_list;
    list < std::pair<string, float>> class_list;
    for (auto iter = money_list.begin(); iter != money_list.end(); ++iter)
    {
        //统计月份
        auto month_iter = month_list.begin();
        for (; month_iter != month_list.end(); ++month_iter)
        {
            if (month_iter->first == iter->data / 100)
                break;
        }
        if (month_iter != month_list.end())
            month_iter->second += iter->money;
        else
        {
            std::pair<int, float> item;
            item.first = iter->data / 100;
            item.second = iter->money;
            month_list.push_back(item);
        }
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

    QLineSeries *seriesx = new QLineSeries();
    seriesx->setName(QString::fromLocal8Bit("金额"));
    QStringList categories;

    int row = 0;
    double max_value = 0;
    for (auto month_iter = month_list.begin(); month_iter != month_list.end(); ++month_iter, ++row)
    {
        categories << QString::fromLocal8Bit("%1月").arg(month_iter->first % 10);
        seriesx->append(row, month_iter->second);
        if (month_iter->second > max_value)
            max_value = month_iter->second;
    }

    __charts->chart()->addSeries(seriesx);

    QValueAxis *axisx = new QValueAxis;
    axisx->setTitleText(QString::fromLocal8Bit("月"));
    QBarCategoryAxis *axis = new QBarCategoryAxis();
    axis->append(categories);
    __charts->chart()->createDefaultAxes();
    __charts->chart()->setAxisX(axis, seriesx);

    QValueAxis *axisy = new QValueAxis;
    axisy->setRange(0, max_value);
    axisy->setTitleText(QString::fromLocal8Bit("元"));
    __charts->chart()->setAxisY(axisy, seriesx);

    __charts->chart()->setTitle(QString::fromLocal8Bit("年度消费"));
}
