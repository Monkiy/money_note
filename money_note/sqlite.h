#pragma once
#include "sqlite3.h"
#include <mutex>
#include <string>
#include <functional>

#define SQL sqlite::sqlite::get_sqlite()
namespace sqlite
{
    class sqlite
    {
    public:
        static sqlite& get_sqlite();
        bool exec(const char *sql, const std::function<void(int, std::string*, std::string*)>& call_back);
        bool exec(const char *sql);
        inline const char* error_msg() { return __error_msg; }
    private:
        sqlite(const char* filename);
        sqlite(const sqlite&);
        ~sqlite();

        static int sql_call_back(void *param, int argc, char **argv, char **col_name);
    private:
        sqlite3* __db;
        std::mutex __mutex;
        char* __error_msg;
        std::function<void(int, std::string*, std::string*)> __sql_call_back;
    };
}

