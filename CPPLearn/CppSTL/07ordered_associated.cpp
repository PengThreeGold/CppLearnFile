#include <iostream>
// 有序关联容器包含的头文件
#include <set> // set multiset
#include <map> // map multimap
// 无序关联容器包含的头文件
#include <unordered_set>
#include <unordered_map>

using namespace std;

/*
 * 关联容器
 *
 * 1、无序关联容器 -> 链式哈希表 增删查O(1)
 * set：集合 key    map：映射表 {key, value}
 * unordered_set      单重集合（key不重复）
 * unordered_multiset 多重集合（key重复）
 * unordered_map      单重映射表
 * unordered_multimap 多重映射表
 *
 * 2、有序关联容器 -> 红黑树 增删查O(log2n) 2是底数（树的层数、树的高度）
 */

int main(int argc, char *argv[])
{
    srand((unsigned)time(NULL));
#if 0
    unordered_set<int> uset1; // 不会存储key值重复的元素
    for (int i = 0; i < 50; ++i)
    {
        uset1.insert(rand() % 20 + 1); // 直接插入元素，哈希映射表/红黑树会将插入元素按照数据结构安放位置
        // vector/deque/list 需要T.insert(it, val) it迭代器 表示位置
    }

    cout << uset1.size() << endl;    // 集合大小
    cout << uset1.count(15) << endl; // 某个元素出现的次数
    // 单重集合内key值不重复，对某个元素进行次数查询一定不大于1

    // 使用迭代器遍历集合
    auto it1 = uset1.begin();
    for (; it1 != uset1.end(); ++it1)
    {
        cout << *it1 << " ";
    }
    cout << endl;

    // 根据key值删除元素
    uset1.erase(20);

    // 迭代器遍历删除
    for (it1 = uset1.begin(); it1 != uset1.end();)
    {
        if (*it1 == 20)
        {
            it1 = uset1.erase(it1); // 调用erase，迭代器失效
        }
        else
        {
            ++it1;
        }
    }

    // 利用find函数寻找对应key值位置，未找到则直接返回容器末尾迭代器
    it1 = uset1.find(20);
    // 判断是否找到，找到则删除
    if (it1 != uset1.end())
    {
        cout << "删除" << *it1 << endl;
        uset1.erase(it1);
    }

    for (int v : uset1)
    {
        cout << v << " ";
    }
    cout << endl;


    // 无序多重集合
    unordered_multiset<int> umset1; // 会存储key值重复的元素
    for (int i = 0; i < 50; ++i)
    {
        umset1.insert(rand() % 20 + 1); // 直接插入元素，哈希映射表/红黑树会将插入元素按照数据结构安放位置
        // vector/deque/list 需要T.insert(it, val) it迭代器 表示位置
    }

    cout << umset1.size() << endl;    // 集合大小
    cout << umset1.count(15) << endl; // 某个元素出现的次数
    // 多重集合内key值重复
#endif

    /*
     * map -> [kay, value]
    struct pair
    {
        private:
        first; -> key
        second; -> value
    }
    */
    unordered_map<int, string> umap1;

    // 新增
    umap1.insert(make_pair(1000, "张三"));
    // C++11
    umap1.insert({1010, "李四"});
    umap1.insert({1020, "王五"});

    // 删除
    umap1.erase(1020);

    // map的operator[]
    // map operator[](key) => value
    // 1、查询
    // 2、如果key不存在，它会插入一对数据[key, string()]

    cout << umap1[1000] << endl; // 查询
    umap1[2000];                 // 空查询 -> 默认创建
    umap1[2010] = "宋六";        // 等同于创建
    umap1[1000] = "张三2";       // 等同于修改

    // 大小
    cout << umap1.size() << endl;

    // 单重映射表不能重复key值，将会忽略
    umap1.insert({1000, "王二麻子"});

    // 迭代器遍历
    auto it1 = umap1.find(1030);
    if (it1 != umap1.end())
    {
        // it1 -> pair对象
        cout << "key: " << it1->first << "value: " << it1->second << endl;
    }

    // 哈希映射表应用场景：海量数据查重复、去重复的时候
    // 示例1
    const int ARR_LEN = 100;
    int arr2[ARR_LEN] = {0};
    for (int i = 0; i < ARR_LEN; ++i)
    {
        arr2[i] = rand() % 20 + 1;
    }

    // 上面的10万个整数中，统计哪些数字重复了，并且统计数字重复的次数
    unordered_map<int, int> map1;
    for (int k : arr2)
    {
        // auto it = map1.find(k);
        // if (it == map1.end())
        // {
        //     map1.insert({k, 1});
        // }
        // else
        // {
        //     it->second++;
        // }
        // 使用下面替代
        map1[k]++;
    }

    for (const pair<int , int> &p : map1)
    {
        if (p.second > 1)
        {
            cout << "key: " << p.first << "  count: " << p.second << endl;
        }
    }

    // 示例2
    
    int arr2[ARR_LEN] = {0};
    for (int i = 0; i < ARR_LEN; ++i)
    {
        arr2[i] = rand() % 20 + 1;
    }
    // 上面的10万个整数中，统计哪些数字重复了，去除重复数字并打印

    unordered_set<int> set1;
    for (int v : arr2)
    {
        set1.insert(v);
    }
    for (int v : set1)
    {
        cout << v << " ";
    }
    cout << endl;
    
    return 0;
}