#include <iostream>
using namespace std;

/*
多态

当类之间存在层次结构，并且类之间是通过继承关联时，就会用到多态。
C++多态意味着调用成员函数时，会根据调用函数的对象的类型来执行不同的函数。

多态的三个必要条件
1、必须存在继承关系
2、继承关系必须有同名虚函数（其中虚函数实在基类中使用关键字virtual声明的函数，在派生类中重新定义基类中定义的虚函数时，会告诉编译器不要静态链接到该函数）
3、存在基类类型的指针或者引用，通过该指针或引用调用虚函数

虚函数
虚函数是在基类中使用关键字virtual声明的函数。
在派生类中重新定义基类中定义的虚函数时，
会告诉编译器不要静态链接到该函数。
我们想要的是在程序中任意点可以根据所调用的对象类型来选择调用的函数，这种操作称为动态链接或后期绑定。

纯虚函数
在基类定义虚函数，以便于在派生类中重新定义该函数更好地使用与对象，
但是在基类中不能对虚函数给出有意义的实现，此时就会用到纯虚函数。
例如：
class Shape
{
protected:
    int width, height;
public:
    Shape(int w, int h)
    {
        width = w;
        heigth = h;
    }
    // pure virtual function
    virtual int area() = 0;
}
= 0 告诉编译器，函数没有主体，上面的虚函数是纯虚函数。
*/

class Shape
{
protected:
    int width;
    int height;

public:
    Shape(int w = 0, int h = 0)
    {
        this->width = w;
        this->height = h;
    }

    virtual int area()
    {
        cout << "Parent class area : " << endl;
        return 0;
    }

    /*
    使用virtual的原因
    未使用virtual的情况下，调用函数area()被编译器设置为基类中的版本（静态多态/静态链接/早绑定，函数调用在程序执行前就准备好了）。
    */
};

class Rectangle : public Shape
{
public:
    Rectangle(int w = 0, int h = 0) : Shape(w, h) {}

    int area()override
    {
        cout << "Rectangle class area : " << endl;
        return width * height;
    }
};

class Triangle : public Shape
{
public:
    Triangle(int w = 0, int h = 0) : Shape(w, h) {}

    int area()
    {
        cout << "Triangle class area : " << endl;
        return width * height / 2;
    }
};

void exa1()
{
    Shape *shape;
    Rectangle rec(10, 8);
    Triangle tri(10, 8);

    // 存储矩形的地址
    shape = &rec;
    // 调用矩形的求面积函数
    shape->area();

    // 存储三角形的地址
    shape = &tri;
    // 调用三角形的求面积函数
    shape->area();
}

int main(int argc, char *argv[])
{
    exa1();
    return 0;
}

/*
1、纯虚函数一定没有定义，纯虚函数用来规范派生类的行为，即为接口。
2、包含纯虚函数的类是抽象类，抽象类不能定义实例，
但可以声明指向 实现该抽象类的具体类 的指针或引用。
3、虚函数必须实现，否则编译器会报错。
4、对于虚函数来说，基类和派生类都有各自的版本，由多态方式调用的时候动态绑定。
5、实现了纯虚函数的派生类，该纯虚函数在派生类中就变成了虚函数，派生类的派生类就可覆盖该虚函数，由多态方式调用的时候动态绑定。
6、虚函数是C++中用于实现多态（polymorphism）的机制。核心理念就是通过基类访问派生类定义的函数。
7、在有动态分配堆上内存的时候，析构函数必须是虚函数，但没有必要是纯虚函数。
8、友元不是成员函数，只有成员函数才可以是虚拟的，因此友元不能是虚拟函数。但是可以通过让友元函数调用虚拟成员函数来解决友元的虚拟问题。
9、析构函数应该是虚函数，将调用相应对象类型的析构函数，因此，如果指针指向的是子类对象，将调用子类的析构函数，然后自动调用基类的析构函数。
*/