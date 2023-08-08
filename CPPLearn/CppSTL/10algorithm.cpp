#include <iostream>
#include <algorithm>
#include <functional> // 包含了函数对象与绑定器
#include <vector>
using namespace std;

/*
 * algorithm: 泛型算法 = template + 迭代器 + 函数对象
 * 示例：sort、find、find_if、binary_search、for_each
 * 特点一：泛型算法的参数接收的都是迭代器
 * 特点二：泛型算法的参数还可以接受函数对象（或是C函数指针）
 */

int main(int argc, char *argv[])
{
    int arr[] = {43, 23, 54, 12, 65, 32, 45, 75};
    vector<int> vec(arr, arr + sizeof(arr) / sizeof(int));

    for (int v : vec)
    {
        cout << v << " ";
    }
    cout << endl;

    // 默认小到大的排序
    sort(vec.begin(), vec.end());

    for (int v : vec)
    {
        cout << v << " ";
    }
    cout << endl;

    // 普通查找

    auto it1 = find(vec.begin(), vec.end(), 32);

    if (it1 != vec.end())
    {
        cout << "find 找到 32" << endl;
    }

    // 二分查找（有序容器）

    if (binary_search(vec.begin(), vec.end(), 32))
    {
        cout << "binary_search 找到 32" << endl;
    }

    // 传入函数对象改变容器元素排序时比较方式

    sort(vec.begin(), vec.end(), greater<int>());

    for (int v : vec)
    {
        cout << v << " ";
    }
    cout << endl;

    // 把某个数按序插入到vector容器当中

    // 可以理解为找第一个小于这个数的数字（需要一个一元函数对象）

    /*
     * 绑定器 + 二元函数对象 =》 一元函数对象
     * bind1st：把二元函数对象的operator()的第一个形参绑定起来
     * bind2st：把二元函数对象的operator()的第二个形参绑定起来
     */

    // 以34示例
    // greater a > b 需要把a绑定为34
    // less a < b 需要把b绑定为34

    auto it2 = find_if(vec.begin(), vec.end(), bind1st(greater<int>(), 34));
    vec.insert(it2, 34);

    for (int v : vec)
    {
        cout << v << " ";
    }
    cout << endl;

    // lambda 表达式的实现
    auto it2 = find_if(vec.begin(), vec.end(), 
                    [=](int x) -> bool{ x < 34; });
    
    // for_each：可以遍历容器的所有元素，可以自行添加合适的函数对象对容器的元素进行过滤

    for_each(vec.begin(), vec.end(), 
            [=](int x)->void{if (x % 2 == 0) cout << x << " "; });
    cout << endl;

    return 0;
}