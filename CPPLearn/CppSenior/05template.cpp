#include <iostream>
using namespace std;

/*
 * C++ 模版
 * 模版是创建泛型类或函数的蓝图或公式。
 * 模版是泛型编程的基础，泛型编程即以一种独立于任何特定类型的方式编写代码。
 * 库容器、比如迭代器和算法，都是泛型编程的例子，他们都是用了模版的概念。
 */

/*
 * 1、C++ 中 typename 和 calss 的区别
 *
 * typename 起源：
 * 最初定义模版的方法为：template <class T> .....
 * 这里的 class 关键字表明 T 是一个类型，后来为了避免 class 在这两个地方的使用可能给人带来混淆，
 * 所以引入了 typename 这个关键字，他的作用同 class 一样表明后面的符号位一个类型，
 * 这样在定义模版的时候就可以使用下面的方式了：template <typename T> .....
 * 在模版定义语法中，关键字 class 和 typename 的作用完全一样。
 *
 * 2、typename 的另一个作用：使用嵌套依赖类型（nested depended name）
 * class MyArray
 * {
 * public:
 *     typedef int LengthType;
 * }
 * 
 * template <class T>
 * void MyMethod(T myarr)
 * {
 *     typedef typename T::LengthType LengthType; 
 *     LengthType length = myarr.length();
 * }
 * 
 * 这个时候 typename 的作用就是告诉 C++ 编译器，typename 后面的字符串为一个类型名称，
 * 而不是成员函数或者成员变量，这个时候如果前面没有 typename ，
 * 编译器没有任何办法知道 T::LengthType 是一个类型或是一个成员名称（静态数据成员或者静态函数），
 * 所以编译会无法通过。
 * 
 * 3、代码分离：即 template class 的声明、定义、以及 main 函数分属不同文件。
 * 需要 main 文件中同时包含 其声明所在文件 以及 定义所在文件。
 */
/*
 * 函数模版
 * 定义形式：
 * template <typename type> ret-type func-name(parameter list)
 * {
 *      //函数主体
 * }
 * 其中 type 是函数所使用的数据类型的占位符名称，这个名称可以在函数定义中使用。
 */

template <typename T>
inline T const &Max(T const &a, T const &b)
{
    return a < b ? b : a;
}

void exa1()
{
    int i = 39;
    int j = 20;
    cout << "Max(i, j): " << Max(i, j) << endl;

    double f1 = 13.5;
    double f2 = 20.7;
    cout << "Max(f1, f2): " << Max(f1, f2) << endl;

    string s1 = "Hello";
    string s2 = "World";
    cout << "Max(s1, s2): " << Max(s1, s2) << endl;
}

/*
 * 类模版
 * 定义形式：
 * template <class type> class class-name{}
 * 其中type是占位符类型名称，可以在类被实例化的时候进行指定。
 * 可以使用一个逗号分隔的列表来定义多个泛型数据类型。
 */

// 下面的实力定义了类Stack<>，并实现了泛型方法来对元素进行入栈出栈操作
#include <vector>
#include <cstdlib>
#include <string>
#include <stdexcept>

template <class T>
class Stack
{
private:
    vector<T> elems; // 元素

public:
    void push(T const &); // 入栈
    void pop();           // 出栈
    T top() const;        // 返回栈顶元素
    bool empty() const    // 如果为空则返回值
    {
        return elems.empty();
    }
};

template <class T>
void Stack<T>::push(T const &elem)
{
    elems.push_back(elem); // 追加传入元素的副本
}

template <class T>
void Stack<T>::pop()
{
    if (elems.empty())
    {
        throw out_of_range("Stack<>::pop():empty stack");
    }
    elems.pop_back(); // 删除最后一个元素
}

template <class T>
T Stack<T>::top() const
{
    if (elems.empty())
    {
        throw out_of_range("Stack<>::top():empty stack");
    }
    elems.back(); // 返回最后一个元素的副本
}

int exa2()
{
    try
    {
        Stack<int> intStack; // int 类型的栈
        Stack<string> stringStack; // string 类型的栈

        // 操作 int 类型的栈
        intStack.push(7);
        cout << intStack.top() << endl;

        // 操作 string 类型的栈
        stringStack.push("hello");
        cout << stringStack.top() << endl;
        stringStack.pop();
        stringStack.pop();
    }
    catch (exception const&exc)
    {
        cerr << "Exception: " << exc.what() << endl;
        return -1;
    }
}
