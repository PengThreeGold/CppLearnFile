#include <iostream>
using namespace std;
/*
 * 异常处理
 * 异常是程序在执行期间产生的问题。
 * C++异常是指程序运行时发生的特殊情况，例如除以零的操作等。
 * 异常提供了一种转移程序控制权的方式。
 * C++异常处理涉及到三个关键字：try, catch, throw。
 *
 * throw: 当问题出现时，程序会抛出一个异常，这是通过使用throw关键字完成的。
 * catch: 当您想要处理问题的地方，通过异常处理程序捕获异常，catch关键字用于捕获异常。
 * try  : try块中的代码标识将被激活的特定异常。它后面通常跟着一个或多个catch块。
 *
 * 如果一个块抛出一个异常，捕获异常的方法会使用try和catch关键字。
 * try块中放置可能抛出异常的代码，try块中的代码被称为保护代码。
 */

// 抛出异常
// 可以使用throw语句在代码块中的任何地方抛出异常。
// throw语句的操作数可以是任意的表达式，表达式的结果的类型决定了抛出的异常类型。
double division(int a, int b)
{
    if (b == 0)
    {
        throw "Division by zero condition!";
    }
    return (a / b);
}

// 捕获异常
// catch块在try块后面，用于捕获异常。可以指定想要捕捉的异常类型，
// 这是由catch关键字后的括号内的异常声明决定的
void exa1()
{
    int x = 50;
    int y = 0;
    double z = 0;

    try
    {
        z = division(x, y);
    }
    // 由于抛出了一个类型为const char*的异常
    // 因此捕获时我们必须在catch块中使用const char*
    catch (const char *msg)
    {
        cerr << msg << endl;
    }
}

// C++标准的异常
// C++提供了一系列标准的异常，定义在<exception>中。
// 可以再程序中使用这些标准的异常。
// 他们是以父子类层次结构组织起来的。

// 定义新的异常
// 可以通过继承和重载exception类来定义新的异常。
// 下面的实例演示了如何使用std::exception类来实现自己的异常。
#include <exception>
struct MyException:public exception
{
    const char * what () const throw()
    {
        return "C++ Exception";
    }
};

int main()
{
    try
    {
        throw MyException();
    }
    catch(MyException& e)
    {
        std::cout << "MyException caught" << std::endl;
        std::cout << e.what() << std::endl;
    }
    catch(std::exception& e)
    {
        // 其他的错误
    }
}