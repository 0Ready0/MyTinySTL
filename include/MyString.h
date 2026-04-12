#pragma once
#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>
#include <cstring> 
#include <algorithm>
#include <string>

#include "MyContainers.h"

class MyString : public MyContainers<char>{
private:
    char* m_char;
    size_t m_size;
    size_t m_capacity;

public:

    // 输入输出运算符 
    friend std::ostream& operator<< (ostream& out, const MyString& val);
    friend std::istream& operator>> (istream& in, MyString& str);

    // 默认构造函数
    MyString();
    // 从C字符串构造函数
    MyString(const char* str);
    // 拷贝构造
    MyString(const MyString& other);
    // 使用n个字符ch初始化
    MyString(int n, const char& ch);

    // 赋值运算符
    MyString& operator=(const MyString& str);
    MyString& operator=(const char* ch);
    MyString& operator= (const char ch);

    // 赋值操作
    // 将char*类型字符串赋给当前字符串
    MyString& assign(const char* str);
    // MyString类型字符串str赋给当前字符串
    MyString& assign(const MyString& str);
    //  把字符串s前n个字符赋给当前字符串
    MyString& assign(const char* str, int n);
    // 把n个字符c赋给当前字符串
    MyString& assign(int n,char ch);

    // 拼接操作
    // 将char*类型字符串与当前字符串拼接
    MyString& operator+(const char* s);
    // 将char 字符与当前字符串拼接
    MyString& operator+(const char ch);
    // 将Mystring 类型字符串与当前字符串拼接
    MyString& operator+(const MyString& str);

    // 析构函数
    ~MyString();
};



#endif