#include <iostream>
#include <csignal>
#include <unistd.h>
using namespace std;

/*
 * 信号是由操作系统传给进程的中断，会提早终止一个程序。
 * 有些信号不能被程序捕获，但是下表所列信号可以在程序中捕获，
 * 并可以基于信号采取适当的动作。
 * 这些信号是定义在 C++ 头文件 <csignal> 中。
 */

/*
 * 部分信号
 *
 * SIGABRT  程序的异常终止，如调用 abort
 * SIGFPE   错误的算术运算，如除以零或导致溢出等操作
 * SIGILL   检测非法指令
 * SIGSEGV  非法访问内存
 * SIGTERM  发送到程序的终止请求
 *
 */

/*
 * signal() 函数
 * C++ 信号处理库提供了 signal 函数，用来捕获突发事件。
 * 用法：void (*signal(int sig, void (*func)(int)))(int)
 * 或：signal(registered signal, signal handler)
 *
 * 这个函数接收两个参数：(信号标识符， 信号处理函数的指针)，返回值是一个指向先前信号处理函数的指针
 * 如果未设置信号处理函数，则返回值 SIG_DFL 。
 */

// 使用 signal() 函数捕获 SIGINT 信号

void signalHandler(int signalnum)
{
    cout << "Interrupt signal (" << signalnum << ") received" << endl;

    // 清理并关闭
    // 终止程序

    exit(signalnum);
}

void exa1()
{
    // 注册信号 SIGINT 和信号处理函数
    signal(SIGINT, signalHandler);

    while (1)
    {
        cout << "Going to sleep..." << endl;
        sleep(1);
    }
}

/*
 * 预期结果
 * Going to sleep....
 * Going to sleep....
 * Going to sleep....
 * 当按下 CTRL + C 中断程序时
 * Interrupt signal (2) received.
 */

/*
 * raise() 函数
 * 使用 raise() 函数生成信号，该函数带有一个整数信号编号作为参数。
 * 用法：int raise(signal sig)
 */

// 使用 raise() 函数内部生成信号

void exa2()
{
    int i = 0;
    // 注册信号 SIGINT 和信号处理函数
    signal(SIGINT, signalHandler);
    while (++i)
    {
        cout << "Going to sleep..." << endl;
        if (i == 2)
            raise(SIGINT);
        sleep(1);
    }
}

/*
 * sleep() 函数
 * 执行挂起一段时间，等待一段时间再继续运行
 * 用法：sleep(时间)
 * 
 * Linux 用 #include <unistd.h> 中的 sleep(秒)
 * Windows 用 #include <windows.h> 中的 Sleep(毫秒)
*/