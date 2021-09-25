#include "add_note_widget.h"
#include "ui_add_note_widget.h"
#include "money_data.h"
#include <QMessageBox>
#include "add_note_table_delegate.h"
#define ROWID Qt::UserRole+1

add_note_widget::add_note_widget(QWidget* parent) :
    item_widget(parent),
    ui(new Ui::add_note_widget())
{
    ui->setupUi(this);
    ui->tableWidget_day->verticalHeader()->hide();
    //ui->tableWidget_day->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->doubleSpinBox_value->setValue(0);
    ui->dateEdit->setCalendarPopup(true);

    //设置消息记录的显示代理
    add_note_table_delegate* table_delegate = new add_note_table_delegate(this);
    ui->tableWidget_day->setItemDelegate(table_delegate);
    ui->doubleSpinBox_value->installEventFilter(this);
    ui->lineEdit_note->installEventFilter(this);
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
    ui->doubleSpinBox_value->setFocus();
}

void add_note_widget::timerEvent(QTimerEvent * event)
{
    if (event->timerId() == m_valueSelectAllTimer)
    {
        killTimer(m_valueSelectAllTimer);
        ui->doubleSpinBox_value->selectAll();
    }
    else if (event->timerId() == m_noteSelectAllTimer)
    {
        killTimer(m_noteSelectAllTimer);
        ui->lineEdit_note->selectAll();
    }
}

bool add_note_widget::eventFilter(QObject * target, QEvent * event)
{
    if (target == ui->doubleSpinBox_value)
    {
        if (event->type() == QEvent::FocusIn)
        {
            m_valueSelectAllTimer = startTimer(100);
        }
    }
    else if (target == ui->lineEdit_note)
    {
        if (event->type() == QEvent::FocusIn)
        {
            m_noteSelectAllTimer = startTimer(100);
        }
    }
    return QWidget::eventFilter(target, event);
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
    QStringList note_types;
    auto type_list = money_data.get_type_list();
    ui->comboBox_type->clear();
    for (auto iter = type_list.begin(); iter != type_list.end(); ++iter)
    {
        ui->comboBox_type->addItem(iter->first);
        note_types.push_back(iter->first);
    }
    ui->comboBox_type->addItem(QStringLiteral("工资"));
    QString money_type = property("money_type").toString();
    if(money_type.length())
        ui->comboBox_type->setCurrentIndex(ui->comboBox_type->findText(money_type));

    add_note_table_delegate* table_delegate = dynamic_cast<add_note_table_delegate*>(ui->tableWidget_day->itemDelegate());
    if (table_delegate)
        table_delegate->set_note_types(note_types);
}

void add_note_widget::update_day_table()
{
    disconnect(ui->tableWidget_day, &QTableWidget::itemChanged, this, &add_note_widget::slot_tableWidget_day_itemChanged);
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
        item->setData(ROWID, iter->rowid);
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
    connect(ui->tableWidget_day, &QTableWidget::itemChanged, this, &add_note_widget::slot_tableWidget_day_itemChanged);
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
    {
        ui->doubleSpinBox_value->setFocus();
        ui->doubleSpinBox_value->selectAll();
        return;
    }
    QString money_note = ui->lineEdit_note->text();
    if (money_note.length())
        money_data.add_note(date_key, money_type, money, money_note);
    else
        money_data.add_note(date_key, money_type, money);

    setProperty("money_type", money_type);
    ui->lineEdit_note->clear();
    ui->doubleSpinBox_value->setValue(0);
    update();
}

void add_note_widget::slot_add_type_bt_clicked()
{
    //添加一条消费类别
    /*QString money_type = ui->lineEdit_type->text();
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
    money_data.add_type(money_type);*/
}

void add_note_widget::on_bt_remove_note_clicked()
{
    QString money, money_type, money_note;
    unsigned int rowid;
    QTableWidgetItem* item=ui->tableWidget_day->currentItem();
    if (!item)
        return;
    int row = item->row();
    item = ui->tableWidget_day->item(row, 0);
    money_type = item->text();
    rowid = item->data(ROWID).toUInt();
    item = ui->tableWidget_day->item(row, 1);
    money = item->text();
    item = ui->tableWidget_day->item(row, 2);
    if (item)
        money_note = item->text();
    QString msg_str;
    if (money_note.isEmpty())
    {
        msg_str = QStringLiteral("是否删除记录<%1,%2>").arg(money_type).arg(money);
    }
    else
    {
        msg_str = QStringLiteral("是否删除记录<%1,%2,%3>").arg(money_type).arg(money).arg(money_note);
    }
    if (QMessageBox::Ok != QMessageBox::information(this, QStringLiteral("提示"), msg_str, QMessageBox::Ok | QMessageBox::Cancel))
        return;
    money_data.remove_note(rowid);
    update_day_table();
}

void add_note_widget::slot_tableWidget_day_itemChanged(QTableWidgetItem * item)
{
    if (!item)
        return;
    QDate date = ui->dateEdit->date();
    int date_key = date.year() * 10000 + date.month() * 100 + date.day();
    QString money, money_type, money_note;
    unsigned int rowid;
    int row = item->row();
    item = ui->tableWidget_day->item(row, 0);
    money_type = item->text();
    rowid = item->data(ROWID).toUInt();
    item = ui->tableWidget_day->item(row, 1);
    money = item->text();
    item = ui->tableWidget_day->item(row, 2);
    if (item)
        money_note = item->text();
    money_data.update_note(rowid, date_key, money_type, money.toFloat(), money_note);
    update_day_table();
}