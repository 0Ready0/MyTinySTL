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



MyString& MyString::append(const char* s){
    /**
     * @brief 将char*类型字符串与当前字符串拼接
     * @param const char* s
     * @return MyString&
     */

    *this = *this + s;
    return *this;
}

MyString& MyString::append(const char* s, int n){
    /**
     * @brief 将char*类型字符串的前n个字符连接到当前字符串结尾
     * @param const char* s
     * @param int n:前n个字符
     * @return MyString&
     */
    size_t s_len = strlen(s);
    if(s_len < 0) throw std::invalid_argument("MyString::append : str is empty string");
    if(s_len < n) throw std::invalid_argument("MyString::append : length of str should be greater than n");
    if(m_capacity < m_size + n){
        char* temp_char = new char[m_size + 1];
        std::copy(m_char, m_char + m_size, temp_char);
        delete[] m_char;
        m_capacity = n + m_size + 1;
        m_char = new char[m_capacity];
        std::copy(temp_char, temp_char + m_size, m_char);
        delete[] temp_char;
    }
    std::copy(s, s + n, m_char + m_size);
    m_size += n;
    m_char[m_size] = '\0';
    return *this;
}

MyString& MyString::append(const MyString& str){
    /**
     * @brief 将Mystring 类型字符串与当前字符串拼接
     * @param const MyString& str
     * @return MyString&
     */
    *this = *this + str;
    return *this;
}
MyString& MyString::append(const MyString& str, int pos, int n){
    /**
     * @brief 将Mystring类型字符串从pos开始的n个字符连接到字符串结尾
     * @param const MyString& str
     * @param int pos 带拼接的起始位置
     * @param int n   n个字符
     * @return MyString&
     */
    size_t str_len = str.m_size;
    if(str_len < 0) throw std::invalid_argument("MyString::append : str is empty string");
    if(str_len < n) throw std::invalid_argument("MyString::append : length of str should be greater than n");
    if(pos < 0) throw std::invalid_argument("MyString::append : pos is invalid");
    if(pos + n > str_len) n = str_len - pos;
    if(m_capacity < m_size + n){
        char* temp_char = new char[m_size + 1];
        std::copy(m_char, m_char + m_size, temp_char);
        delete[] m_char;
        m_capacity = n + m_size + 1;
        m_char = new char[m_capacity];
        std::copy(temp_char, temp_char + m_size, m_char);
        delete[] temp_char;
    }
    std::copy(str.m_char + pos, str.m_char + pos + n, m_char + m_size);
    m_size += n;
    m_char[m_size] = '\0';
    return *this;
}

// KMP算法
int MyString::KMP(const MyString& str, int pos) const {
    /**
     * @brief KMP算法实现文本串和模式串的匹配
     * @param const MyString& str 模式串
     * @param int pos 带查找的文本串的起始位置
     */
    int prefix[str.m_size] = {0};
    getPrefix(str, prefix);
    int j = pos;  // 模式串指针
    for(int i = pos + 1; i < this->m_size; ++i){
        if(j == str.m_size - 1) return i - j;
        if(this->m_char[i] != str.m_char[j]){
            j = prefix[j - 1];
        }
        else ++j;
    }
    return -1; 
}
// 获取前缀数组
void MyString::getPrefix(const MyString& str, int prefix[])const {
    /**
     * @brief 获取KMP算法的 前缀数组
     * @param const MyString& str 模式串
     * @param int* prefix 前缀数组（前缀和后缀相等的最大长度）
     */
    int j = 0;  // 前缀子串末尾 = prefix[i], 前缀数组 i位置 的值
    int i = 1;  // 后缀子串末尾
    for(; i < str.m_size; ++i){
        // 前缀末尾 和 后缀末尾 不相等
        while(j > 0 && str.m_char[j] != str.m_char[i]){   // 如果j大于0 && 前缀子串末尾 != 后缀子串末尾，则j进行回退
            j = prefix[j - 1];
        }
        // 前缀末尾 和 后缀末尾 相等
        if(str.m_char[j] == str.m_char[i]) j++;   // 如果 前缀末尾 == 后缀末尾，则j++; 
                                    // 这里仅为一个if判断，个人理解为上面的while循环已经将j调到最佳匹配位置，由于进行了前缀数组的跳转
        prefix[i] = j;
    }
}

int MyString::find(const MyString& str, int pos) const{
    /**
     * @brief  查找Mystr在文本串第一次出现位置，从pos开始查找
     * @param const Mystring& str 模式串
     * @param int pos 起始位置
     * @return int 返回查找位置，未找到返回-1
     */
    return KMP(str, pos);
}
// 查找s第一次出现位置，从pos开始查找
int MyString::find(const char* s, int pos) const{
    return -1;
}
// 从pos位置查找s的前n个字符第一次位置
int MyString::find(const char* s, int pos, int n) const{
    return -1;
}
// 查找字符c第一次出现位置
int MyString::find(const char c, int pos) const{
    return -1;
}
// 查找str最后一次位置，从pos开始查找
int MyString::rfind(const MyString& str, int pos) const{
    return -1;
}
// 查找s最后一次出现位置，从pos开始查找
int MyString::rfind(const char* s, int pos) const{
    return -1;
}
//从pos查找s的前n个字符最后一次位置
int MyString::rfind(const char* s, int pos, int n) const{
    return -1;
}
// 查找字符c最后一次出现位置
int MyString::rfind(const char c, int pos) const{
    return -1;
}

MyString::~MyString(){
    delete[] m_char;
}
