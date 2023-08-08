#include <iostream>
#include <stack> // 栈stack
#include <queue> // 队列queue 和 优先级队列priority queue

using namespace std;

/*
 * 标准容器 ——> 容器适配器 ——>可以参考适配器模式（但实际可以解释为代理模式）
 */

// 怎么理解适配器？以下为简单适配器示例

template <typename T, typename Container = deque<T>>
class Stack_
{
public:
    void push(const T &val) { con.push_back(val); }
    void pop() { con.pop_back(); }
    T top() const { return con.back(); }

private:
    Container con;
};

/*
 * 1、适配器底层没有自己的数据结构，它是另外一个容器的封装，
 *    它的方法全部由底层依赖的容器进行实现。
 * 2、没有实现自己的迭代器
 */

int main(int argc, char *argv[])
{
    srand((unsigned)time(NULL));

    stack<int> s1;
    // push入栈 pop出栈 top返回栈顶元素 empty判空 size返回元素个数
    // stack => deque 为什么不依赖vector？

    for (int i = 0; i < 20; ++i)
    {
        s1.push(rand() % 100 + 1);
    }

    cout << s1.size() << endl;

    while (!s1.empty())
    {
        cout << s1.top() << " ";
        s1.pop();
    }

    cout << "\n------------ end ------------" << endl;

    queue<int> que;
    // push入队 pop出队 front返回队头元素 back返回队尾元素 empty判空 size返回元素个数
    // queue => deque 为什么不依赖vector？

    for (int i = 0; i < 20; ++i)
    {
        que.push(rand() % 100 + 1);
    }

    cout << que.size() << endl;
    
    while (!que.empty())
    {
        cout << que.front() << " ";
        que.pop();
    }

    cout << "\n------------ end ------------" << endl;

    priority_queue<int> pque;
    // push入队 pop出队 top返回队头元素 empty判空 size返回元素个数 
    // 默认底层数据结构：大根堆
    // priority_queue => vector 为什么依赖vector?

    for (int i = 0; i < 20; ++i)
    {
        pque.push(rand() % 100 + 1);
    }

    cout << pque.size() << endl;

    while (!pque.empty())
    {
        cout << pque.top() << " ";
        pque.pop();
    }

    return 0;
}

/*
 * stack/queue => deque 为什么不依赖vector？
 * 1、vector的初始内存使用效率太低了！没有deque好。
 *  vector 0-1-2-4-8…… 多次扩容（修改源码使用reserve预分配空间解决）
 *  deque 4096/sizeof(T) 初始二维数据域较大
 * 2、对于queue来说，需要支持尾部插入与头部删除最好是O(1)
 *  vector 头插入效率为O(n)，效率过低
 * 3、vector需要大片连续内存，deque只需要分段内存
 *  当存储大量数据时，显然deque对于内存的利用率较好。
 * 
 * priority_queue => vector 为什么依赖vector?
 * 1、底层默认把数据组成一个大根堆结构
 *  大根堆数据结构需要利用随机访问（下标）或说内存连续的数组上构建
 *  deque第二维上是不连续的，无法进行随机访问（下标）
 * 
*/