#include "money_note_widget.h"
#include "ui_money_note_widget.h"
#include "money_data.h"
#include "widget_list.h"
#include "add_note_widget.h"
#include "year_line_chart_widget.h"
#include "month_line_chart_widget.h"
#include "year_pie_chart_widget.h"
#include "month_pie_chart_widget.h"

money_note_widget::money_note_widget(QWidget* parent):
    item_widget(parent),
    ui(new Ui::money_note_widget())
{
    ui->setupUi(this);
    ui->tableWidget_year->verticalHeader()->hide();
    ui->tableWidget_year_class->verticalHeader()->hide();
    ui->tableWidget_month_class->verticalHeader()->hide();
    ui->tableWidget_day->verticalHeader()->hide();
    ui->tableWidget_year->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget_year_class->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget_month_class->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget_day->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

money_note_widget::~money_note_widget()
{
    delete ui;
}

void money_note_widget::update()
{
    update_year_table();
    update_month_table();
    update_day_table();
}

void money_note_widget::update_year_table()
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
    ui->dateEdit_year->setDate(QDate(money_data.get_year() / 10000, 1, 1));
    ui->tableWidget_year->setRowCount(month_list.size());
    int row = 0;
    for (auto month_iter = month_list.begin(); month_iter != month_list.end(); ++month_iter, ++row)
    {
        QTableWidgetItem* item = new QTableWidgetItem();
        item->setText(QString::fromLocal8Bit("%1月").arg(month_iter->first % 10));
        ui->tableWidget_year->setItem(row, 0, item);
        item = new QTableWidgetItem();
        item->setText(QString::fromLocal8Bit("%1").arg(month_iter->second));
        ui->tableWidget_year->setItem(row, 1, item);
    }
    ui->tableWidget_year_class->setRowCount(class_list.size());
    row = 0;
    for (auto class_iter = class_list.begin(); class_iter != class_list.end(); ++class_iter, ++row)
    {
        QTableWidgetItem* item = new QTableWidgetItem();
        item->setText(QString::fromLocal8Bit(class_iter->first.c_str()));
        ui->tableWidget_year_class->setItem(row, 0, item);
        item = new QTableWidgetItem();
        item->setText(QString::fromLocal8Bit("%1").arg(class_iter->second));
        ui->tableWidget_year_class->setItem(row, 1, item);
        item = new QTableWidgetItem();
        item->setText(QString::fromLocal8Bit("%1%").arg(QString::number(100 * class_iter->second / total, 'f', 2)));
        ui->tableWidget_year_class->setItem(row, 2, item);
    }
}

void money_note_widget::update_month_table()
{
    //当月统计
    auto money_list = money_data.poll_money(money_data.get_month(), money_data.get_date());
    float total = 0.0f;
    list < std::pair<string, float>> class_list;
    for (auto iter = money_list.begin(); iter != money_list.end(); ++iter)
    {
        //统计总金额
        total += iter->money;
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

    ui->groupBox_month->setTitle(QString::fromLocal8Bit("本月总计 %1").arg(total));
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
        item->setText(QString::fromLocal8Bit("%1%").arg(QString::number(100 * class_iter->second / total, 'f', 2)));
        ui->tableWidget_month_class->setItem(row, 2, item);
    }
}

void money_note_widget::update_day_table()
{
    //更新当日消费纪录
    auto money_list = money_data.poll_money(money_data.get_date(), money_data.get_date());
    ui->tableWidget_day->setRowCount(money_list.size());
    float total = 0.0f;
    int row_count = 0;
    for (auto iter = money_list.begin(); iter != money_list.end(); ++iter, ++row_count)
    {
        //将消费纪录添加到当日消费列表
        QTableWidgetItem* item = new QTableWidgetItem();
        item->setText(QString::fromLocal8Bit(iter->money_type.c_str()));
        ui->tableWidget_day->setItem(row_count, 0, item);
        item = new QTableWidgetItem();
        item->setText(QString::number(iter->money, 'f', 2));
        ui->tableWidget_day->setItem(row_count, 1, item);
        item = new QTableWidgetItem();
        item->setText(QString::fromLocal8Bit(iter->money_note.c_str()));
        ui->tableWidget_day->setItem(row_count, 2, item);

        total += iter->money;
    }
    ui->groupBox_day->setTitle(QString::fromLocal8Bit("今日总计 %1").arg(total));
}

void money_note_widget::slot_year_line_chart_bt_clicked()
{
    widgets.push_widget(new year_line_chart_widget());
}

void money_note_widget::slot_month_line_chart_bt_clicked()
{
    widgets.push_widget(new month_line_chart_widget());
}

void money_note_widget::slot_year_pie_chart_bt_clicked()
{
    widgets.push_widget(new year_pie_chart_widget());
}

void money_note_widget::slot_month_pie_chart_bt_clicked()
{
    widgets.push_widget(new month_pie_chart_widget());
}

void money_note_widget::slot_add_note_bt_clicked()
{
    widgets.push_widget(new add_note_widget());
}