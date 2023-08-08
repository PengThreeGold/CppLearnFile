// 杂谈
#include <iostream>
using namespace std;

// 一：this 指针  -----------------------------------
/*
this 指针：所有成员函数的隐含参数，
每一个对象都能通过this指针来访问自己的地址，
因此在成员函数内部可以用来指向调用对象。

注意：友元函数没有this指针，因为友元不是类的成员，
只有成员函数才有this指针。
*/

// 实例
class Box
{
public:
    // 构造函数定义
    Box(double l = 2.0, double b = 2.0, double h = 2.0)
    {
        cout << "Object has been created !" << endl;
        length = l;
        breadth = b;
        height = h;
    }

    ~Box(){};

    double Volume()
    {
        return length * breadth * height;
    }

    int compare(Box box)
    {
        return this->Volume() > box.Volume();
    }

    Box *getAddress()
    {
        return this; // 得到this的地址
    }

private:
    double length;
    double breadth;
    double height;
};

// this 指针实例
void exa1()
{
    cout << "——————————this 指针实例——————————" << endl;
    Box box1(3.3, 1.2, 1.5);
    Box box2(1.2, 2.3, 4.5);
    if (box1.compare(box2))
    {
        cout << "box1 is bigger !" << endl;
    }
    else
    {
        cout << "box2 is bigger !" << endl;
    }
    // 使用Box* 定义指针ptr接收对象box1的getAddress()成员函数的返回值，并打印。
    Box *ptr = box1.getAddress();
    cout << "Address of box1 : " << ptr << endl;
    ptr = box2.getAddress();
    cout << "Address of box2 : " << ptr << endl;
}

// 二：指向类的指针 -----------------------------------
/*
一个指向C++类的指针与指向结构的指针类似，
访问指向类的指针的成员，需要使用成员访问运算符->。
*/

void exa2(){
    cout << "——————————类 指针实例——————————" << endl;
    Box box;
    Box *ptrBox;
    ptrBox = &box;
    cout << "Adress of box : " << ptrBox << endl;
}


// 程序入口
int main()
{
    exa1();
    exa2();
    return 0;
}