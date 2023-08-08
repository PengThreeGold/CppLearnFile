/*
 * 创建线程
 * 在 Windows 平台，Windows API 提供了许多对多线程的支持。
 * 一个程序至少有一个线程，这个线程称为主线程（main thread），
 * 如果我们不显示地创建线程，那我们产的程序就是只有主线程的间线程程序。
 *
 * create Thread 与 CloseHandle
 *
 * CreateThread 用于创建一个线程，其函数原型如下：
 *
 * HANDLE WINAPI CreateThread(
 * LPSECURITY_ATTRIBUTES   lpThreadAttributes,  // 线程安全相关的属性，常置为NULL
 *  SIZE_T                  dwStackSize,        // 新线程的初始化栈在大小，可设置为0
 * LPTHREAD_START_ROUTINE  lpStartAddress,      // 被线程执行的回调函数，也称为线程函数
 * LPVOID                  lpParameter,         // 传入线程函数的参数，不需传递参数时为NULL
 * DWORD                   dwCreationFlags,     // 控制线程创建的标志
 * LPDWORD                 lpThreadId           // 传出参数，用于获得线程ID，如果为NULL则不返回线程ID
 * );
 *
 */

/*
 * 为什么CreateThread()之后又马上CloseHandle()的问题？
 * 1、线程和线程句柄（）不是一个东西。线程在CPU上运行，线程句柄是一个内核对象。
 * 2、所有的内核对象（包括线程Handle）都是系统资源，使用后要及时关闭，否则系统句柄资源很快被消耗殆尽。
 * 3、如果创建线程后需要对这个线程进行操作，例如：改变优先级、阻塞等待等则需要保存线程句柄，使用完后关闭。
 * 
*/

#include <iostream>
#include <windows.h>

using namespace std;

#define NAME_LINE 40

// --------- 1、简单的线程创建 ---------

// 线程函数
DWORD WINAPI ThreadProc_1(LPVOID lpParameter)
{
    for (int i = 0; i < 5; i++)
    {
        cout << "子线程: i = " << i << endl;
        Sleep(100);
    }
    return 0L;
}

void exa1()
{
    // 创建一个线程
    HANDLE thread = CreateThread(NULL, 0, ThreadProc_1, NULL, 0, NULL);
    // 关闭创建的线程句柄
    CloseHandle(thread);

    // 主线程的执行路劲
    for (int i = 0; i < 5; i++)
    {
        cout << "主线程: i = " << i << endl;
        Sleep(100);
    }
}

// --------- 2、在线程函数中传入参数 ---------


typedef struct __THREAD_DATA
{
    int nMaxNum;
    char strThreadName[NAME_LINE];

    __THREAD_DATA() : nMaxNum(0)
    {
        memset(strThreadName, 0, NAME_LINE * sizeof(char));
    }

} THREAD_DATA;

// 线程函数
DWORD WINAPI ThreadProc_2(LPVOID lpParameter)
{
    THREAD_DATA *pThreadData = (THREAD_DATA *)lpParameter;

    for (int i = 0; i < pThreadData->nMaxNum; ++i)
    {
        cout << pThreadData->strThreadName << " ---- " << i << endl;
        Sleep(100);
    }

    return 0L;
}

void exa2()
{
    // 初始化线程数据
    THREAD_DATA threadData1, threadData2;
    threadData1.nMaxNum = 5;
    strcpy(threadData1.strThreadName, "线程1");
    threadData2.nMaxNum = 10;
    strcpy(threadData2.strThreadName, "线程2");

    // 创建第一个子线程
    HANDLE hThread1 = CreateThread(NULL, 0, ThreadProc_2, &threadData1, 0, NULL);
    // 创建第二个子线程
    HANDLE hThread2 = CreateThread(NULL, 0, ThreadProc_2, &threadData2, 0, NULL);

    // 关闭创建的线程句柄
    CloseHandle(hThread1);
    CloseHandle(hThread2);

    // 主线程的执行路径
    for (int i = 0; i < 5; ++i)
    {
        cout << "主线程 === " << i << endl;
        Sleep(500);
    }
}

//  --------- 3、线程中互斥量的使用 ---------

/*
 * 线程同步处理：互斥量（mutex）
 * 互斥量（mutex）和二元信号量类似，资源仅允许一个线程访问。
 * 与二元信号量不同的是，信号量在整个系统中可以被任意线程获取和释放，
 * 也就是说，同一个信号量可以由一个线程获取而由另一线程释放。
 * 而互斥量则要求哪个线程获取了该互斥量锁就由哪个线程释放，
 * 其他线程释放互斥量是无效的。
 *
 * 在使用互斥量进行线程同步时会用到以下几个函数：
 *
 * HANDLE WINAPI CreateMutex(
 *     LPSECURITY_ATTRIBUTES lpMutexAttributes,        //线程安全相关的属性，常置为NULL
 *     BOOL                  bInitialOwner,            //创建Mutex时的当前线程是否拥有Mutex的所有权
 *     LPCTSTR               lpName                    //Mutex的名称
 * );
 *
 * DWORD WINAPI WaitForSingleObject(
 *     HANDLE hHandle,                             //要获取的锁的句柄
 *     DWORD  dwMilliseconds                           //超时间隔
 * );
 *
 * BOOL WINAPI ReleaseMutex(HANDLE hMutex);  // 释放所拥有的互斥量锁对象，hMutex为释放的互斥量的句柄。
 *
 */

HANDLE g_hmutex = NULL; // 互斥量

// 线程函数
DWORD WINAPI ThreadProc_3(LPVOID lpParameter)
{
    THREAD_DATA *pThreadData = (THREAD_DATA *)lpParameter;

    for (int i = 0; i < pThreadData->nMaxNum; ++i)
    {
        // 请求获得一个互斥量锁
        WaitForSingleObject(g_hmutex, INFINITE); // 无限等待
        cout << pThreadData->strThreadName << " --- " << i << endl;
        Sleep(100);
        // 释放互斥量锁
        ReleaseMutex(g_hmutex);
    }
    return 0L;
}

void exa3()
{
    // 创建一个互斥量
    g_hmutex = CreateMutex(NULL, false, NULL);

    // 初始化线程数据
    THREAD_DATA threadData1, threadData2;
    threadData1.nMaxNum = 5;
    strcpy(threadData1.strThreadName, "线程1");
    threadData2.nMaxNum = 10;
    strcpy(threadData2.strThreadName, "线程2");

    // 创建第一个子线程
    HANDLE hThread1 = CreateThread(NULL, 0, ThreadProc_3, &threadData1, 0, NULL);
    // 创建第二个子线程
    HANDLE hThread2 = CreateThread(NULL, 0, ThreadProc_3, &threadData2, 0, NULL);
    // 关闭创建的线程句柄
    CloseHandle(hThread1);
    CloseHandle(hThread2);

    // 主线程的执行路径
    for (int i = 0; i < 5; ++i)
    {
        // 请求获得一个互斥量锁
        WaitForSingleObject(g_hmutex, INFINITE);
        cout << "主线程 === " << i << endl;
        Sleep(100);
        // 释放互斥量锁
        ReleaseMutex(g_hmutex);
    }
    int i = 0;
    cin >> i;
}

int main(int argc, char *argv[])
{
    exa3();
    return 0;
}