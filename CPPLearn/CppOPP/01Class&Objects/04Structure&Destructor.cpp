# include <iostream>
using namespace std;

// ---------------------------------------//
// 构造函数
// 一个类可以有多个构造函数，可以是一般类型的，也可以是带参数的，相当于重载构造函数
/*
题目：假定AB为一个类，则执行 ”AB a(2), b[3], *p[4];“ 语句时调用该类构造函数的次数为4次。

解析：

AB a(2) 为调用一次构造函数；

AB b[3]  代表b是AB类的对象数组，包含3个对象，因此为调用3次构造函数；

AB *p[4] 代表p是AB类的对象指针数组，包含4个类对象指针，不调用构造函数。

补充思路：

1. AB *a = new AB;  代表调用默认构造函数：

2. AB b(*a); 代表用括号中的内容*a来初始化Test类型的对象b，调用拷贝构造函数;

3. AB c; 代表定义一个AB类型的对象c，并且没有赋初值，调用默认构造函数;

4. c = a; 代表用a对象给c对象赋值，这里的赋值运算符实际上是调用了赋值构造函数。

5. AB d = a; 代表进行变量d的定义和初始化操作，
虽然有赋值运算符=在，但是其实质还是初始化，并不属于赋值的范畴，
因此这里调用的是复制构造函数，而非赋值构造函数。
*/

class Line
{
    public:
        void setLength(double len);
        double getLength(void);
        Line(); // 这是构造函数
        
    private:
        double Length;
};

// 成员函数定义，包括构造函数
Line::Line(void)
{
    cout << "Object is been created !" << endl;
}

void Line::setLength(double len)
{
    this->Length = len;
}

double Line::getLength(void)
{
    return this->Length;
}

void Exa1()
{
    Line line_1;

    // 设置长度
    line_1.setLength(1.234);
    cout << "Length of line_1 : " << line_1.getLength() << endl;
}

// ---------------------------------------//
// 带参数的构造函数

class Point
{
    public:
        void setArea(double area);
        double getArea(void);
        Point(double area); // 这是构造函数

    private:
        double Area;
};

// 成员函数定义，包括构造函数
Point::Point(double area)
{
    cout << "Object is been created , Area = " << area << endl;
    this->Area = area;
}

void Point::setArea(double area)
{
    this->Area = area;
}

double Point::getArea(void)
{
    return this->Area;
}

void Exa2()
{
    Point point_1(1.234);

    // 获取默认设置的面积
    cout << "Area of point : " << point_1.getArea() << endl;
    // 再次设置长度
    point_1.setArea(2.345);
    cout << "Area of point : " << point_1.getArea() << endl;
}

// ---------------------------------------//
// 使用初始化列表初始化字段（等同于上述语法）
// Point::Point(double area):Area(area)
// {
//     cout << "Object is been created , Area = " << area << endl;
// }

// 多字段(X, Y, Z)初始化（初始化列表）
/*
C::C(int a, int b, int c):X(a), Y(b), Z(c)
{
    ////
}
*/

// ---------------------------------------//
// 类的析构函数
/*
1、类的一种特殊的成员函数，会在每次删除所创建的对象时执行；
2、名称与类名相同，~ 波浪号作为前缀，不返回任何值，不带有任何参数；
3、有助于在跳出程序（比如关闭文件、释放内存等）前释放资源。
*/

class Face{
    public:
        void setSize(double size);
        double getSize(void);
        Face(); // 这是构造函数声明
        ~Face(); // 这是析构函数声明
    
    private:
        double Size;
};

// 成员函数定义，包括构造函数
Face::Face(void)
{
    cout << "Object has been created" << endl;
}

Face::~Face(void)
{
    cout << "Object has been deleted" << endl;
}

void Face::setSize(double size)
{
    this->Size = size;
}

double Face::getSize(void)
{
    return this->Size;
}

void Exa3()
{
    Face face1;

    // 设置大小
    face1.setSize(1.234);
    cout << "Size of face1 : " << face1.getSize() << endl;
}

int main()
{
    // Exa1();
    // Exa2();
    Exa3();
    return 0;
}