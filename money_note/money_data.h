#pragma once
#include <list>
#include <QtSql>
#include <QSqlQuery>

#define money_data money_sql_data::get_instance()

using std::list;

struct money_data_item
{
    unsigned int rowid;
    int data;
    float money;
    QString money_type;
    QString money_note;
};

class money_sql_data
{
public:
    static money_sql_data& get_instance();
    void add_note(int date, const QString& money_type, float money, const QString& note = QString());
    void add_note(const QString& money_type, float money, const QString& note = 0);
    void update_note(unsigned int rowid,int date, const QString& money_type, float money, const QString& note = QString());
    void remove_note(unsigned int rowid);
    void add_type(const QString& money_type);
    list<std::pair<QString, int>> get_type_list();

    list<money_data_item> poll_money(int start_date, int end_date);

    static int get_date();
    static int get_month();
    static int get_year();
private:
private:
    money_sql_data();
    money_sql_data(const money_sql_data&);

private:
    QSqlDatabase __db; //数据库
};