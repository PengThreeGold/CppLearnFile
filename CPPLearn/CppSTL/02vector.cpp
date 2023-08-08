#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

/********* vector 向量简洁 *********/

/*
 * 1、vector 容器基本概念
 * vector的数据安排及操作方式，与array非常相似，两者的唯一差别在于空间运用灵活性
 *
 * array是静态空间，一旦配置了一般不能改变，如果要改变空间大小，需要自行完成以下三个步骤：
 * a: 配置一块新的空间
 * b: 旧数据搬往新的空间
 * c: 释放原来的空间
 *
 * 而vector是动态空间，但其实vector的动态也是对于上述过程的封装，
 * 并且vector配置空间的策略也考虑了运行成本，采用特定的扩展的策略（不是简单的成倍扩展）。
 */

/*
 * 2、vector 迭代器
 * vector维护一个线性空间，所以不论元素类型如何，普通指针都可以作为vector的迭代器
 * 因为vector迭代器所需要的行为（常用指针操作行为）普通指针天生具备，
 * 而且vector指针支持随机存取，而普通指针正有着这样的能力。
 * 所以，vector提供的是随机访问迭代器，其内部是用普通指针实现的。
 *
 * 注意：判断迭代器是否能随机访问的方法
 * iterator++; iterator--;  // 通过编译至少是双向迭代器
 * iterator = iterator + 1; // 通过编译则是随机访问迭代器
 */

void exa1()
{
    vector<int> v = {1, 2, 3, 4, 5};

    // 使用迭代器进行正序遍历
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it;
    }
    cout << endl;

    // 使用迭代器进行逆序遍历
    for (vector<int>::reverse_iterator rit = v.rbegin(); rit != v.rend(); rit++)
    {
        cout << *rit;
    }
    cout << endl;
}

/*
 * 3、vector 数据结构
 * vector 采用的数据结构非常简单，线性连续空间，动态开辟的数组，每次以原来空间大小的2倍进行扩容。
 * 它以两个迭代器_Myfirst和_Mylast分别指向配置得来的连续空间中已被使用的范围，
 * 并以迭代器Myend指向整块连续内存空间的尾端。
 *
 * 容量：
 * 为了降低空间配置时的成本，vector 实际配置的大小可能比用户端需求大一些，
 * 以备将来可能的扩充，这便是容量的概念
 * 一个vector容器的容量永远大于等于其大小，一旦容量等于大小，
 * 便是满载，下次再有新增元素，整个vector容器就得另觅居所。
 *
 * 动态增加大小：
 * 所谓动态增加大小，并不是在原空间之后续接新空间（因为无法保证原空间之后尚有可配置的空间），
 * 而是开辟一块更大的内存空间，然后将原数据拷贝到新空间，并释放原空间。
 *
 * 注意：对vector的任何操作，一旦引起空间的重新配置，指向原vector的所有迭代器就都失效了。
 */

/********* vector 常用API操作 *********/

/*
 * 1、vector 构造函数
 *
 * vector<T> v; // 采用模版类实现，默认构造函数
 * vector<T> v(T* v1.begin(), T* v1.end()); // 将v1[begin(), end())区间中的元素拷贝给本身
 * vector<T> v(int n, T elem); // 将n个elem拷贝给本身
 * vector<T> v(const vector<T> v1); // 拷贝构造函数
 */

void exa2()
{
    // 默认构造函数
    vector<int> v1;
    // 序列地址构造
    vector<int> v2(v1.begin(), v1.end());
    vector<int> v3 = {1, 2, 3, 4, 5};
    int array[5] = {1, 2, 3, 4, 5};
    vector<int> v4(array, array + sizeof(array) / sizeof(int));
    // 指定元素构造
    vector<int> v5(5, 0);
    // 拷贝构造
    vector<int> v6(v4);
    vector<int> v7 = v6;
}

/*
 * 2、vector 常用赋值操作
 *
 * 由于 vector 采用模板类实现，其完整的函数声明会稍显复杂，
 * 下面方法的演示会省略类型界定。
 *
 * assign(beg, end); // 将[beg, end)区间中的数据拷贝复制给本身
 * assign(n, elem); // 将n个elem拷贝给本身
 * vector& operator=(const vector& vec); // 重载赋值操作符
 *
 * 赋值操作也可视为一种特殊的复制
 * swap(vec); //将vec与本身的元素互换
 *
 * 注意：巧用swap来收缩空间
 * vector<int> (v).swap(v);
 * // vector<int>(v);利用拷贝构造函数初始化匿名对象
 * // swap(v);交换的本质其实只是互换指向内存的指针
 * // 匿名对象指针指向的内存会由系统自动释放
 */

void exa3()
{
    vector<int> v1 = {1, 2, 3, 4, 5};
    vector<int> v2;
    v2.assign(v1.begin(), v1.end());
    v2.assign(5, 0);
    v2 = v1;

    v2.swap(v1);
    vector<int>(v2).swap(v2);
}

/*
 * 3、vector 大小操作
 *
 * int size(); // 返回容器中的元素个数
 *
 * bool empty(); // 判断容器是否为空
 *
 * void resize(int num);
 * 重新指定容器的长度为num，若容器变长，则以默认值填充新位置。
 * 若容器变短，则末尾超出容器长度的元素被删除
 *
 * void resize(int num, T elem);
 * 重新指定容器的长度为num，若容器变长，则以elem填充新位置。
 * 若容器变短，则末尾超出容器长度的元素被删除
 *
 * int capacity(); // 返回容器的容量
 *
 * void reserve(int len);
 * 容器预留len个元素长度，预留位置不初始化，元素不可访问
 */

void exa4()
{
    vector<int> v1;
    v1.assign(5, 0);
    for_each(v1.begin(), v1.end(), [=](int x)
             { cout << x << " "; });
    cout << endl;
    cout << "size of v1 : " << v1.size() << endl;
    cout << "empty of v1 : " << v1.empty() << endl;
    // v1.resize(10);
    v1.resize(10, 1);
    cout << "capacity of v1 : " << v1.capacity() << endl;
    v1.reserve(100);
}

/*
 * 4、vector 数据存取操作
 *
 * T& at(int idx); // 返回索引idx所指的数据，如果idx越界，抛出out_of_range异常
 * T& operator[](int idx); // 返回索引idx所指的数据，如果idx越界，运行直接报错

 * T& front(); // 返回首元素的引用
 * T& back(); // 返回尾元素的引用
 */

void exa5()
{
    vector<int> v1;
    v1 = {1, 2, 3, 4, 5, 6};
    cout << v1.at(0) << endl;
    cout << v1[0] << endl;
    cout << v1.front() << endl;
    cout << v1.back() << endl;
}

/*
 * 5、vector 插入和删除操作
 *
 * insert(const_iterator pos, T elem); // 在pos位置处插入元素elem
 * insert(const_iterator pos, int n, T elem); // 在pos位置插入n个元素elem
 * insert(pos, beg, end); // 将[beg, end)区间内的元素插到位置pos
 * push_back(T elem); // 尾部插入元素elem
 * pop_back(); // 删除最后一个元素

 * erase(const_iterator start, const_iterator end); // 删除区间[start, end)内的元素
 * erase(const_iterator pos); // 删除位置pos的元素

 * clear(); // 删除容器中的所有元素 *
*/

void exa6()
{
    vector<int> v1 = {1, 2, 3, 4, 5, 6, 7, 8};

    vector<int>::iterator it = v1.begin();
    it += v1.size();
    v1.insert(it, 0);
    for_each(v1.begin(), v1.end(), [=](int x)
             { cout << x << " "; });
    cout << endl;

    v1.insert(v1.end(), 3, 0);
    for_each(v1.begin(), v1.end(), [=](int x)
             { cout << x << " "; });
    cout << endl;

    v1.push_back(0);
    for_each(v1.begin(), v1.end(), [=](int x)
             { cout << x << " "; });
    cout << endl;

    v1.pop_back();
    for_each(v1.begin(), v1.end(), [=](int x)
             { cout << x << " "; });
    cout << endl;

    v1.erase(v1.begin(), ++v1.begin());
    for_each(v1.begin(), v1.end(), [=](int x)
             { cout << x << " "; });
    cout << endl;

    v1.erase(--v1.end());
    for_each(v1.begin(), v1.end(), [=](int x)
             { cout << x << " "; });
    cout << endl;
}

int main(int argc, char *argv[])
{
#include <random>
    srand((unsigned)time(NULL));

    vector<int> vec;
    vec.reserve(20); // 给容器预留空间。只开辟不添加元素。
    vec.resize(20);  // 给容器开辟指定空间并添加元素（初始化为0）。

    for (int i = 0; i < 20; ++i)
    {
        vec.push_back(rand() % 100 + 1);
    }

#if 0
    // vector 的 operator[] 运算符重载函数
    int size = vec.size();
    for (int i = 0; i < size; ++i)
    {
        cout << vec[i] << " ";
    }
    cout << endl;

    // 把 vec 容器中的所有的偶数都删除
    auto it2 = vec.begin();
    while (it2 != vec.end())
    {
        if (*it2 % 2 == 0)
        {
            // 删除并更新迭代器
            it2 = vec.erase(it2);
        }
        else
        {
            ++it2;
        }
    }

    // 使用迭代器
    auto it1 = vec.begin();
    for (; it1 != vec.end(); ++it1)
    {
        cout << *it1 << " ";
    }
    cout << endl;

    // 给 vector 容器中所有的奇数前面都添加一个小于奇数1的偶数
    for (it1 = vec.begin(); it1 != vec.end(); ++it1)
    {
        if (*it1 % 2 != 0)
        {
            it1 = vec.insert(it1, *it1 - 1);
            it1++;
        }
    }

    for (it1 = vec.begin(); it1 != vec.end(); ++it1)
    {
        cout << *it1 << " ";
    }
    cout << endl;
#endif
    return 0;
}