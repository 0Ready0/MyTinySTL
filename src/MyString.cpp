#include <cstring>   // 确保 strlen 等可用
#include <algorithm>
#include <stdexcept>
#include "MyString.h"

MyString::MyString(){
    m_char = new char();
    m_size = 0;
    m_capacity = m_size + 1;
    m_char[m_size] = '\0';
}

MyString::MyString(const char* str){
    m_size = std::strlen(str);
    m_capacity = m_size + 1;
    m_char = new char[m_capacity];
    std::copy(str, str + m_size, m_char);
    m_char[m_size] = '\0';
}

MyString::MyString(const MyString& other){
    m_size = other.m_size;
    m_capacity = other.m_capacity;
    m_char = new char[m_capacity];
    std::copy(other.m_char, other.m_char + m_size, m_char);
    m_char[m_size] = '\0';
}

MyString::MyString(int n, const char& ch){
    if (n < 0){     // 处理负数，抛异常
        throw std::invalid_argument("MyString : n cannot be negetive");
    }                     
    m_size = n;
    m_capacity = n + 1;                   // 包含结束符的空间
    m_char = new char[m_capacity];        // 分配 n+1 个字符
    // 将前 n 个字符填充为 ch
    for (size_t i = 0; i < n; ++i) {
        m_char[i] = ch;
    }
    m_char[n] = '\0';                     // 添加结束符
}


MyString& MyString::operator=(const MyString& str){
/**
 * @brief 用于 MyString 风格串的赋值
 * @param str MyString的类对象
 * @return MyString& 返回对象的引用
 */
    if(this != &str){
        delete[] m_char;
        m_size = str.m_size;
        m_capacity = str.m_capacity;
        m_char = new char[m_capacity];
        std::copy(str.m_char, str.m_char + m_size, m_char);
        m_char[m_size] = '\0';
    }
    return *this;
}

MyString& MyString::operator=(const char* ch){
/**
 * @brief 用于C风格字符串赋值
 * 
 * 将当前对象的内容替换为以空字符结尾的字符串 ch 的内容。
 * 如多当前容量不足，会进行重新分配内存以容纳新字符串。
 * 如果 ch 为空指针，会清空当前字符串
 * 
 * @param ch 指向以空字符串结尾的字符串指针
 * @return MyString& 返回当前对象的引用，以支持链式赋值
 * 
 * @exception std::bad_alloc 如果内存分配失败，则抛出异常，当前对象状态不变
 * 
 * @note 此函数不会检查自赋值，因为参数类型为 const char* , 不会与当前对象指向同一内存
 * 
*/
    // 处理空指针
    if(ch == nullptr){
        delete[] m_char;
        m_char = new char[1];
        m_char[0] = '\0';
        m_size = 0;
        m_capacity = m_size + 1;
    }else{
        size_t newSize = strlen(ch);
        // 如果容量不足进行扩容
        if(m_capacity <= newSize + 1){
            // 需要重新分配更大的空间
            delete[] m_char;
            m_capacity = newSize + 1;
            m_char = new char[m_capacity];
        }
        std::copy(ch, ch + newSize, m_char);
        m_size = newSize;
        m_char[m_size] = '\0';
    }
    return *this;
}

MyString& MyString::operator= (const char ch){
/**
 * @brief 用于C风格字符赋值
 * 
 * @param ch 单个char字符
 * @return MyString& 返回当前对象的引用，以支持链式赋值
 * 
*/    
    if(ch == '\0'){
        delete[] m_char;
        m_size = 0;
        m_capacity = m_size + 1;
        m_char[0] = '\0';
    }else{
        if(m_capacity < 1){
            delete m_char;
            m_capacity = 2;
            m_char = new char[2];
        }
        m_size = 1;
        m_char[0] = ch;
        m_char[m_size] = '\0';
    }
    return *this;
}

std::ostream& operator<< (ostream& out, const MyString& val){
    out << val.m_char;
    return out;
}

std::istream& operator>> (istream& in, MyString& str){
    std::string temp;
    in >> std::ws;   // 跳过前导空白
    in >> temp; // 读取输入
    if(in){
        str = temp.c_str();
    }
    return in;
}

MyString& MyString::assign(const char* str){
/**
 * @brief 将char* 类型字符串赋给字符串
 * @param str 输入C风格字符串
 * @return MyString 输出自定义类型字符串
 * 
 */
    if(str == nullptr){
        m_size = 0;
        m_capacity = m_size + 1;
        m_char = new char[m_capacity];
        m_char[m_size] = '\0';
    }else{
        int newSize = strlen(str);
        if(m_capacity < newSize){
            delete[] m_char;
            m_capacity = newSize;
            m_char = new char[m_capacity];
        }
        std::copy(str, str + newSize, m_char);
        m_size = newSize;
        m_char[m_size] = '\0';
    }
    return *this;
}

MyString& MyString::assign(const MyString& str){
    /**
     * @brief 将MyString类型字符串str赋给当前字符串
     * @param str 待赋值的MyString类型字符串
     * @return MyString& 输出MyString类型字符串
     */

    if(str.m_size == 0){
        m_size = 0;
        m_capacity = m_size + 1;
        m_char = new char[m_capacity];
        m_char[m_size] = '\0';
    }else{
        int newSize = str.m_size;
        if(m_capacity < newSize){
            delete[] m_char;
            m_capacity = newSize;
            m_char = new char[m_capacity];
        }
        m_size = newSize;
        std::copy(str.m_char, str.m_char + str.m_size, m_char);
        m_char[m_size] = '\0';
    }
    return *this;
}
MyString& MyString::assign(const char* str, int n){
    /**
     * @brief 把字符串s前n个字符赋给当前字符串
     * @param str 源MyString字符串
     * @param n   需要进行赋值的前n个字符
     * @exception 当n > 字符串长度时，只会赋值全部字符串
     * @return MyString& 输出MyString类型字符串
     * 
     */
    // 空字符串检测
    if (str == nullptr) {
        throw std::invalid_argument("MyString::assign: str is nullptr");
    }
    // 负数检测
    if(n < 0){
        throw std::invalid_argument("MyString::assign : n cannot be negetive");
    }

    size_t str_len = strlen(str);
    size_t copy_len = static_cast<size_t>(n);
    // 如果 n >= 字符串长度，复制整个字符串
    if(copy_len > str_len){
        MyString::assign(str);
    }
    // 判断空间是否充足
    if(m_capacity < n){
        delete[] m_char;
        m_capacity = n + 1;
        m_char = new char[m_capacity];
    }
    m_size = copy_len;  
    std::copy(str, str + m_size, m_char);
    m_char[m_size] = '\0';
    return *this;
}



MyString& MyString::assign(int n,char ch){
    /**
     * @brief  把n个字符c赋给当前字符串
     * @param  n：需要将字符 ch 重复的次数
     * @param  ch: 待重复的字符
     * @return MyString&: 输出MyString类型字符串
     */
    if(n <= 0){
        throw std::invalid_argument("MyString::assign : n should be positive");
    }else{
        if(m_capacity < n){
            delete[] m_char;
            m_capacity = n + 1;
            m_char = new char[m_capacity]; 
        }
        m_size = n;
        for(int i = 0; i < m_size; ++i){
            m_char[i] = ch;
        }
        m_char[m_size] = '\0';
        return *this;
    }
}

MyString& MyString::operator+(const char* s){
    /**
     * @brief 将char*字符串与当前字符串拼接
     * 
     * @param const char* s
     * @return MyString& 
     */
    size_t s_len = strlen(s);
    // 判空
    if(s_len == 0) return *this;
    // 判溢
    if(s_len + m_size >= m_capacity){
        char* temp_char = new char[m_size + 1];
        std::copy(m_char, m_char + m_size, temp_char);
        delete[] m_char;
        m_capacity = s_len + m_size + 1;
        m_char = new char[m_capacity];
        std::copy(temp_char, temp_char + m_size, m_char);
        delete[] temp_char;
    }
    std::copy(s, s + s_len, m_char + m_size);
    m_size += s_len;
    m_char[m_size] = '\0';
    return *this;
}

MyString& MyString::operator+(const char ch){
    /**
     * @brief 将char 单字符 与当前字符串拼接
     * 
     * @param const char ch
     * @return MyString& 
     */

    // 判空
    if(ch == '\0') return *this;
    // 判溢
    if(m_size + 1 >= m_capacity){
        char* temp_char = new char[m_size + 1];
        std::copy(m_char, m_char + m_size, temp_char);
        delete[] m_char;
        m_capacity = m_size + 1;
        m_char = new char[m_capacity];
        std::copy(temp_char, temp_char + m_size, m_char);
        delete[] temp_char;
    }
    m_char[m_size] = ch;
    m_size += 1;
    m_char[m_size] = '\0';
    return *this;
}

MyString& MyString::operator+(const MyString& str){
    /**
     * @brief 将char*字符串与当前字符串拼接
     * 
     * @param const MyString& str
     * @return MyString& 
     */
    size_t s_len = str.m_size;
    // 判空
    if(s_len == 0) return *this;
    // 判溢
    if(s_len + m_size >= m_capacity){
        char* temp_char = new char[m_size + 1];
        std::copy(m_char, m_char + m_size, temp_char);
        delete[] m_char;
        m_capacity = s_len + m_size + 1;
        m_char = new char[m_capacity];
        std::copy(temp_char, temp_char + m_size, m_char);
        delete[] temp_char;
    }
    std::copy(str.m_char, str.m_char + s_len, m_char + m_size);
    m_size += s_len;
    m_char[m_size] = '\0';
    return *this;
}

MyString::~MyString(){
    delete[] m_char;
}
