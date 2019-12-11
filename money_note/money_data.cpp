#include "money_data.h"
#include "sqlite.h"
#include "code.h"

money_sql_data & money_sql_data::get_instance()
{
    static money_sql_data sql;
    return sql;
}

void money_sql_data::add_note(int date, const char * money_type, float money, const char * note)
{
    char sql[512] = {};
    if (note)
    {
        snprintf(sql, sizeof(sql),
            "insert into money_note(date,type,money,note) "
            "values "
            "(%d,'%s',%.2f,'%s');", date, money_type, money, note);
    }
    else
    {
        snprintf(sql, sizeof(sql),
            "insert into money_note(date,type,money) "
            "values "
            "(%d,'%s',%.2f);", date, money_type, money);
    }
    SQL.exec(sql);
}

void money_sql_data::add_note(const char * money_type, float money, const char * note)
{
    add_note(get_date(), money_type, money, note);
}

void money_sql_data::add_type(const char * money_type)
{
    char sql[512] = {};
    snprintf(sql, sizeof(sql),
        "insert into note_type(name,use_times) "
        "values "
        "('%s',%d);", money_type, 9999);
    SQL.exec(sql);
}

list<std::pair<string, int>> money_sql_data::get_type_list()
{
    list<std::pair<string, int>> type_list;
    char sql[512] = "select * from note_type;";
    auto show_note_sql_call_back = [&type_list](int argc, std::string* argv, std::string* col_name)
    {
        if (2 > argc)
            return;
        std::pair<string, int> item;
        item.first = argv[0];
        item.second = str_to_int(argv[1]);
        type_list.push_back(item);
    };
    SQL.exec(sql, show_note_sql_call_back);
    return type_list;
}

list<money_data_item> money_sql_data::poll_money(int start_date, int end_date)
{
    char sql[512] = {};
    snprintf(sql, sizeof(sql),
        "select rowid,* from money_note where date>=%d and date <= %d;", start_date, end_date);
    list<money_data_item> money_list;
    auto show_note_sql_call_back = [&money_list](int argc, std::string* argv, std::string* col_name)
    {
        if (4 > argc)
            return;
        money_data_item item;
        item.rowid= str_to_int(argv[0]);
        item.data = str_to_int(argv[1]);
        item.money_type = argv[2];
        item.money = str_to_float(argv[3]);
        if (argc == 5)
            item.money_note = argv[4];
        money_list.push_back(item);
    };
    SQL.exec(sql, show_note_sql_call_back);
    return money_list;
}

list < std::pair<string, float>> money_sql_data::poll_class(int start_date, int end_date)
{
    return list < std::pair<string, float>>();
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
