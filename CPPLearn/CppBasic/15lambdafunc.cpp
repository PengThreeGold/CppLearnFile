#include <iostream>
#include <vector>

using namespace std;

/*
 * Lambda 函数与表达式
 * 语法定义: [capture](parameters)mutable ->return-type{statement}
 * 结构解释:
 * [capture] : 捕捉列表。捕捉列表总是出现在lambda表达式的开始处。
 * 事实上，[]是lambda引出符。编译器根据引出符判断接下来的代码是否是lambda函数。
 * 捕捉列表能够捕捉上下文中的变量提供给lambda函数使用。
 * (parameters) : 参数列表。与普通的函数参数列表一致，不需使用可连同()省略。
 * mutable : 修饰符。默认情况下，lambda函数总是一个const函数，mutable可以取消其常量性。在使用修饰符时，参数列表不可省略（及时参数为空）。
 * ->return——type : 返回类型。用追踪返回类型形式声明函数的返回类型。出于方便不需要使用返回值的时候可以连同->符号一起省略。
 * 此外在返回类型明确的情况下，还可以使用所有捕获的常量。
 * {statement} : 函数体。内容与普通函数一样，不过除了可以使用参数之外，还可以使用所有捕获的变量。
 *
 * 最简单的表达式：[]{};
 */

/*
 * []：默认不捕获任何变量；
 * [=]：默认以值捕获所有变量；
 * [&]：默认以引用捕获所有变量；
 * [x]：仅以值捕获x，其它变量不捕获；
 * [&x]：仅以引用捕获x，其它变量不捕获；
 * [=, &x]：默认以值捕获所有变量，但是x是例外，通过引用捕获；
 * [&, x]：默认以引用捕获所有变量，但是x是例外，通过值捕获；
 * [this]：通过引用捕获当前对象（其实是复制指针）；
 * [*this]：通过传值方式捕获当前对象；
 */

// 拷贝捕获
void exa1()
{
    int i = 1024;
    // 什么也不捕获（故意不用Lambda函数外部的变量）
    // auto func = []
    // { cout << i; };
    // func(); // 结果报错，因为未指定默认捕获模式

    // 正确方式如下
    auto func = [=]
    { cout << i; }; // 表明将外部的所有变量拷贝一到该Lambda函数内部
    func();
}

// 引用捕获
void exa2()
{
    int i = 1024;
    cout << &i << endl;
    auto func = [&]
    { cout << &i << endl; };
    func();
}

// 复制并引用捕获
void exa3()
{
    int i = 1024, j = 2048;

    cout << "address of i : " << &i << endl;
    cout << "address of j : " << &j << endl;

    auto func = [=, &i]
    {
        cout << "address of i : " << &i << endl;
        cout << "address of j : " << &j << endl;
    };

    func();
}

// 指定引用或复制
void exa4()
{
    int i = 1024, j = 2048;

    cout << "address of i : " << &i << endl;

    auto func = [i]
    {
        // i 被值捕获
        cout << "address of i : " << &i << endl;
        // j 未被捕获
    };

    func();
}

// 捕获this指针
class Test
{
public:
    void hello() { cout << "test hello!" << endl; };
    void lambda(){
        auto func = [this] // 这里捕获了 this 指针
        {
            this->hello(); // 这里 this 调用的就是 class Test 的对象了
        };

        func();
    }
};

void exa5()
{
    Test t;
    t.lambda();
}

int main(int argc, char *argv[])
{
    exa5();
    return 0;
}