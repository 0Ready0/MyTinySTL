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
    // 使用char*的前n个字符进行初始化
    MyString(const char* str, int n);
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
    MyString& operator+=(const char* s);
    // 将char 字符与当前字符串拼接
    MyString& operator+=(const char ch);
    // 将Mystring 类型字符串与当前字符串拼接
    MyString& operator+=(const MyString& str);

    // 将char*类型字符串与当前字符串拼接
    MyString& operator+(const char* s);
    // 将char 字符与当前字符串拼接
    MyString& operator+(const char ch);
    // 将Mystring 类型字符串与当前字符串拼接
    MyString& operator+(const MyString& str);

    // 将char*类型字符串与当前字符串拼接
    MyString& append(const char* s);
    // 将char*类型字符串的前n个字符连接到当前字符串结尾
    MyString& append(const char* s, int n);
    // 将Mystring 类型字符串与当前字符串拼接
    MyString& append(const MyString& str);
    // 将Mystring类型字符串从pos开始的n个字符连接到字符串结尾
    MyString& append(const MyString& str, int pos, int n);


    // 查找 - 模式匹配
    // KMP算法
    int KMP(const MyString& str, int pos = 0) const;
    // KMP算法, 从右侧开始
    int RKMP(const MyString& str, int epos = 0) const;
    // 获取前缀数组
    void getPrefix(const MyString& str, int* prefix)const;
    // 获取前缀数组, 从右侧开始
    void getRPrefix(const MyString& str, int prefix[])const;
    // 查找str第一次出现位置，从pos开始查找
    int find(const MyString& str, int pos = 0) const;
    // 查找s第一次出现位置，从pos开始查找
    int find(const char* s, int pos = 0) const;
    // 从pos位置查找s的前n个字符第一次位置
    int find(const char* s, int pos, int n) const;
    // 查找字符c第一次出现位置
    int find(const char ch, int pos = 0) const;
    // 查找str最后一次位置，从pos开始查找
    int rfind(const MyString& str, int pos) const;
    // 查找s最后一次出现位置，从pos开始查找
    int rfind(const char* s, int pos) const;
    //从pos查找s的前n个字符最后一次位置
    int rfind(const char* s, int pos, int n) const;
    // 查找字符c最后一次出现位置
    int rfind(const char ch, int pos = 0) const;

    // 翻转
    MyString reverse();

    // 替换
    // 替换从pos开始n个字符为字符串str
    MyString& replace(int pos, int n, const MyString& str); 
    // 替换从pos开始的n个字符为字符串s
    MyString& replace(int pos, int n, const char* s); 

    // 比较
    // 与字符串str比较
    int compare(const MyString &str) const; 
    //与字符串str比较
    int compare(const char *str) const; 

    // 字符存取
    // 通过[]方式取字符
    char& operator[](int n); 
    // 用于 const MyString对象通过[]方式取字符
    const char& operator[](int n) const;
    // 通过at方法获取字符
    char& at(int n); 
    // 用于 const MyString对象通过at方法获取字符
    const char& at(int n) const;

    // 插入和删除
    // 插入字符串
    MyString& insert(int pos, const char* str); 
    // 插入字符串
    MyString& insert(int pos, const MyString& str);
    // 在指定位置插入n个字符c 
    MyString& insert(int pos, int n, char ch);
    // 删除从pos开始的n个字符 
    MyString& erase(int pos, int n); 

    // 子串
    // 返回由pos开始的n个字符组成的字符串
    MyString substr(int pos, int n) const; 
    // 析构函数
    ~MyString();
};



#endif