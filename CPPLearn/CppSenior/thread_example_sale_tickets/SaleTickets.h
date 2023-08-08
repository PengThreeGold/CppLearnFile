
#include <windows.h>
#include <iostream>
#include <string>

using namespace std;

#define NAME_LINE 40

// 定义线程函数传入参数的结构体

// 票结构体
typedef struct __TICKET
{
    int nCount;
    char strTicketName[NAME_LINE];

    __TICKET() : nCount(0)
    {
        memset(strTicketName, 0, NAME_LINE * sizeof(char));
    }
} TICKET;

// 线程函数参数结构体
typedef struct __THD_DATA
{
    TICKET *pTicket;
    char strThreadName[NAME_LINE];

    __THD_DATA() : pTicket(NULL)
    {
        memset(strThreadName, 0, NAME_LINE * sizeof(char));
    }
} THD_DATA;

// 售票程序声明
DWORD WINAPI SaleTicket(LPVOID lpParameter);