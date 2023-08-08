/*
1、
类的友元函数是定义在类外部，
但有权访问类的所有私有成员和保护成员，
尽管友元函数的原型在类的定义中出现过，
但是友元函数并不是成员函数，

2、
友元可以是一个函数，该函数被称为友元函数；
友元也可以是一个类，该类被称为友元类；
（在这个情况下，整个类及其所有成员都是友元）
*/

#include <iostream>
using namespace std;

class Box
{
    double width; // 默认私有化
public:
    friend void printWidth(Box box); // 友元函数
    friend class BigBox;             // 友元类
    void setWidth(double wid);
};

class BigBox
{
public:
    void Print(double width, Box &box)
    {
        // BigBox是Box的友元类，他可以直接访问Box的任何成员
        box.setWidth(width);
        cout << "width of box : " << box.width << endl;
    }
};
// 成员函数定义
void Box::setWidth(double wid)
{
    this->width = wid;
}

// 请注意：printWidth() 不是任何类的成员函数
void printWidth(Box box)
{
    // 因为 printWidth() 是 Box 的友元，他可以直接访问该类的任何成员。
    cout << "width of box : " << box.width << endl;
}

// 程序的主函数
int main()
{
    Box box;
    BigBox bigbox;

    // 使用成员函数设置宽度
    box.setWidth(1.23);

    // 使用友元函数输出宽度
    printWidth(box);

    // 使用友元类中的方法设置宽度
    bigbox.Print(2.34, box);

    return 0;
}