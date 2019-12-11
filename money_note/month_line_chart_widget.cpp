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
    float consumer_total = 0.0f;//消费总计
    float wages_total = 0.0f;//工资总计
    list<std::pair<int, float>> consumer_month_list;
    list<std::pair<int, float>> wages_month_list;
    for (auto iter = money_list.begin(); iter != money_list.end(); ++iter)
    {
        //统计总金额
        if (iter->money_type == "工资")
        {
            wages_total += iter->money;
            //统计月份
            auto month_iter = wages_month_list.begin();
            for (; month_iter != wages_month_list.end(); ++month_iter)
            {
                if (month_iter->first == iter->data / 100)
                    break;
            }
            if (month_iter != wages_month_list.end())
                month_iter->second += iter->money;
            else
            {
                std::pair<int, float> item;
                item.first = iter->data / 100;
                item.second = iter->money;
                wages_month_list.push_back(item);
            }
        }
        else
        {
            consumer_total += iter->money;
            //统计月份
            auto month_iter = consumer_month_list.begin();
            for (; month_iter != consumer_month_list.end(); ++month_iter)
            {
                if (month_iter->first == iter->data / 100)
                    break;
            }
            if (month_iter != consumer_month_list.end())
                month_iter->second += iter->money;
            else
            {
                std::pair<int, float> item;
                item.first = iter->data / 100;
                item.second = iter->money;
                consumer_month_list.push_back(item);
            }
        }
    }

    ui->groupBox_year->setTitle(QString::fromLocal8Bit("年度总计 %1/%2").arg(consumer_total).arg(wages_total));
    ui->tableWidget_month->setRowCount(consumer_month_list.size());
    int row = 0;
    for (auto month_iter = consumer_month_list.begin(); month_iter != consumer_month_list.end(); ++month_iter, ++row)
    {
        QTableWidgetItem* item = new QTableWidgetItem();
        item->setText(QString::fromLocal8Bit("%1月").arg(month_iter->first % 100));
        ui->tableWidget_month->setItem(row, 0, item);
        item = new QTableWidgetItem();
        item->setText(QString::fromLocal8Bit("%1").arg(month_iter->second));
        ui->tableWidget_month->setItem(row, 1, item);

        for (auto wages_month_iter = wages_month_list.begin(); wages_month_iter != wages_month_list.end(); ++wages_month_iter)
        {
            if (month_iter->first == wages_month_iter->first)
            {
                item = new QTableWidgetItem();
                item->setText(QString::fromLocal8Bit("%1").arg(wages_month_iter->second));
                ui->tableWidget_month->setItem(row, 2, item);
            }
        }
    }
}

void month_line_chart_widget::update_month_charts()
{
    __charts->chart()->removeAllSeries();
    //年度统计
    auto money_list = money_data.poll_money(money_data.get_year(), money_data.get_date());
    list<std::pair<int, float>> consumer_month_list;
    list<std::pair<int, float>> wages_month_list;
    for (auto iter = money_list.begin(); iter != money_list.end(); ++iter)
    {
        //统计总金额
        if (iter->money_type == "工资")
        {
            //统计月份
            auto month_iter = wages_month_list.begin();
            for (; month_iter != wages_month_list.end(); ++month_iter)
            {
                if (month_iter->first == iter->data / 100)
                    break;
            }
            if (month_iter != wages_month_list.end())
                month_iter->second += iter->money;
            else
            {
                std::pair<int, float> item;
                item.first = iter->data / 100;
                item.second = iter->money;
                wages_month_list.push_back(item);
            }
        }
        else
        {
            //统计月份
            auto month_iter = consumer_month_list.begin();
            for (; month_iter != consumer_month_list.end(); ++month_iter)
            {
                if (month_iter->first == iter->data / 100)
                    break;
            }
            if (month_iter != consumer_month_list.end())
                month_iter->second += iter->money;
            else
            {
                std::pair<int, float> item;
                item.first = iter->data / 100;
                item.second = iter->money;
                consumer_month_list.push_back(item);
            }
        }
    }

    //消费折线
    QLineSeries *consumer_seriesx = new QLineSeries();
    consumer_seriesx->setName(QString::fromLocal8Bit("消费"));
    consumer_seriesx->setColor(Qt::red);
    QStringList categories;

    int row = 0;
    double max_value = 0;
    for (auto month_iter = consumer_month_list.begin(); month_iter != consumer_month_list.end(); ++month_iter, ++row)
    {
        categories << QString::fromLocal8Bit("%1月").arg(month_iter->first % 100);
        consumer_seriesx->append(row, month_iter->second);
        if (month_iter->second > max_value)
            max_value = month_iter->second;
    }

    //工资折线
    QLineSeries *wages_seriesx = new QLineSeries();
    wages_seriesx->setName(QString::fromLocal8Bit("工资"));
    wages_seriesx->setColor(Qt::blue);

    row = 0;
    for (auto month_iter = wages_month_list.begin(); month_iter != wages_month_list.end(); ++month_iter, ++row)
    {
        wages_seriesx->append(row, month_iter->second);
        if (month_iter->second > max_value)
            max_value = month_iter->second;
    }

    __charts->chart()->addSeries(consumer_seriesx);
    __charts->chart()->addSeries(wages_seriesx);

    QBarCategoryAxis *axisx = new QBarCategoryAxis();
    axisx->append(categories);
    __charts->chart()->createDefaultAxes();
    __charts->chart()->setAxisX(axisx, consumer_seriesx);

    QValueAxis *axisy = new QValueAxis;
    axisy->setRange(0, ((int)(max_value+999.99))/1000*1000);
    axisy->setTitleText(QString::fromLocal8Bit("元"));
    __charts->chart()->setAxisY(axisy, consumer_seriesx);

    __charts->chart()->setTitle(QString::fromLocal8Bit("年度总计"));
}
