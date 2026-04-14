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

    // 3.4 将char*类型字符串与当前字符串拼接
    MyString str3_4("str3_4");
    char ch3_4[] = "_append_";
    cout << "3.4 char* 类型字符串拼接：" << str3_4.append(ch3_4) << endl;

    // 3.5 将char*类型字符串与当前字符串拼接
    MyString str3_5("str3_5");
    char ch3_5[] = "_append_";
    cout << "3.5 char* 类型字符串拼接(append)：" << str3_5.append(ch3_5, 7) << endl;

    // 3.6 将MyString类型字符串与当前字符串拼接
    MyString str3_6("str3_6");
    MyString ch3_6 = "_append_";
    cout << "3.6 char* 类型字符串拼接：" << str3_6.append(ch3_6) << endl;

    // 3.7 将char*类型字符串与当前字符串拼接
    MyString str3_7("str3_7");
    char ch3_7[] = "_append_";
    cout << "3.7 char* 类型字符串拼接(append)：" << str3_7.append(ch3_5, 1, 7) << endl;

    cout << "------------------------- 4.查找 -----------------------------" << endl;
    // 4.1 查找str第一次出现位置，从pos开始查找
    MyString str4_1("aabaabaaf");
    MyString substr4_1("aabaaf");
    int pos4_1 = 0;
    cout << "4.1 查找" << str4_1 << "起始位置为" << pos4_1 << "的子串" << substr4_1 << "的位置为：" << str4_1.find(substr4_1, pos4_1) << endl;

    // 4.2 查找char*第一次出现位置，从pos开始查找
    MyString str4_2("aabaabaaf");
    char* substr4_2 = new char[]{"aabaaf"};
    int pos4_2 = 0;
    cout << "4.2 查找" << str4_2 << "起始位置为" << pos4_2 << "的子串" << substr4_2 << "的位置为：" << str4_2.find(substr4_2, pos4_2) << endl;

    // 4.2 从pos位置查找s的前n个字符第一次位置
    MyString str4_3("aabaabaaf");
    char* substr4_3 = new char[]{"aafaaf"};
    int n4_3 = 3;
    int pos4_3 = 0;
    cout << "4.3 查找" << str4_3 << "起始位置为" << pos4_3 << "的子串" << substr4_3 << "的位置为：" << str4_3.find(substr4_3, pos4_3, n4_3) << endl;
}
int main(){
    // 设置控制台输出为 UTF-8
    SetConsoleOutputCP(CP_UTF8);

    testMyString();

    return 0;
}