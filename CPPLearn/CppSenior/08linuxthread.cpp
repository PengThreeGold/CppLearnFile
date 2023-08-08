#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <unistd.h>

using namespace std;

/*
 * C++ 多线程
 * 多线程是多任务处理的一种特殊形式，多任务处理允许让电脑同时运行两个或两个以上的程序。
 * 一般情况下，两种类型的多任务处理：基于进程和基于线程。
 * 基于进程的多任务处理是程序的并发执行。
 * 基于线程的多任务处理事同一程序的片段的并发执行。
 *
 * 多线程程序包含可以同时运行的两个或多个部分。
 * 这样的程序中的每一个部分称为一个线程，每个线程定义了一个单独的执行路径。
 *
 * 在此文件中使用的是 POSIX 编写多线程 C++ 程序。
 * POSIX Threads 或 Pthreads 提供的 API 可以在多种类 Unix POSIX 系统上可用。
 * 例如：FreeBSD、NetBSD、GUN/Linux、Mac OS X 和 Solaris 等。
 */

/*
 * 创建线程
 * pthread_create(thread, attr, start_routime, arg)
 * 参数说明：
 * thread:         指向线程标识符指针
 * attr  :         一个不透明的属性对象，可以用来设置线程属性。
 * start_routime:  线程运行函数起始地址。
 * arg:            运行函数的参数。（它必须通过把引用作为指针强制转换为 void 类型进行传递。默认NULL）
 *
 *
 * 终止线程
 * pthread_exit(status)
 * 在这里，pthread_exit 用于显式地退出一个线程。
 * 通常情况下，pthread_exit() 函数实在线程完成工作后无需继续存在时被调用。
 * 如果 mian() 实在它所在创建的线程之前结束，并通过 pthread_exit() 退出，
 * 那么其他线程将继续执行。否则它们将在 main() 函数结束时自动被终止。
 */

#define NUM_THREADS 5

// 1、以下简单的实例代码使用 pthread_create() 函数创建了 5 个线程，
// 每个线程输出 "HELLO WORLD!"
void *say_hello(void *args) // 线程的运行函数
{
    cout << "HELLO WORLD!" << endl;
    return 0;
}

void exa1()
{
    pthread_t tids[NUM_THREADS]; // 线程（id）队列
    int rc;                      // 线程创建返回值，0为创建成功，其余为错误状态码

    for (int i = 0; i < NUM_THREADS; ++i)
    {
        // 参数依次是：传出创建的线程id、线程参数、调用的函数、传入的函数参数
        rc = pthread_create(&tids[i], NULL, say_hello, NULL);
        if (rc)
        {
            cout << "错误！！！无法创建线程, 错误码: " << rc << endl;
        }
    }
    // 等各个线程退出之后，进程才结束，否则进程强制结束了，线程可能还没反应过来！
    pthread_exit(NULL);
}

// 2、以下简单的实例代码使用 pthread_create() 函数创建了 5 个线程，并接收传入的参数。
// 每个线程打印一个 "HELLO WORLD!" 消息，并输出接收的参数，然后调用 pthread_exit() 终止线程。
void *PrintHello(void *threadid) // 线程的运行函数
{
    // 对传入的参数进行强制类型转换，由无类型指针变为整形指针，然后在读取
    int tid = *((int *)threadid);
    cout << "HELLO WORLD! 线程序号: " << tid << endl;
    pthread_exit(NULL);
    return 0;
}

void exa2()
{
    pthread_t threads[NUM_THREADS];
    int indexes[NUM_THREADS]; // 用数组来保存i的值
    int rc;
    int i;
    for (i = 0; i < NUM_THREADS; i++)
    {
        cout << "主函数创建线程: " << i << endl;
        indexes[i] = i; // 保存 i 的值
        // 传入线程函数参数的时候必须强制转换为 void* 类型，即无类型指针
        rc = pthread_create(&threads[i], NULL, PrintHello, (void *)&(threads[i]));
        if (rc)
        {
            cout << "错误！！！无法创建线程, 错误码: " << rc << endl;
            exit(-1);
        }
    }
    pthread_exit(NULL);
}

// 3、向线程传递参数
// 以下实例通过结构传递多个参数。
// 可以在线程回调中传递任意的数据类型，因为它指向 void 。

struct thread_data // （传入线程函数参数）结构体
{

    int thread_num; // 线程序号
    char *message;  // 消息
};

void *PrintHelloArg(void *threadarg) // 线程运行函数
{
    struct thread_data *my_data;                         // 结构体指针
    my_data = (struct thread_data *)threadarg;           // 传递参数强制转换为结构体指针类型
    cout << "线程ID: " << pthread_self() << endl;        // 打印当前线程 ID
    cout << "线程序号: " << my_data->thread_num << endl; // 打印（传递参数）结构体中线程序号
    cout << "消息: " << my_data->message << endl;        // 打印（传递参数）结构体中消息
    pthread_exit(NULL);                                  // 退出线程
}

void exa3()
{
    pthread_t threads[NUM_THREADS];     // 线程（id）队列
    struct thread_data td[NUM_THREADS]; // （传递参数）结构体队列

    int rc; // 线程创建返回值，0为创建成功，其余为错误状态码
    int i;

    for (i = 0; i < NUM_THREADS; i++) // 遍历创建线程
    {
        td[i].message = (char *)("消息主体。");                                // 向结构体参数赋值
        td[i].thread_num = i;                                                  // 向结构体参数赋值
        rc = pthread_create(&threads[i], NULL, PrintHelloArg, (void *)&td[i]); // (传出参数(线程id), 线程默认属性, 函数指针(线程主函数), 主函数参数)
        cout << "主函数创建线程, 线程ID: " << threads[i] << endl;              // 输出线程 id

        if (rc)
        {
            cout << "错误！！！无法创建线程, 错误码: " << rc << endl;
            exit(-1);
        }
    }
    pthread_exit(NULL);
}

/*
 * 4、连接线程
 * 连接函数：pthread_join(threadid, status)
 * 该函数用于子程序阻碍调用程序，指导指定的threadid线程终止为止。
 * 当创建一个线程时，它的某个属性会定义它是否是可连接的（joinable）或可分离的（detached）.
 * 只有创建时定义为可连接的线程才可以被连接。
 * 如果线程创建时被定义为可分离的，则它永远也不能被连接。
 */

void *wait(void *t)
{
    int i;

    i = *(int *)t;
    sleep(1);
    cout << "线程ID: " << pthread_self() << endl;
    cout << "线程睡眠。" << endl;
    cout << "线程序号: " << i << "...退出中" << endl;
    pthread_exit(NULL);
}

void exa4()
{
    int rc;
    int i;
    pthread_t threads[NUM_THREADS];
    pthread_attr_t attr;
    void *status;

    // 初始化并设置线程为可连接的（joinable）
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
    // 注意：如果设置为 PTHREAD_CREATE_HOINABLE
    // 则继续用 pthread_join() 来等待和释放资源，否则会内存泄漏
    for (i = 0; i < NUM_THREADS; i++)
    {
        cout << "主函数创建线程, 线程序号: " << i << endl;
        rc = pthread_create(&threads[i], NULL, wait, (void *)&i);
        if (rc)
        {
            cout << "错误!!!无法创建线程, 错误码: " << rc << endl;
            exit(-1);
        }
    }

    // 删除属性，并等待其他线程
    pthread_attr_destroy(&attr);
    for (i = 0; i < NUM_THREADS; i++)
    {
        rc = pthread_join(threads[i], &status);
        if (rc)
        {
            cout << "错误!!!无法连接线程, 错误码: " << rc << endl;
            exit(-1);
        }

        cout << "主函数完成线程序号: " << i;
        cout << ", 退出状态码为: " << status << endl;
    }

    cout << "主函数程序退出。" << endl;
    pthread_exit(NULL);
}

/*
 * 5、分离线程
 * 分离函数：pthread_detach(threadid)
 *
 */

/*
 * 6、std::thread
 * C++ 11 之后添加了新的标准线程库 std::thread ,
 * std::thread在 <thread> 头文件中声明，
 * 因此使用 std::thread 时需要包含在 <thread> 头文件。
 * 之前一些编译器使用 C++ 11 的编译参数是 -std=c++11
 * 示例: g++ -std=c++11 test.cpp
 *
 * std::thread 默认构造函数，创建一个空的 std::thread 执行对象。
 * 示例: std::thread thread_object(callable)
 * 一个可调用对象可以是以下三个中的任何一个
 * 1、函数指针
 * 2、函数对象
 * 3、lambda 表达式
 *
 * 定义 callable 后，将其传递给 std::thread 构造函数 thread_object() 。
 */

#include <thread>

void foo(int z) // 一个虚拟函数
{
    for (int i = 0; i < z; i++)
    {
        cout << "线程使用函数指针作为可调用参数" << endl;
    }
}

class thread_obj // 可调用对象
{
public:
    void operator()(int x)
    {
        for (int i = 0; i < x; i++)
        {
            cout << "线程使用函数对象作为可调用参数" << endl;
        }
    }
};

void exa6()
{
    cout << "线程 1、2、3 独立运行。" << endl;

    // 函数指针
    thread th1(foo, 3);

    // 函数对象
    thread th2(thread_obj(), 3);

    // 定义 lambda 表达式
    auto f = [](int x)
    {
        for (int i = 0; i < x; i++)
        {
            cout << "线程使用 lambda 表达式作为可调用参数" << endl;
        }
    };

    // 线程通过使用 lambda 表达式作为可调用的参数
    thread th3(f, 3);

    // 等待线程完成
    th1.join(); // 等待线程th1完成
    th2.join(); // 等待线程th2完成
    th3.join(); // 等待线程th3完成
}

// 7、C++ 11 标准线程库 实例

thread::id main_thread_id = this_thread::get_id();

void hello()
{
    cout << "Hello World" << endl;
    if (main_thread_id == this_thread::get_id())
    {
        cout << "这是主线程" << endl;
    }
    else
    {
        cout << "这不是主线程" << endl;
    }
}

void pause_thread(int n)
{
    this_thread::sleep_for(chrono::seconds(n));
    cout << "pause of " << n << " seconds ended" << endl;
}

void exa7()
{
    thread t(hello);
    cout << t.hardware_concurrency() << endl;              // 用于获取程序可以调动的最大线程数（不准确）
    cout << "native_handle " << t.native_handle() << endl; // 可以并发执行多少个线程（不准确）
    t.join();
    thread a(hello);
    a.detach();
    thread threads[5];

    cout << "新建5个线程" << endl;
    for (int i = 0; i < 5; i++)
    {
        threads[i] = thread(pause_thread, i + 1); // 动态分配线程
    }
    cout << "完成线程创建。等待加入" << endl;
    for (auto &thread : threads)
    {
        thread.join();
    }

    cout << "所有线程已经加入！" << endl;
}

int main(int argc, char **argv)
{
    exa7();
    return 0;
}