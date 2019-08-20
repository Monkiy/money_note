#pragma once
#include <string>
#include <list>

#define money_data money_sql_data::get_instance()

using std::list;
using std::string;

struct money_data_item
{
    int data;
    float money;
    string money_type;
    string money_note;
};

class money_sql_data
{
public:
    static money_sql_data& get_instance();
    void add_note(int date, const char* money_type, float money, const char* note = 0);
    void add_note(const char* money_type, float money, const char* note = 0);
    void add_type(const char* money_type);
    list<std::pair<string, int>> get_type_list();

    list<money_data_item> poll_money(int start_date, int end_date);
    list < std::pair<string, float>> poll_class(int start_date, int end_date);

    static int get_date();
    static int get_month();
    static int get_year();
private:
private:
    money_sql_data() {}
    money_sql_data(const money_sql_data&);
};