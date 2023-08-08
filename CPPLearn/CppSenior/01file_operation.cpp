#include <iostream>
#include <fstream>
using namespace std;

/*
关于cin.ignore()，完整版是cin.ignore(int n, char a)，
从输入流（cin）中提取字符，提取的字符被忽略（ignore），不被使用。
每抛弃一个字符，它都要技术和比较字符；
如果计数值达到n或者被抛弃的字符是a，则cin.ignore()函数执行终止；
否则它继续等待。
它的一个常用功能就是用来清除以回车结束的输入缓冲区的内容，
消除上一次输入对下一次输入的影响。
*/
// 向文件内部写入数据，并将数据读出
void file_wr(void)
{
    char data[100];
    // 向文件写入数据
    ofstream outfile;
    outfile.open("test.txt");
    cout << "Write to the test file" << endl;
    cout << "Enter your username: ";
    cin.getline(data, 100);
    outfile << data << endl;
    cout << "Enter your password: " << endl;
    cin >> data;
    cin.ignore();
    outfile << data << endl;
    outfile.close();

    // 从文件读取数据
    ifstream infile;
    infile.open("test.txt");
    cout << "Read the test file" << endl;
    infile >> data;
    cout << data << endl;
    infile >> data;
    cout << data << endl;
    infile.close();
}

// 将数据从一文件复制到另一文件中
void file_copy()
{
    char data[100];
    ifstream infile;
    ofstream outfile;
    infile.open("test.txt");
    outfile.open("test_copy.txt");
    cout << "Copy from test.txt to test_copy.txt" << endl;
    while (!infile.eof())
    {
        infile >> data;
        cout << data << endl;
        outfile << data << endl;
    }
    infile.close();
    outfile.close();
}

// 测试上述读写文件，与文件数据复制
void copy()
{
    file_wr();
    file_copy();
}

// 使用freopen()函数完成

#include <cstdio>
#include <iostream>
#include <algorithm>

void file_wr_()
{
    freopen("test.txt", "r", stdin);
    freopen("test_copy.txt", "w", stdout);
    int a[10];
    for (int i = 0; i < 10; i++)
    {
        cin >> a[i];
    }
    cout << *max_element(a, a + 10);
}