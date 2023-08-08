#include <iostream>
#include <queue>
#include <set>

using namespace std;

/*
 * 函数对象 => C语言里面的函数指针
 */

// 问题：加法的实现？

// 1、常规函数实现
// int sum(int a, int b)
// {
//     return a + b;
// }

// int ret = sum(1, 2);

// 2、C ++11函数对象实现
// class Sum
// {
// public:
//     int operator()(int a, int b)
//     {
//         return a + b;
//     }
// };

// Sum sum_;
// int ret = sum_(1, 2);

// 注意：把有operator() 小括号运算符重载函数的对象，称做函数对象或称作防函数

// 问题：实现比较大小？

// 1、常规函数模版实现大于比较操作

template <typename T>
bool compare(T a, T b)
{
    return a > b;
}

// 2、使用C的函数指针解决方案

template <typename T> // 大于比较
bool _greater(T a, T b)
{
    return a > b;
}

template <typename T> // 小于比较
bool _less(T a, T b)
{
    return a < b;
}

template <typename T, typename COMPARE> // C++11库函数模版
bool compare_c11(T a, T b, COMPARE comp)
{
    return comp(a, b); // 通过函数指针调用函数
    // 通过函数指针调用函数，是无法内联的，从而有函数调用开销，导致效率很低
}

// 3、C++函数对象版本的实现
template <typename T> // 大于比较函数对象（仿函数）
class MyGreater
{
public:
    bool operator()(T a, T b)
    {
        return a > b;
    }
};

template <typename T> // 小于比较函数对象（仿函数）
class MyLess
{
public:
    bool operator()(T a, T b)
    {
        return a < b;
    }
};

// 好处分析
// 1、
// 通过函数对象调用operator()，可以省略函数的调用开销
// 比通过函数（不能够inline内联调用）效率高
// 2、
// 因为函数对象是类生成的，所以可以添加相关的成员变量
// 用来记录函数对象使用时更多的信息

int main(int argc, char *argv[])
{
    compare(10, 20);
    compare_c11(10, 20, _greater<int>);
    compare_c11(10, 20, _less<int>);
    compare_c11(10, 20, MyGreater<int>());
    compare_c11(10, 20, MyLess<int>());

    // 函数对象使用实例 1 
    // priority_queue 的底层更改
    priority_queue<int> pque; // vector 构建成默认的大根堆

    for (int i = 0; i < 10; ++i)
    {
        pque.push(rand() % 100 + 1);
    }

    while (!pque.empty())
    {
        cout << pque.top() << " ";
        pque.pop();
    }

    cout << endl;

    // 怎么修改为小根堆数据结构？

    using MinHeap = priority_queue<int, vector<int>, greater<int>>; // vector 构建成默认的大根堆

    // 函数对象使用实例 2
    // set 的底层更改

    set<int> set1; // 红黑树 默认小到大

    for (int i = 0; i < 10; ++i)
    {
        set1.insert(rand() % 100 + 1);
    }

    for (int v : set1)
    {
        cout << v << " ";
    }

    cout << endl;

    // 怎么修改为从大到小的循序呢？

    using ReverseSet = set<int, greater<int>>;

    // 思考 lambda 表达式 与函数对象的关系？
    
    return 0;
}
