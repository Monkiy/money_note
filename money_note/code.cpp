#include"code.h"

//其他字符串转Unicode 
void str_to_unicode(const std::string& str, std::wstring &unicode_str, int code_page)
{
    unicode_str.clear();
    int widesize = ::MultiByteToWideChar(code_page, 0, str.c_str(), -1, NULL, 0);
    if (widesize == ERROR_NO_UNICODE_TRANSLATION)
    {
        throw std::exception("Invalid UTF-8 sequence.");
    }
    if (widesize == 0)
    {
        throw std::exception("Error in conversion.");
    }
    unicode_str.resize(widesize);
    int convresult = ::MultiByteToWideChar(code_page, 0, str.c_str(), -1, const_cast<LPWSTR>(unicode_str.data()), widesize);
    if (convresult != widesize)
    {
        throw std::exception("La falla!");
    }
}

//unicode转为其他字符串
void unicode_to_str(const std::wstring &unicode_str, std::string& str, int code_page)
{
    int str_size = ::WideCharToMultiByte(code_page, 0, unicode_str.c_str(), -1, NULL, 0, NULL, NULL);
    if (str_size == ERROR_NO_UNICODE_TRANSLATION)
    {
        throw std::exception("Invalid UTF-8 sequence.");
    }
    if (str_size == 0)
    {
        throw std::exception("Error in conversion.");
    }
    str.resize(str_size);
    int convresult = ::WideCharToMultiByte(code_page, 0, unicode_str.c_str(), -1, const_cast<char*>(str.data()), str_size, NULL, NULL);
    if (convresult != str_size)
    {
       throw std::exception("La falla!");
    }
}

//first_code编码转next_code编码
void str_to_str(const std::string & first, std::string& next, int first_code, int next_code)
{
    if (first_code == next_code)
    {
        next = first;
        return;
    }
    std::wstring unicode_str;
    str_to_unicode(first, unicode_str, first_code);
    unicode_to_str(unicode_str, next, next_code);
}


//falot字符串转float
float str_to_float(const std::string &v)
{
    float ret = 0;
    const char*p0 = v.data();
    const char*p1 = p0;
    while (*p1&&'.' != *p1)
    {
        p1++;
    }
    ret = atoi(p0);
    if ('.' == *p1)
    {
        ++p1;
        ret = ret + atoi(p1)*pow(10.00f, -1.00f*strlen(p1));
    }
    return ret;
}

//int字符串转int
int str_to_int(const std::string & v)
{
    return atoi(v.c_str());
}
