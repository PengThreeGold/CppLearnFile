#include <iostream>
#include <vector>

using namespace std;

/*
 * iterator: 容器的迭代器
 */

int main(int argc, char *argv[])
{
    vector<int> vec;
    for (int i = 0; i < 20; ++i)
    {
        vec.push_back(rand() % 100 + 1);
    }

    // iterator: 普通的正向迭代器
    // 既可以读取也可以修改
    // 常规迭代器定义
    // vector<int>::iterator it1;
    // C++ 11 自动识别迭代器类型
    auto it1 = vec.begin();
    for (; it1 != vec.end(); ++it1)
    {
        cout << *it1 << " ";
        if (*it1 % 2 == 0)
        {
            *it1 = 0;
        }
    }
    cout << endl;

    for (int v : vec)
    {
        cout << v << " ";
    }
    cout << endl;

    // const_iterator: 常量的正向迭代器
    // 可以读取但不可以修改
    vector<int>::const_iterator it = vec.begin();
    /* 思考：如上所示左值为常量迭代器，右值为普通迭代器
     * 为什么可以进行赋值？
     * 根据容器类的定义设计可知：
     * class const_iterator
     * {
     * public：
     *     // 返回的元素的常引用（不可被赋值）
     *     const T& operator*(){return *_ptr;}
     * }; // 基类
     * class iterator : public const_iterator
     * {
     * public：
     *     // 返回的元素的引用（可被赋值）
     *     T& operator*(){return *_ptr;}
     * }; // 派生类
     * 基类类型可以接收派生类定义的对象
     */

    // reverse_iterator:反向迭代器
    // rbegin(): 返回的是最后一个元素的反向迭代器表示
    // rend(): 返回的是首元素前驱位置的反向迭代器表示
    // vector<int>::reverse_iterator rit;
    auto rit1 = vec.rbegin();
    for (; rit1 != vec.rend(); ++rit1)
    {
        cout << *rit1 << " ";
    }
    cout << endl;

    // 常量的反向迭代器
    // 可以读取但不可以修改
    vector<int>::const_reverse_iterator rit = vec.rbegin();

    return 0;
}