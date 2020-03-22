#include "money_data.h"
#include <QApplication>
#include <QMessageBox>

money_sql_data & money_sql_data::get_instance()
{
    static money_sql_data sql;
    return sql;
}

void money_sql_data::add_note(int date, const QString& money_type, float money, const QString& note)
{
    QString sql;
    if (!note.isEmpty())
    {
        sql=QString("insert into money_note(date,type,money,note) values (%1,'%2',%3,'%4');")
            .arg(date).arg(money_type).arg(money).arg(note);
    }
    else
    {
        sql = QString("insert into money_note(date,type,money) values (%1,'%2',%3);")
            .arg(date).arg(money_type).arg(money);
    }
    QSqlQuery query;
    query.exec(sql);
}

void money_sql_data::add_note(const QString& money_type, float money, const QString& note)
{
    add_note(get_date(), money_type, money, note);
}

void money_sql_data::update_note(unsigned int rowid, int date, const QString& money_type, float money, const QString& note)
{
    QString sql;
    if (!note.isEmpty())
    {
        sql=QString("update money_note set date=%1,type='%2',money=%3,note='%4' where rowid=%5")
            .arg(date).arg(money_type).arg(money).arg(note).arg(rowid);
    }
    else
    {
        sql = QString("update money_note set date=%1,type='%2',money=%3,note=null where rowid=%4")
            .arg(date).arg(money_type).arg(money).arg(rowid);
    }
    QSqlQuery query;
    query.exec(sql);
}

void money_sql_data::remove_note(unsigned int rowid)
{
    QString sql = QString("delete from money_note where rowid=%1").arg(rowid);
    QSqlQuery query;
    query.exec(sql);
}

void money_sql_data::add_type(const QString& money_type)
{
    QString sql = QString("insert into note_type(name,use_times) values ('%1',%2);").arg(money_type).arg(0);
    QSqlQuery query;
    query.exec(sql);
}

list<std::pair<QString, int>> money_sql_data::get_type_list()
{
    list<std::pair<QString, int>> type_list;
    char sql[512] = "select * from note_type;";

    QSqlQuery query;
    query.exec(sql);
    if(!query.first())
        return type_list;
    do
    {
        QSqlRecord record = query.record();
        std::pair<QString, int> item;
        item.first = record.value("name").toString();
        item.second = record.value("use times").toInt();
        type_list.push_back(item);
    } while (query.next());
    return type_list;
}

list<money_data_item> money_sql_data::poll_money(int start_date, int end_date)
{
    char sql[512] = {};
    snprintf(sql, sizeof(sql),
        "select rowid,* from money_note where date>=%d and date <= %d;", start_date, end_date);
    list<money_data_item> money_list;

    QSqlQuery query;
    query.exec(sql);
    if (!query.first())
        return money_list;
    do
    {
        QSqlRecord record = query.record();
        money_data_item item;
        item.rowid = record.value("rowid").toInt();
        item.data = record.value("date").toInt();
        item.money_type = record.value("type").toString();
        item.money = record.value("money").toFloat();
        item.money_note = record.value("note").toString();
        money_list.push_back(item);
    } while (query.next());
    return money_list;
}

int money_sql_data::get_date()
{
    time_t t = time(0);
    tm* m = localtime(&t);
    int date = (1900 + m->tm_year) * 10000 + (m->tm_mon + 1) * 100 + m->tm_mday;
    return date;
}

int money_sql_data::get_month()
{
    time_t t = time(0);
    tm* m = localtime(&t);
    int date = (1900 + m->tm_year) * 10000 + (m->tm_mon + 1) * 100 + 1;
    return date;
}

int money_sql_data::get_year()
{
    time_t t = time(0);
    tm* m = localtime(&t);
    int date = (1900 + m->tm_year) * 10000 + 1 * 100 + 1;
    return date;
}

money_sql_data::money_sql_data()
{
    __db= QSqlDatabase::addDatabase("QSQLITE"); //添加 SQL LITE数据库驱动
    QString app_path= QCoreApplication::applicationDirPath();
    QString db_file = app_path = app_path + "/sqlite.db";
    __db.setDatabaseName(db_file); //设置数据库名称
    if (!__db.open())   //打开数据库
    {
        QMessageBox::warning(0, QStringLiteral("错误"), QStringLiteral("打开数据库失败"),
            QMessageBox::Ok, QMessageBox::NoButton);
        return;
    }
}
