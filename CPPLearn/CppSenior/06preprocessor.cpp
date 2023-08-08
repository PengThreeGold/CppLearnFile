#include <iostream>
using namespace std;

/*
 * 预处理器是一些指令，指示编译器在实际编译之前所需完成的预处理。
 * 所有的预处理器指令都是 # 开头，只有空格字符可以出现在预处理器之前。
 * 预处理器不是 C++ 语句，所以它们不会以分号（;）结尾。
 */

/*
 * #define 预处理
 * 1、用于创建符号常量。该符号变量通常称为宏，指令的一般形式是：#define macro-name replacement-text
 * 2、参数宏，例如：#define MIN(a, b) (a<b?a:b)
 */
#define MIN(a, b) (a < b ? a : b)

void exa1()
{
    int i, j;
    i = 100;
    j = 30;
    cout << "The min is : " << MIN(i, j) << endl;
}

/* 条件编译
 * 有几个指令可以用来有选择地对部分程序源代码进行编译，这个过程被称为条件编译。
 * 例如：
 * #ifdef NULL
 *     #define NULL 0
 * #endif
 *
 */

void exa2()
{
    int i, j;
    i = 100;
    j = 30;
#ifdef DEBUG
    cerr << "Trace: Inside Function" << endl;
#endif

#if 0
    // 这是注释部分
    cout << MKSTR(HELLO C++) << endl;
#endif

    cout << "The min is : " << MIN(i, j) << endl;

#ifdef DEBUG
    cerr << "Trace: Coming Out Of Function" << endl;
#endif
}

/*
 * # 和 ## 运算符
 * # 和 ## 预处理运算符在 C++ 和 ANSI/ISO C 中都是可用的
 * # 运算符会把 replacement-text 令牌转换为引号引起来的字符串
 * ## 运算符用于连接两个令牌
 */

#define MKSTR(x) #x
#define CONCAT(x, y) x##y

void exa3()
{
    cout << MKSTR(HELLO C++) << endl;

    int xy = 100;
    cout << CONCAT(x, y) << endl;
}

/*
 * C++ 中的预定义宏
 * __LINE__ 这会在程序编译时包含当前行号
 * ——FILE__ 这会在程序编译时包含当前文件名
 * __DATE__ 这会包含一个形式为 month/day/year 的字符串，它表示把源文件转换为目标代码的日期。
 * __TIME__ 	这会包含一个形式为 hour:minute:second 的字符串，它表示程序被编译的时间。
 */

void exa4()
{
    cout << "value of __LINE__ : " << __LINE__ << endl;
    cout << "Value of __FILE__ : " << __FILE__ << endl;
    cout << "Value of __DATE__ : " << __DATE__ << endl;
    cout << "Value of __TIME__ : " << __TIME__ << endl;
}