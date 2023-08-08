#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <string>
#include <list>
#include <cstdlib>
#include <ctime>

using namespace std;

/*
 * C++ STL
 * C++ STL （标准模板库）是一套功能强大的C++ 模版类，提供了通用的模板类和函数。
 * 这些模板类和函数可以实现多种流行和常用的算法和数据结构，如向量、链表、队列、栈等。
 * C++ 标准模板库的核心包括以下三个组件：
 * 容器（Containers）  ：容器是用来管理某一类对象的集合，C++ 提供了各种不同类型的容器，如deque、list、vector、map等
 * 算法（Algorithms）  ：算法作用于容器，他们提供了执行各种操作的方式。包括对容器内容执行初始化、排序、搜索和转换等操作。
 * 迭代器（Itherators）：迭代器用于遍历对象集合的元素，这些集合可能是容器，也可能是容器的子集。
 *
 * 这三个组件都带有丰富的预定义函数。
 */

// 基础实例

void display(int x)
{
    cout << " " << x;
    return;
}

void exa1()
{
    vector<int> v; // 创建容器对象 v ，元素类型为 int
    int x;
    cout << "请输入正数, 输入0结束输入: " << endl;
    cin >> x;     // 控制台输入
    while (x > 0) // 生成容器 v 中的元素
    {
        v.push_back(x); // 往容器 v 中增加一个元素
        cin >> x;
    }
    // 利用算法 max_element 计算并输出 v 中的最大元素
    cout << "Max = " << *max_element(v.begin(), v.end()) << endl;

    // 利用算法 accumulate 计算并输出容器 v 中所有元素的和
    cout << "Sum = " << accumulate(v.begin(), v.end(), 0) << endl;

    // 利用算法 sort 对容器 v 中的元素进行排序
    sort(v.begin(), v.end());

    // 利用算法 for_each() 输出排序结果
    cout << "Sorted result is : " << endl;
    for_each(v.begin(), v.end(), display);
    cout << endl;

    return;
}

// 常用容器实例

// 利用map实现一个简单的电话簿
void exa2()
{
    map<string, int> phone_book; // 创建一个map类容器，用于存放电话簿

    // 创建电话簿

    // 通过 [] 操作和关键字往容器中加入元素
    phone_book["小王"] = 123123;
    phone_book["小宋"] = 234234;
    phone_book["小李"] = 345345;

    // 输出电话簿

    cout << "电话簿的信息如下：" << endl;
    for (pair<string, int> item : phone_book)
    {
        // C++ 11 中引入的 enhanced for loop
        cout << item.first << ":" << item.second << endl; // 输出元素的姓名和电话号码
    }

    // 查询某个人的电话号码
    string name;
    cout << "请输入要查询的号码的姓名：" << endl;
    cin >> name;
    map<string, int>::const_iterator it; // 创建一个不能修改所指向的元素的迭代器
    it = phone_book.find(name);          //  查找关键字为 name 的容器元素（find()函数查找成功返回键值元素（迭代器类型），查找失败返回容器.end()元素）
    if (it == phone_book.end())          // 判断是否找到
    {
        cout << name << ": not found" << endl; // 未找到
    }
    else
    {
        cout << it->first << ": " << it->second << endl; // 找到
    }
}

// 使用list和iterator求解约瑟夫问题
void exa3()
{
    int key, numbers;
    // key 用于存储要报的数，numbers 用于存储人个数
    cout << "请输入人数：";
    cin >> numbers;
    cout << "请输入要报的数：";
    cin >> key;
    cout << "将人（编号）添加进列表：";
    // 构建圈子
    list<int> children;               // children 是用于存储人编号的容器
    for (int i = 0; i < numbers; ++i) // 循环创建容器元素
    {
        children.push_back(i); // 把 i （人的编号）从容器尾部放入容器
        cout << i << " ";
    }
    cout << endl;
    // 开始报数
    list<int>::iterator current; // current 为指向容器元素的迭代器
    current = children.begin();  // current 初始化成指向容器的第一个元素
    cout << "约瑟夫游戏开始 !!!" << endl;
    int rounds = 0; // 轮次
    while (children.size() > 1)
    {
        for (int count = 1; count < key; ++count) // 报数，循环 m-1 次
        {
            current++; // current 指向下一个元素

            // 如果 current 指向的是容器末尾，current 指向第一个元素
            if (current == children.end())
            {
                current = children.begin();
            }
        }

        rounds++; // 轮次递增
        // 循环结束时，current 指向将要离开圈子的人
        cout << "第" << rounds << "轮，移除：" << *current << endl;
        cout << "当前存在人（序号）有：" << endl;
        for (list<int>::iterator it = children.begin(); it != children.end(); ++it)
        {
            // 输出当前容器剩余人（序号）
            cout << *it;
        }
        cout << endl;
        current = children.erase(current); // 人离开圈子，current 指向下一个元素
        if (current == children.end())     // 如果 current 指向的是容器末尾，current 指向第一个元素
        {
            current = children.begin();
        }
    } // 循环结束时，current 指向容器中剩下的唯一的一个元素（胜利者）
    cout << "胜利者是：" << *current << endl;
}

// 常用算法实例

// 统计算法count_if
bool func(int x) { return x > 0; }

void exa4()
{
    vector<int> v;
    for (int i = 0; i < 10; ++i)
    {
        v.push_back(i);
    }

    // 统计容器v中正数的个数
    cout << count_if(v.begin(), v.end(), func) << endl;
}

// 实现排序算法的正序与逆序
bool greater2(int x1, int x2) { return x1 < x2; }

void exa5()
{
    vector<int> v;
    // 设置随机种子
    srand((unsigned)time(NULL));
    // 将随机数填充到容器中
    for (int i = 0; i < 10; ++i)
        v.push_back(rand());

    for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
        cout << *it << " ";

    cout << endl;
    // 正序
    sort(v.begin(), v.end());
    for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
        cout << *it << " ";

    cout << endl;
    // 逆序
    // sort(v.begin(), v.end(), greater2);
}

// 算法自定义操作

// 一元操作

void display_(int x) { cout << " " << x; }

void exa6()
{
    vector<int> v;
    for (int i = 0; i < 10; ++i)
        v.push_back(i);

    for_each(v.begin(), v.end(), display);
    cout << endl;
}

// 二元操作

int mp(int partial, int x) { return partial * x; }

int add_mp(int partial, int x) { return partial + x * x; }

double bottom(double partial, int x) { return partial + 1.0 / x; }

void exa7()
{
    // 初始化容器
    vector<int> v;
    for (int i = 1; i < 5; ++i)
    {
        v.push_back(i);
    }
    for_each(v.begin(), v.end(), display);
    cout << endl;
    // 所有元素的和
    cout << "所有元素的和：";
    int sum = accumulate(v.begin(), v.end(), 0);
    cout << sum << endl;

    // 所有元素的乘积
    cout << "所有元素的乘积：";
    int product = accumulate(v.begin(), v.end(), 1, mp);
    cout << product << endl;

    // 所有元素的平方和
    cout << "所有平方和：";
    int sum_sq = accumulate(v.begin(), v.end(), 0, add_mp);
    cout << sum_sq << endl;

    // 元素的倒数和
    cout << "所有倒数和：";
    double sum_rec = accumulate(v.begin(), v.end(), 0.0, bottom);
    cout << sum_rec << endl;
}

// 对元素进行 变换/映射 算法

int power_(int x) { return x * x; }

int add_(int x1, int x2) { return x1 + x2; }

void exa8()
{
    // 初始化容器
    vector<int> v1, v2, v3, v4;

    // 往各容器中填充数据或初始化
    for (int i = 1; i < 6; ++i)
    {
        v1.push_back(i);
        v3.push_back(0);
        v4.push_back(0);
    }

    // v2拷贝v1
    /*
    容器拷贝方式：
    1、copyvec.assign(vec.begin(), vec.end());
    2、copyvec.swap(vec);
    3、copyvec.insert(copyvec.end(), vec.begin(), vec.end());
    4、copy(vec.begin(), vec.end(), beck_inserter(copyvec));
    5、copyvec.resize(size); // 需预分配空间
       copy(vec.begin(), vec.end(), copyvec.begin());
    */
    copy(v1.begin(), v1.end(), back_inserter(v2));

    // 查看v1容器中元素
    for_each(v1.begin(), v1.end(), display);
    cout << endl;

    // v3中的元素为v1元素的平方
    transform(v1.begin(), v1.end(), v3.begin(), power_);

    // 查看v3容器中元素
    for_each(v3.begin(), v3.end(), display);
    cout << endl;

    // v4中的元素为v1和v2元素的和
    transform(v1.begin(), v1.end(), v2.begin(), v4.begin(), add_);

    // 查看v4容器中元素
    for_each(v4.begin(), v4.end(), display);
    cout << endl;
}

int main(int argc, char *argv[])
{
    exa8();
    return 0;
}