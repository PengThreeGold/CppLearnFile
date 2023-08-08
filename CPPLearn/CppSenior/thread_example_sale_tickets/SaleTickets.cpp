#include "SaleTickets.h"

using namespace std;

// 定义互斥锁变量
HANDLE g_hMutex = NULL;

// 售票程序
DWORD WINAPI SaleTicket(LPVOID lpParameter)
{
    // 将传入参数转换为对应线程函数结构体
    THD_DATA *pThreadData = (THD_DATA *)lpParameter;
    // 票结构体指针
    TICKET *pSaleData = pThreadData->pTicket;
    // 加锁前判断是否售完
    while (pSaleData->nCount > 0)
    {
        // 请求获得一个互斥量锁
        WaitForSingleObject(g_hMutex, INFINITE);
        // 加锁后判断是否售完
        if (pSaleData->nCount > 0)
        {
            // 输出售票信息，票数自减
            cout << pThreadData->strThreadName << "出售第" << pSaleData->nCount-- << "的票, ";
            // 判断售票后票数是否大于等于0
            if (pSaleData->nCount >= 0) // 大于等于0说明售票成功
            {
                cout << "出票成功！剩余" << pSaleData->nCount << "张票。" << endl;
            }
            else // 小于零说明超出售票
            {
                cout << "出票失败! 该票已售完。" << endl;
            }
        }
        // 线程休眠
        Sleep(100);
        // 释放互斥量锁
        ReleaseMutex(g_hMutex);
    }
    return 0L;
}

int main(int argc, char *argv[])
{
    // 创建一个互斥量
    g_hMutex = CreateMutex(NULL, false, NULL);

    // 初始化火车票
    TICKET ticket;
    ticket.nCount = 20;
    strcpy(ticket.strTicketName, "大庆东 --> 大庆西");
    // 售票窗口数
    const int THREAD_NUMM = 4;
    // 售票窗口线程队列
    THD_DATA threadSale[THREAD_NUMM];
    // 售票窗口线程句柄
    HANDLE hThread[THREAD_NUMM];

    for (int i = 0; i < THREAD_NUMM; ++i)
    {
        threadSale[i].pTicket = &ticket;
        string strThreadName = to_string(i + 1);

        strThreadName = "窗口" + strThreadName;

        strcpy(threadSale[i].strThreadName, strThreadName.c_str());

        // 创建线程
        hThread[i] = CreateThread(NULL, 0, SaleTicket, &threadSale[i], 0, NULL);

        // 请求一个互斥量锁
        WaitForSingleObject(g_hMutex, INFINITE);
        cout << threadSale[i].strThreadName << "开始出售" << threadSale[i].pTicket->strTicketName << "的票..." << endl;
        Sleep(100);
        // 释放互斥量锁
        ReleaseMutex(g_hMutex);

        // 关闭线程句柄
        CloseHandle(hThread[i]);
    }
    int i = 0;
    cin >> i;
    return 0;
}