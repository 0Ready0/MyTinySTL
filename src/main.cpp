#include<iostream>
#include <windows.h>   // 仅 Windows 需要

#include "MyString.h"

void testMyString(){
    cout << "------------------------- 1. 构造 -----------------------------" << endl;
    // 1.1默认构造
    MyString str1("hello String");
    cout << "1.1 MyString 默认构造:" << str1 << endl;

    // 1.2拷贝构造
    MyString str2 = str1;
    cout << "1.2 MyString 拷贝构造:" << str2 << endl;

    // 1.3 采用字符串初始化
    MyString str3 = "12345";
    cout << "1.3 采用字符串初始化:" << str3 << endl;

    // 1.4 采用n个字符初始化
    char ch1_4 = '1';
    MyString str4;
    str4 = ch1_4;
    cout << "1.4 采用字符串初始化:" << str4 << endl;


    cout << "------------------------- 2.assign赋值 -----------------------------" <<endl;
    // 2.1 将char*类型字符串赋给当前字符串
    MyString str2_1;
    str2_1.MyString::assign("assign");
    cout << "2.1 char*的assign赋值:" << str2_1 << endl;
    // 2.2 MyString类型字符串str赋给当前字符串
    MyString str2_2;
    str2_2.MyString::assign(str3);
    cout << "2.2 MyString类型字符串的assign赋值：" << str2_2 << endl;
    // 2.3 把字符串s前n个字符赋给当前字符串
    MyString str2_3;
    str2_3.MyString::assign("assign", 3);
    cout << "2.3 assign的前3个字符赋值：" << str2_3 << endl;
    // 2.4 把n个字符c赋给当前字符串
    MyString str2_4;
    str2_4.MyString::assign(5, '6');
    cout << "2.3 重复n个字符ch赋值：" << str2_4 << endl;

    cout << "------------------------- 3.拼接 -----------------------------" << endl;
    // 3.1 将char*类型字符串与当前字符串拼接
    MyString str3_1("str3_1");
    char ch3_1[] = "pinjie";
    cout << "3.1 char* 类型字符串拼接：" << str3_1 + ch3_1 << endl;

    // 3.2 将char类型 字符 与当前字符串拼接
    MyString str3_2("str3_2");
    char ch3_2 = '2';
    cout << "3.2 char* 类型字符串拼接：" << str3_2 + ch3_2 << endl;

    // 3.3 将MyString类型字符串与当前字符串拼接
    MyString str3_3("str3_1");
    MyString ch3_3 = "pinjie";
    cout << "3.3 char* 类型字符串拼接：" << str3_3 + ch3_3 << endl;
}
int main(){
    // 设置控制台输出为 UTF-8
    SetConsoleOutputCP(CP_UTF8);

    testMyString();

    return 0;
}