#include <iostream>
#include <string>

using namespace std;

/*
 * string 容器基本概念
 * C风格字符串（以\0结尾的字符数组）太过复杂，难于掌握，不适合大型程序的开发，
 * 所以C++STL中定义了一种string类。在头文件<string>中。
 *
 * string 与 C风格字符串对比
 * 1、char* 是一个指针，string是一个类。
 * string封装了char*，管理这个字符串，是一个char*型的容器。
 *
 * 2、string封装了很多实用的成员方法。
 * 查找find、拷贝copy、删除erase、替换replace、插入insert……
 *
 * 3、不用考虑内存释放和越界。
 * string管理char*所分配的内存，每一次string的复制/赋值、取值都由string类负责维护，
 * 不用担心复制越界或取值越界等。
 */
int main(int argc, char **argv)
{
    /* ---------- string 容器常用操作 ---------*/

    // 1、string 构造函数

    // string();
    // 默认构造函数，创建一个空的字符串
    string s1 = string();

    // string(const string& str);
    // 拷贝构造函数，使用一个string对象初始化另一个string对象
    string s2 = string(s1);

    // string(const char* s);
    // 含参构造函数，使用C风格字符串初始化
    char *s = "123";
    string s3 = string(s);

    // string(int n, char c);
    // p含参构造函数，使用n个字符c初始化
    char c = 'a';
    string s4 = string(4, c);

    // 2、string 基本赋值操作

    // （1）= 赋值操作符

    // string& operator=(const char* s);
    // C风格字符串赋值给当前的字符串
    string str1;
    char *s = "123";
    str1 = s;

    // string& operator=(const string& s);
    // 把字符串s赋给当前的字符串
    string str2;
    str1 = str2;

    // string& operator=(const char c);
    // 字符赋值给当前的字符串
    char c = '1';
    str1 = c;

    // assign 成员函数

    // string& assign(const char* s);
    // C风格字符串赋值给当前的字符串
    string str1;
    char *s = "1234";
    str1.assign(s);

    // string& assign(const char* s, int n);
    // 把C风格字符串s的前n个字符赋给当前的字符串
    str1.assign(s, 2);

    // string& assign(const string& s);
    // 把字符串s赋给当前字符串
    string str2 = "1234567";
    str1.assign(str2);

    // string& assign(int n, char c);
    // 把n个字符c赋给当前的字符串
    char c = '1';
    str1.assign(10, c);

    // string& assign(const string& s, int start, int n);
    // 将字符串s中从start开始的n个字符赋值给当前字符串
    str1.assign(str2, 1, 2);

    // 3、string 存取字符操作

    // [] 下标获取操作符
    cout << str1[1] << endl;

    // at 成员函数
    cout << str1.at(1) << endl;
    // 使用at方法获取字符时，如果下标越界，at方法内部会抛出异常
    try
    {
        // 使用[100]不会抛出异常，程序会直接终止
        str1.at(100);
    }
    catch (out_of_range &e) // 也可以直接使用多态特性 exception& e
    {
        cerr << e.what() << endl;
    }

    // 4、string 拼接操作

    // += 复合操作符（同上述 + 操作符）

    // append 成员函数

    // string& append(const char* s);
    // 把C风格字符数组s连接到当前字符串结尾
    string str1 = "1234";
    char *s = "000";
    str1.append(s);

    // string& append(const char* s, int n);
    // 把C风格字符数组s的前n个字符连接到当前字符串结尾
    str1.append(s, 1);

    // string& append(const string &s);
    // 将字符串s追加到当前字符串末尾
    string str2 = "000";
    str1.append(str2);

    // string& append(const string& s, int pos, int n);
    // 把字符串s中从pos开始的n个字符连接到当前字符串结尾
    str1.append(str2, 1, 2);

    // string& append(int n, char c);
    // 在当前字符串结尾添加n个字符c
    char c = '0';
    str1.append(3, c);

    // 5、string 查找和替换

    // find 成员函数

    // int find(const string& str, int pos = 0) const;
    // 查找str在当前字符串中第一次出现的位置，从pos开始查找，pos默认为0
    str1.find("1", 0);

    // int find(const char* s, int pos = 0) const;
    // 查找C风格字符串s在当前字符串中第一次出现的位置，从pos开始查找，pos默认为0
    char *s = "12";
    str1.find(s);

    // int find(const char* s, int pos, int n) const;
    // 从pos位置查找s的前n个字符在当前字符串中第一次出现的位置
    str1.find(s, 0, 2);

    // int find(const char c, int pos = 0) const;
    // 查找字符c第一次出现的位置，从pos开始查找，pos默认为0
    char c = '1';
    str1.find(c, 1);

    // 当查找失败时，find方法会返回-1，-1已经被封装为string的静态成员变量 string::npos
    // static const size_t nops = =1;

    // rfind 成员函数（使用如上）

    // int rfind(const string& str, int pos = npos) const;
    // 从pos开始向左查找最后一次出现的位置，pos默认为npos
    // int rfind(const char* s, int pos = npos) const;
    // 查找s最后一次出现的位置，从pos开始向左查找，pos默认为npos
    // int rfind(const char* s, int pos, int n) const;
    // 从pos开始向左查找s的前n个字符最后一次出现的位置
    // int rfind(const char c, int pos = npos) const;
    // 查找字符c最后一次出现的位置

    /*
     * find方法通常查找字串第一次出现的位置，
     * 而rfind方法通常查找字串最后一次出现的位置。
     * rfind(str, pos)的实际的开始位置是pos + str.size()，
     * 即从该位置开始（不包括该位置字符）向前寻找匹配项，
     * 如果有则返回字符串位置，如果没有返回string::npos。
     * -1其实是size_t类的最大值（学过补码的同学应该不难理解），
     * 所以string::npos还可以表示“直到字符串结束”，
     * 这样的话rfind中pos的默认参数是不是就不难理解啦？
     */

    // replace 成员函数

    // string& replace(int pos, int n, const string& str);
    // 替换从pos开始n个字符为字符串s
    string str1 = "0123456";
    str1.replace(0, 2, "12");

    // string& replace(int pos, int n, const char* s);
    // 替换从pos开始的n个字符为字符串s
    char *s = "00";
    str1.replace(0, 4, s);

    // 6、string比较操作

    // compare 成员函数

    // int compare(const string& s) const;
    // 与字符串s比较
    string str1 = "123";
    string str2 = "456";
    str1.compare(str2);

    // int compare(const char* s) const;
    // 与C风格字符数组比较
    char *str3 = "123";
    str1.compare(str3);

    /*
     * compare函数依据字典序比较，
     * 在当前字符串比给定字符串小时返回-1，
     * 在当前字符串比给定字符串大时返回1，
     * 相等时返回0。
     */

    // 比较操作符

    // bool operator<(const string& str) const;
    // bool operator<(const char* str) const;
    // bool operator<=(const string& str) const;
    // bool operator<=(const char* str) const;
    // bool operator==(const string& str) const;
    // bool operator==(const char* str) const;
    // bool operator>(const string& str) const;
    // bool operator>(const char* str) const;
    // bool operator>=(const string& str) const;
    // bool operator>=(const char* str) const;
    // bool operator!=(const string& str) const;
    // bool operator!=(const char* str) const;

    // string 类重载了所有的比较操作符，其含义与比较操作符本身的含义相同。

    // 7、string 子串

    // substr 成员函数
    // string substr(int pos = 0, int n = npos) const;
    // 返回由pos开始的n个字符组成的字符串
    cout << str1.substr(0, 4) << endl;

    // 8、string 插入和删除操作

    // insert 成员函数

    // string& insert(int pos, const char* s);
    // 在pos位置插入C风格字符数组
    string str1 = "abcdefg";
    char *s = "01234";
    str1.insert(0, s);

    // string& insert(int pos, const string& str);
    // 在pos位置插入字符串str
    string str2 = "01234";
    str1.insert(0, str2);

    // string& insert(int pos, int n, char c);
    // 在pos位置插入n个字符c
    char c = '0';
    str1.insert(0, 5, c);

    // erase 成员函数

    // string& erase(int pos, int n = npos);
    // 删除从pos位置开始的n个字符，默认一直删除到末尾。
    str1.erase(0, 2);

    // 9、string 和 C-Style 字符串的转换

    // string 转 const char*
    string str = "test";
    const char *cstr = str.c_str();

    // const char* 转 string
    const char *cstr = "test";
    string str(cstr); // 本质上是一个有参构造

    /*
     * 在c++中存在一个从const char*到string类的隐式类型转换，
     * 但却不存在从一个string对象到const char*的自动类型转换。
     * 对于string类型的字符串，
     * 可以通过c_str()方法返回string对象对应的const char* 字符数组。
    */
    return 0;
}