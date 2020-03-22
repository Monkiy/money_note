#include "add_note_widget.h"
#include "ui_add_note_widget.h"
#include "money_data.h"

add_note_widget::add_note_widget(QWidget* parent) :
    item_widget(parent),
    ui(new Ui::add_note_widget())
{
    ui->setupUi(this);
    ui->tableWidget_day->verticalHeader()->hide();
    ui->tableWidget_day->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->doubleSpinBox_value->clear();
    ui->dateEdit->setCalendarPopup(true);
}

add_note_widget::~add_note_widget()
{
    delete ui;
}

void add_note_widget::update()
{
    update_date();
    update_type_combox();
    update_day_table();
}

void add_note_widget::update_date()
{
    QDate date = property("date").toDate();
    if (date.isNull())
    {
        ui->dateEdit->setDate(QDate(money_data.get_date() / 10000,
        (money_data.get_date() % 10000) / 100,
        money_data.get_date() % 100));
    }
    else
    {
        ui->dateEdit->setDate(date);
    }
}

void add_note_widget::update_type_combox()
{
    //更新消费类别选项
    auto type_list = money_data.get_type_list();
    ui->comboBox_type->clear();
    for (auto iter = type_list.begin(); iter != type_list.end(); ++iter)
    {
        ui->comboBox_type->addItem(iter->first);
    }
    QString money_type = property("money_type").toString();
    if(money_type.length())
        ui->comboBox_type->setCurrentIndex(ui->comboBox_type->findText(money_type));
}

void add_note_widget::update_day_table()
{
    //更新当日消费纪录
    QDate date = ui->dateEdit->date();
    int date_key = date.year() * 10000 + date.month() * 100 + date.day();
    auto money_list = money_data.poll_money(date_key, date_key);
    ui->tableWidget_day->setRowCount(money_list.size());
    float total = 0.0f;
    int row_count = 0;
    for (auto iter = money_list.begin(); iter != money_list.end(); ++iter, ++row_count)
    {
        //将消费纪录添加到当日消费列表
        QTableWidgetItem* item = new QTableWidgetItem();
        item->setText(iter->money_type);
        ui->tableWidget_day->setItem(row_count, 0, item);
        item = new QTableWidgetItem();
        item->setText(QString::number(iter->money, 'f', 2));
        ui->tableWidget_day->setItem(row_count, 1, item);
        item = new QTableWidgetItem();
        item->setText(iter->money_note);
        ui->tableWidget_day->setItem(row_count, 2, item);

        if (iter->money_type != QStringLiteral("工资"))
            total += iter->money;
    }
    ui->groupBox_day->setTitle(QString::fromLocal8Bit("%1 总计 %2").arg(date.toString("yyyy/MM/dd")).arg(total));
}

void add_note_widget::slot_date_changed()
{
    int date_val = ui->dateEdit->date().toString("yyyyMMdd").toInt();
    if (date_val > money_data.get_date())
    {
        ui->dateEdit->setDate(QDate(money_data.get_date() / 10000,
            (money_data.get_date() % 10000) / 100,
            money_data.get_date() % 100));
        return;
    }
    setProperty("date", ui->dateEdit->date());
    update();
}

void add_note_widget::slot_add_note_bt_clicked()
{
    //添加一条消费纪录
    QDate date = ui->dateEdit->date();
    int date_key = date.year() * 10000 + date.month() * 100 + date.day();
    QString money_type = ui->comboBox_type->currentText();
    if (0 == money_type.length())
        return;
    float money = ui->doubleSpinBox_value->value();
    if (0.01l > money)
        return;
    QString money_note = ui->lineEdit_note->text();
    if (money_note.length())
        money_data.add_note(date_key, money_type.toLocal8Bit().data(), money, money_note.toLocal8Bit().data());
    else
        money_data.add_note(date_key, money_type.toLocal8Bit().data(), money);

    setProperty("money_type", money_type);
    ui->doubleSpinBox_value->clear();
    ui->lineEdit_note->clear();
    update();
}

void add_note_widget::slot_add_type_bt_clicked()
{
    //添加一条消费类别
    QString money_type = ui->lineEdit_type->text();
    if (0 == money_type.length())
        return;
    ui->lineEdit_type->clear();
    if (0 <= ui->comboBox_type->findText(money_type))
    {
        ui->comboBox_type->setCurrentIndex(ui->comboBox_type->findText(money_type));
        return;
    }
    ui->comboBox_type->addItem(money_type);
    ui->comboBox_type->setCurrentIndex(ui->comboBox_type->findText(money_type));
    money_data.add_type(money_type.toLocal8Bit().data());
}
