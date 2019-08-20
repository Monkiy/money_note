#pragma once
#include<Windows.h>
#include<string>

/*
CodePage：指定执行转换的字符集，
这个参数可以为系统已安装或有效的任何字符集所给定的值。
你也可以指定其为下面的任意一值：

#define CP_ACP                    0           // default to ANSI code page
#define CP_OEMCP                  1           // default to OEM  code page
#define CP_MACCP                  2           // default to MAC  code page
#define CP_THREAD_ACP             3           // current thread's ANSI code page
#define CP_SYMBOL                 42          // SYMBOL translations
#define CP_UTF7                   65000       // UTF-7 translation
#define CP_UTF8                   65001       // UTF-8 translation

CP_ACP：ANSI字符集；
CP_MACCP：Macintosh代码页；
CP_OEMCP：OEM代码页；
CP_SYMBOL：符号字符集（42）；
CP_THREAD_ACP：当前线程ANSI代码页；
CP_UTF7：使用UTF-7转换；
CP_UTF8：使用UTF-8转换。

*/
//code_page编码转unicode
void str_to_unicode(const std::string& str, std::wstring &unicode_str, int code_page);
//unicode编码转code_page编码
void unicode_to_str(const std::wstring &unicode_str,std::string& str,int code_page);

//first_code编码转next_code编码
void str_to_str(const std::string& first, std::string& next,int first_code,int next_code);

//falot字符串转float
float str_to_float(const std::string &v);
//int字符串转int
int str_to_int(const std::string &v);