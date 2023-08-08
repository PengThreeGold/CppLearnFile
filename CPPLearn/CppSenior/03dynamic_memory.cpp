#include <iostream>
using namespace std;

/*
 * 栈：在函数内部声明的所有变量都将占用栈内存
 * 堆：这是程序中未使用的内存，在程序运行时可用于动态内存分配
 *
 * new运算符：用于分配堆上内存，返回所分配的空间地址
 * 1、new VS malloc() 函数
 * (1) new的功能是在堆区新建一个对象，并返回该对象的指针。
 *     所谓新建对象的意思就是将调用该类的构造函数，不构造则不能称为对象。
 * (2) malloc() 函数只是机械的分配一块内存，如果用malloc在堆区创建一个对象的话，
 *     是不会调用构造函数的。严格来说malloc不能算是新建了一个对象，
 *     只能说是分配了一块与该类对象匹配的内存，然后把它强行解释为 “对象”。
 * (3) 当使用 delete 去释放一个堆区对象时，会调用该对象的析构函数。
 *     而是用 free 释放一个堆区的对象时，不会调用该对象的析构函数。
 * 
 * 
 * 2、示例：new data-type
 * data-type 可以是包括数组在内的任意内置的数据类型，
 * 也可以是包括类或结构在内的用户自定义的任何数据类型。
 * 
 * 3、例子：
 * 定义一个指向double类型的指针，然后请求内存，该内存在执行时被分配。
 * double* pvalue = NULL; // 初始化为null的指针
 * pvalue = new double; // 为变量请求内存
 *
 * 4、注意：
 * 如果自由存储区已被用完，可能无法成功分配内存，
 * 所以建议检车new运算符是否返回NULL指针。
 * double* pvalue = NULL;
 * if (!(pvalue = new double))
 * {
 *     cout << "ERROR: OUT OF MEMORY!" << endl;
 *     exit(1);
 * }
 *
 *
 * delete运算符：用于删除之前由new运算符分配的内存
 *
 * 1、delete VS delete[]
 * (1) 针对简单类型，使用new分配后的不管是数组还是非数组形式内存空间两种均可
 * (2) 针对类class，两种方式体现出具体差异
 * delete ptr 代表用来释放内存，且只用来释放ptr指向的内存
 * delete[] ptr 用来释放ptr指向的内存，还逐一调用数组中每个对象的destructor（简单数据类型无，对象数组有）
 * （上述ptr代指用new申请的内存返回的内存空间地址，即为指针）
 * 
 */

// new 与 delete 的简单使用
void exa1()
{
    double *pvalue = NULL; // 初始化为null的指针
    pvalue = new double;   // 为变量请求内存

    *pvalue = 123.231; // 在分配的地址存储值
    cout << "Value of pvalue : " << *pvalue << endl;

    delete pvalue; // 释放内存
}

// 数组的动态内存分配
void exa2()
{
    char *pvalue = NULL;   // 初始化为null的指针
    pvalue = new char[20]; // 为变量请求内存

    delete[] pvalue; // 删除pvalue所指向的数组

    // new操作符用于分配多维数组

    // 一维数组
    int *array_1 = new int[8]; // 动态分配，数组长度为8
    // 输出数组
    for (int i = 0; i < 8; i++)
    {
        cout << i;
    }
    cout << endl;
    delete[] array_1; // 释放内存

    // 二维数组（一维长度为4，二维长度为8）
    int **array_2;
    // 动态分配空间
    array_2 = new int *[4];
    for (int i = 0; i < 4; i++)
    {
        array_2[i] = new int[8];
    }
    // 输出数组
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (j == 0)
            {
                cout << endl;
            }
            cout << array_2[i][j] << "\t";
        }
    }
    cout << endl;
    cout << endl;
    // 释放
    for (int i = 0; i < 4; i++)
    {
        delete[] array_2[i];
    }
    delete[] array_2;

    // 三维数组（一维长度为2，二维长度为4，三维长度为8）
    int ***array_3;
    // 动态分配内存
    array_3 = new int **[2];
    for (int i = 0; i < 2; i++)
    {
        array_3[i] = new int *[4];
        for (int j = 0; j < 4; j++)
        {
            array_3[i][j] = new int[4];
        }
    }
    // 输出数组
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            for (int k = 0; k < 8; k++)
            {
                cout << array_3[i][j][k] << "\t";
            }
            cout << endl;
        }
        cout << endl;
    }
    cout << endl;
    // 释放内存
    for (int i = 2; i < 2; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            delete[] array_3[i][j];
        }
    }
    for (int i = 0; i < 2; i++)
    {
        delete[] array_3[i];
    }
    delete[] array_3;
}

// 对象的动态内存分配
class Box
{
public:
    Box()
    {
        cout << "调用构造函数" << endl;
    }
    ~Box()
    {
        cout << "调用析构函数" << endl;
    }
};

void exa3()
{
    Box *BoxArray = new Box[4];
    delete[] BoxArray;
}

int main(int argc, char **argv)
{
    exa1();
    exa2();
    exa3();
    return 0;
}