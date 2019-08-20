#pragma once
#include<Windows.h>
#include<string>

/*
CodePage��ָ��ִ��ת�����ַ�����
�����������Ϊϵͳ�Ѱ�װ����Ч���κ��ַ�����������ֵ��
��Ҳ����ָ����Ϊ���������һֵ��

#define CP_ACP                    0           // default to ANSI code page
#define CP_OEMCP                  1           // default to OEM  code page
#define CP_MACCP                  2           // default to MAC  code page
#define CP_THREAD_ACP             3           // current thread's ANSI code page
#define CP_SYMBOL                 42          // SYMBOL translations
#define CP_UTF7                   65000       // UTF-7 translation
#define CP_UTF8                   65001       // UTF-8 translation

CP_ACP��ANSI�ַ�����
CP_MACCP��Macintosh����ҳ��
CP_OEMCP��OEM����ҳ��
CP_SYMBOL�������ַ�����42����
CP_THREAD_ACP����ǰ�߳�ANSI����ҳ��
CP_UTF7��ʹ��UTF-7ת����
CP_UTF8��ʹ��UTF-8ת����

*/
//code_page����תunicode
void str_to_unicode(const std::string& str, std::wstring &unicode_str, int code_page);
//unicode����תcode_page����
void unicode_to_str(const std::wstring &unicode_str,std::string& str,int code_page);

//first_code����תnext_code����
void str_to_str(const std::string& first, std::string& next,int first_code,int next_code);

//falot�ַ���תfloat
float str_to_float(const std::string &v);
//int�ַ���תint
int str_to_int(const std::string &v);