#include "year_line_chart_widget.h"
#include "ui_year_line_chart_widget.h"
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

year_line_chart_widget::year_line_chart_widget(QWidget* parent) :
    item_widget(parent),
    ui(new Ui::year_line_chart_widget())
{
    ui->setupUi(this);
    ui->tableWidget_year->verticalHeader()->hide();
    ui->tableWidget_year->setEditTriggers(QAbstractItemView::NoEditTriggers);
    init_charts();
}

year_line_chart_widget::~year_line_chart_widget()
{
}

void year_line_chart_widget::update()
{
    update_year_table();
    update_year_charts();
}

void year_line_chart_widget::init_charts()
{
    __charts = new QChartView(this);

    ui->horizontalLayout->addWidget(__charts);
}

void year_line_chart_widget::update_year_table()
{
    //年度统计
    auto money_list = money_data.poll_money(0, money_data.get_date());
    float consumer_total = 0.0f;//消费总计
    float wages_total = 0.0f;//工资总计
    list<std::pair<int, float>> consumer_year_list;
    list<std::pair<int, float>> wages_year_list;
    for (auto iter = money_list.begin(); iter != money_list.end(); ++iter)
    {
        //统计总金额
        if (iter->money_type == QStringLiteral("工资"))
        {
            wages_total += iter->money;
            //统计年份
            auto year_iter = wages_year_list.begin();
            for (; year_iter != wages_year_list.end(); ++year_iter)
            {
                if (year_iter->first == iter->data / 10000)
                    break;
            }
            if (year_iter != wages_year_list.end())
                year_iter->second += iter->money;
            else
            {
                std::pair<int, float> item;
                item.first = iter->data / 10000;
                item.second = iter->money;
                wages_year_list.push_back(item);
            }
        }
        else
        {
            consumer_total += iter->money;
            //统计年份
            auto year_iter = consumer_year_list.begin();
            for (; year_iter != consumer_year_list.end(); ++year_iter)
            {
                if (year_iter->first == iter->data / 10000)
                    break;
            }
            if (year_iter != consumer_year_list.end())
                year_iter->second += iter->money;
            else
            {
                std::pair<int, float> item;
                item.first = iter->data / 10000;
                item.second = iter->money;
                consumer_year_list.push_back(item);
            }
        }
    }

    ui->tableWidget_year->setRowCount(consumer_year_list.size());
    int row = 0;
    for (auto year_iter = consumer_year_list.begin(); year_iter != consumer_year_list.end(); ++year_iter, ++row)
    {
        QTableWidgetItem* item = new QTableWidgetItem();
        item->setText(QString::fromLocal8Bit("%1年").arg(year_iter->first % 10000));
        ui->tableWidget_year->setItem(row, 0, item);
        item = new QTableWidgetItem();
        item->setText(QString::fromLocal8Bit("%1").arg(year_iter->second));
        ui->tableWidget_year->setItem(row, 1, item);

        for (auto wages_year_iter = wages_year_list.begin(); wages_year_iter != wages_year_list.end(); ++wages_year_iter)
        {
            if (year_iter->first == wages_year_iter->first)
            {
                item = new QTableWidgetItem();
                item->setText(QString::fromLocal8Bit("%1").arg(wages_year_iter->second));
                ui->tableWidget_year->setItem(row, 2, item);
            }
        }
    }
}

void year_line_chart_widget::update_year_charts()
{
    //年度统计
    auto money_list = money_data.poll_money(0, money_data.get_date());
    float consumer_total = 0.0f;//消费总计
    float wages_total = 0.0f;//工资总计
    list<std::pair<int, float>> consumer_year_list;
    list<std::pair<int, float>> wages_year_list;
    for (auto iter = money_list.begin(); iter != money_list.end(); ++iter)
    {
        //统计总金额
        if (iter->money_type == QStringLiteral("工资"))
        {
            wages_total += iter->money;
            //统计年份
            auto year_iter = wages_year_list.begin();
            for (; year_iter != wages_year_list.end(); ++year_iter)
            {
                if (year_iter->first == iter->data / 10000)
                    break;
            }
            if (year_iter != wages_year_list.end())
                year_iter->second += iter->money;
            else
            {
                std::pair<int, float> item;
                item.first = iter->data / 10000;
                item.second = iter->money;
                wages_year_list.push_back(item);
            }
        }
        else
        {
            consumer_total += iter->money;
            //统计年份
            auto year_iter = consumer_year_list.begin();
            for (; year_iter != consumer_year_list.end(); ++year_iter)
            {
                if (year_iter->first == iter->data / 10000)
                    break;
            }
            if (year_iter != consumer_year_list.end())
                year_iter->second += iter->money;
            else
            {
                std::pair<int, float> item;
                item.first = iter->data / 10000;
                item.second = iter->money;
                consumer_year_list.push_back(item);
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
    for (auto year_iter = consumer_year_list.begin(); year_iter != consumer_year_list.end(); ++year_iter, ++row)
    {
        categories << QString::fromLocal8Bit("%1年").arg(year_iter->first % 10000);
        consumer_seriesx->append(row, year_iter->second);
        if (year_iter->second > max_value)
            max_value = year_iter->second;
    }

    //工资折线
    QLineSeries *wages_seriesx = new QLineSeries();
    wages_seriesx->setName(QStringLiteral("工资"));
    wages_seriesx->setColor(Qt::blue);

    row = 0;
    for (auto year_iter = wages_year_list.begin(); year_iter != wages_year_list.end(); ++year_iter, ++row)
    {
        wages_seriesx->append(row, year_iter->second);
        if (year_iter->second > max_value)
            max_value = year_iter->second;
    }

    consumer_seriesx->setPointLabelsFormat("@yPoint");
    wages_seriesx->setPointLabelsFormat("@yPoint");
    consumer_seriesx->setPointLabelsVisible(true);
    wages_seriesx->setPointLabelsVisible(true);
    __charts->chart()->addSeries(consumer_seriesx);
    __charts->chart()->addSeries(wages_seriesx);

    QBarCategoryAxis *axisx = new QBarCategoryAxis();
    axisx->append(categories);
    __charts->chart()->createDefaultAxes();
    __charts->chart()->setAxisX(axisx, consumer_seriesx);
    __charts->chart()->setAxisX(axisx, wages_seriesx);

    QValueAxis *axisy = new QValueAxis;
    axisy->setRange(0, ((int)(max_value + 999.99)) / 1000 * 1000);
    axisy->setTitleText(QString::fromLocal8Bit("元"));
    __charts->chart()->setAxisY(axisy, consumer_seriesx);
    __charts->chart()->setAxisY(axisy, wages_seriesx);

    __charts->chart()->setTitle(QString::fromLocal8Bit("历年总计"));
}
