/*
 * C++ std::thread
 * C++ 11 之后新的标准线程库
 * 调用方式：g++ -std=c++11 test.cpp
 * 默认构造函数      ：创建一个空的 std::thread 执行对象
 * 初始化构造函数    ：创建一个 std::thread 对象，该对象可被 joinable ，
 *                   新产生的线程会调用 fn 函数，该函数的参数由 args 给出。
 * 拷贝构造函数(禁用)：意味着 std::thread 对象不可拷贝构造。
 * Move移动构造     ：移动构造，调用成功之后x不代表任何 std::thread 执行对象。
 */

#include <iostream>
#include <utility>
#include <thread>
#include <chrono>
#include <functional>
#include <atomic>

using namespace std;

// std::thread 各种构造函数实例

void f1(int n)
{
    for (int i = 0; i < 5; ++i)
    {
        cout << "Thread " << n << " executing" << endl;
        this_thread::sleep_for(chrono::milliseconds(10));
    }
}

void f2(int &n)
{
    for (int i = 0; i < 5; ++i)
    {
        cout << "Thread 2 excuting" << endl;
        ++n;
        this_thread::sleep_for(chrono::milliseconds(10));
    }
}

void exa1()
{
    int n = 0;
    thread t1;             // t1 is not a thread
    thread t2(f1, n + 1);  // pass by value
    thread t3(f2, ref(n)); // pass by reference
    thread t4(move(t3));   // t4 is now running f2(), t3 is no longer a thread
    t2.join();
    t4.join();
    cout << "Final value of n is " << n << endl;
}

// std::thread 赋值操作
// Move() 赋值操作：如果当前对象不可joinable，需要传递一个右值引用（rhs）给Move赋值操作；
//                 如果当前对象可被joinable，则对调用terminate()报错。
// 拷贝赋值操作   ：被禁用，因此std::thread对象不可被拷贝赋值

void thread_task(int n)
{
    this_thread::sleep_for(chrono::milliseconds(n));
    cout << "Hello Thread" << this_thread::get_id() << " paused " << n << " seconds " << endl;
}

void exa2()
{
    thread threads[5];
    cout << "Spawning 5 threads..." << endl;
    for (int i = 0; i < 5; ++i)
    {
        threads[i] = thread(thread_task, i + 1);
    }
    cout << "Done spawning threads! Now wait for them to join." << endl;
    for (auto& t: threads)
    {
        t.join();
    }
    cout << "All threads joined!" << endl;
}

// get_is()：获取线程ID，返回一个类型为std::thread::id的对象。

void f3()
{
    this_thread::sleep_for(std::chrono::seconds(1));
}

void exa3()
{
    thread t1(f3);
    thread::id t1_id = t1.get_id();
    cout << "t1's id : " << t1_id << endl;
    t1.join();
}

// joinable()：检查线程是否被join。检查当前的线程对象是否表示了一个活动的执行线程，由默认构造函数创建的线程是不能被join的。
// 另外，如果某个线程已经执行完任务，但是没有没join的话，该线程会被认为是一个活动的执行线程，因此也是可以被join的。

void f4()
{
    this_thread::sleep_for(std::chrono::seconds(1));
}

void b4()
{
    this_thread::sleep_for(chrono::seconds(1));
}

void exa4_1()
{
    thread t;
    cout << "before starting, joinable : " << t.joinable() << endl;
    t = thread(f4);
    cout << "after starting, joinable : " << t.joinable() << endl;

    t.join();
}

// join()：join线程，调用该函数会阻塞当前线程，直到由 *this 所标示的线程执行完毕join才返回。

void exa4_2()
{
    cout << "starting first helper..." << endl;
    thread helper1(f4);

    cout << "starting second helper..." << endl;
    thread helper2(b4);

    cout << "waiting for helpers to finish..." << endl;
    helper1.join();
    helper2.join();

    cout << "Done!" << endl;
}


/*
 * detach()：detach线程。将当前线程对象所代表的执行实例与该线程对象分离。
 * 使得线程的执行可以单独进行。一旦线程执行完毕，它所分配的资源将会被释放。
 * 调用detach()函数之后：
 * 1、*this 不在代表任何的线程执行实例。
 * 2、joinable() == false
 * 3、get_id() == std::thread::id()
 * 另外，如果出错或者joinable() == false，则会抛出std::system_error
*/

void independentThread()
{
    cout << "Starting concurrent thread" << endl;
    this_thread::sleep_for(chrono::seconds(2));
    cout << "Exiting concurrent thread" << endl;
}

void threadCaller()
{
    cout << "Starting thread caller" << endl;
    thread t(independentThread);
    t.detach();
    this_thread::sleep_for(chrono::seconds(1));
    cout << "Exiting thread caller" << endl;
}

void exa5()
{
    threadCaller();
    this_thread::sleep_for(chrono::seconds(5));
}

// swap():swap 线程，交换两个线程对象所代表的底层句柄（underlying handles）


int main()
{
    exa5();
    return 0;
}