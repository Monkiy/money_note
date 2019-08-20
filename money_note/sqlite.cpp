#include "sqlite.h"
#include <iostream>
#include <memory>
#include <Windows.h>
#include "code.h"
using std::cout;
using std::endl;
using std::string;
using std::shared_ptr;

sqlite::sqlite & sqlite::sqlite::get_sqlite()
{
    char buf[512] = {};
    ::GetModuleFileNameA(0, buf, sizeof(buf));
    int len = strlen(buf);
    for (int i = len-1; i > 0; --i)
    {
        if (buf[i] == '\\' || buf[i] == '/')
        {
            buf[i] = 0;
            break;
        }
    }
    strcat(buf, "\\sqlite.db");
    static sqlite sql(buf);
    return sql;
}

bool sqlite::sqlite::exec(const char * sql, const std::function<void(int, string*, string*)>& call_back)
{
    std::lock_guard<std::mutex> guard(__mutex);
    __sql_call_back = call_back;
    __error_msg = 0;
    if (__db)
    {
        std::string sql_str;
        str_to_str(sql, sql_str, CP_ACP, CP_UTF8);
        return sqlite3_exec(__db, sql_str.c_str(), sqlite::sql_call_back, this, &__error_msg);
    }
    return false;
}

bool sqlite::sqlite::exec(const char * sql)
{
    std::lock_guard<std::mutex> guard(__mutex);
    __error_msg = 0;
    if (__db)
    {
        std::string sql_str;
        str_to_str(sql, sql_str, CP_ACP, CP_UTF8);
        return sqlite3_exec(__db, sql_str.c_str(), 0, this, &__error_msg);
    }
    return false;
}

sqlite::sqlite::sqlite(const char * filename):
    __error_msg(0)
{
    if (0 != sqlite3_open(filename, &__db))
    {
        __db=0;
        cout << "打开数据库失败" << endl;
    }
}

sqlite::sqlite::~sqlite()
{
    if(__db)
        sqlite3_close(__db);
}

int sqlite::sqlite::sql_call_back(void * param, int argc, char ** argv, char ** col_name)
{
    sqlite* sql = reinterpret_cast<sqlite*>(param);
    if (sql&&sql->__sql_call_back)
    {
        shared_ptr<string> argv_tmp(new string[argc], [](string *ptr) {delete[] ptr; });
        shared_ptr<string> col_name_tmp(new string[argc], [](string *ptr) {delete[] ptr; });
        for (int i = 0; i < argc; ++i)
        {
            if (argv[i]&& col_name[i])
            {
                str_to_str(argv[i], argv_tmp.get()[i], CP_UTF8, CP_ACP);
                str_to_str(col_name[i], col_name_tmp.get()[i], CP_UTF8, CP_ACP);
            }
        }
        sql->__sql_call_back(argc, argv_tmp.get(), col_name_tmp.get());
    }
    return 0;
}
