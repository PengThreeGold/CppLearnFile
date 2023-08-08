#include <iostream>
#include <deque>

using namespace std;

/*
 * deque 双端队列容器
 * 
 * 底层数据结构：
 * 动态开辟的二维数组，一维数组从2开始，以2倍的方式进行扩容，
 * 每次扩容后，原来第二维的数组，从新的第一维数组的下标（oldsize/2）开始存放，
 * 上下都预留相同的空行，方便支持deque的首尾元素添加。
 * 
 * 常用操作:
 * deque<int> deq;
 * 增加：
 *  deq.push_back(20);  // 从末尾添加元素，o(1)
 *  deq.push_front(20); // 从首部添加元素，o(1) vector要想实现只能首部插入 o(n)
 *  deq.insert(it, 20); // it指向的位置添加元素 o(n)
 * 删除：
 *  deq.pop_back();  // 从末尾删除元素 o(1)
 *  deq.pop_front(); // 从首部删除元素 o(1)
 *  deq.erase(it);   // 从it指向的位置删除元素 o(n)
 * 查询搜索：
 * iterator(连续的insert和erase一定要考虑迭代器失效的问题)
 */

/*
 * list 链表容器
 *
 * 底层数据结构：
 * 双向的循环链表 pre data next
 *
 * 常用操作：
 * list<int> mylist;
 * 增加：
 *  mylist.push_back(20);  // 从末尾添加元素，o(1)
 *  mylist.push_front(20); // 从首部添加元素，o(1) vector要想实现只能首部插入 o(n)
 *  mylist.insert(it, 20); // it指向的位置添加元素 o(1) 
 *  // 但是链表进行insert的时候，先要进行一个query查询操作，而链表的查询操作效率较慢
 *  // 所以完成整体的插入操作为 o(n)，而仅仅是插入操作本身为 o(1)
 * 删除：
 *  mylist.pop_back();  // 从末尾删除元素 o(1)
 *  mylist.pop_front(); // 从首部删除元素 o(1)
 *  mylist.erase(it);   // 从it指向的位置删除元素 o(n)
 * 查询搜索：
 * iterator(连续的insert和erase一定要考虑迭代器失效的问题)
 */
int main(int argc, char *argv[])
{    
    return 0;
}