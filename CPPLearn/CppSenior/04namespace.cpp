#include <iostream>
using namespace std;

/*
 * 命名空间 namespace
 * 用于解决不同库中相同名称的函数、类、变量的区分问题。
 * 使用命名空间即定义了上下文，本质上命名空间就是定义了一个范围。
 */

// 定义一个命名空间 A
namespace A
{
    int a = 100;
    namespace B // 嵌套一个命名空间 B
    {
        int a = 200;
    }
}

int a = 300; // 定义一个全局变量

int main(int argc, char **argv)
{
    cout << "A::a = " << A::a << endl;
    cout << "A::B::a =" << A::B::a << endl;
    cout << "a =" << a << endl;
    cout << "::a =" << ::a << endl;

    int a = 30;
    // 全局变量标识符 ::
    // 当存在同名的局部变量时用于区别两者
    cout << "a =" << a << endl;
    cout << "::a =" << ::a << endl;

    return 0;
}