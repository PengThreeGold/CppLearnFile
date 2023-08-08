#include <iostream>
using namespace std;

/*
C++允许在同一个作用域中的某个函数和运算符指定多个定义，
成别称为函数重载和运算符重载。

重载声明：指一个与之前已经在该作用域内声明过得函数或方法具有相同名称的声明，
但是他们的参数列表和定义（实现）不相同。

重载决策：当调用一个重载函数或重载运算符时，
编译器通过把您所使用的参数类型与定义中的参数类型进行比较，
决定选用最合适的定义，编译器选择最合适的重载函数或重载运算符的过程称为重载决策。
*/

// -----函数重载-----
/*
同作用域内，可以声明几个功能类似的同名函数，
但是这些同名函数的形式参数（参数的个数、类型或顺序）必须不同，
不能仅通过返回类型的不同来重载函数。
*/
// 代码实例：
class printData
{
public:
    void print(int i)
    {
        cout << "整数为：" << i << endl;
    }

    void print(double f)
    {
        cout << "浮点数为：" << f << endl;
    }

    void print(char c[])
    {
        cout << "字符串为：" << c << endl;
    }
};

// -----运算符重载-----
/*
C++支持重定义或重载大部分内置的运算符，因此可以使用自定义类型的运算符。
重载的运算符是带有特殊名称的函数，函数名是由关键字operator和其后要重载的运算符符号构成的。
与其他函数一样，重载运算符有一个返回类型和一个参数列表。
*/

/*
声明加法运算符用于把两个Box对象相加，返回最终的Box对象。
Box operator+(const Box&)
大多数的重载运算符可被定义为 普通的非成员函数 或 类的成员函数。
如果我们定义上面的函数为类的非成员函数，则我们需要为每次操作传递两个参数，如下所示：
Box operator+(const Box&, const Box&)
*/

// 代码实例：（对象作为参数进行传递，对象的属性使用this运算符进行访问）
class Box
{
public:
    double getV()
    {
        return length * breadth * height;
    }

    void setL(double len)
    {
        this->length = len;
    }

    void setB(double bre)
    {
        this->breadth = bre;
    }

    void setH(double hei)
    {
        this->height = hei;
    }

    // 重载“+”运算符，用于把两个Box对象相加
    Box operator+(const Box &b)
    {
        Box box;
        box.length = this->length + b.length;
        box.breadth = this->breadth + b.breadth;
        box.height = this->height + b.height;
        return box;
    }

private:
    double length;
    double breadth;
    double height;
};

void exa1()
{
    Box box1;
    Box box2;
    Box box3;
    double Volume;

    box1.setL(1.0);
    box1.setB(2.0);
    box1.setH(3.0);

    box2.setL(4.0);
    box2.setB(5.0);
    box2.setH(6.0);

    Volume = box1.getV();
    cout << "Volume of box1 : " << Volume << endl;
    Volume = box2.getV();
    cout << "Volume of box2 : " << Volume << endl;

    // 利用重载运算符“+”将两个Box对象相加
    box3 = box1 + box2;

    Volume = box3.getV();
    cout << "Volume of box3 : " << Volume << endl;
}

int main(int argc, char *argv[])
{
    exa1();
    return 0;
}

/*
运算符重载注意事项
1、不改变语法结构
2、不改变操作数的个数
3、不改变优先级
4、不改变结合性
*/

/*
类的重载、覆盖、重定义的区别

重载：重载指的是函数具有不同的参数列表，而函数名相同。
重载要求函数参数列表必须不同，其中包含参数的类型不同、个数不同、顺序不同。
如果仅仅是函数的返回值不同是不能完成重载的。

覆盖：覆盖是存在类中，子类重写从基类继承过来的参数。被重写的函数不能是静态（static）的，必须是virtual的。
但是函数名、返回值、参数列表都必须和基类相同（发生在基类和子类）。

重定义：重定义也叫做隐藏，子类重新定义父类中相同名称的非虚函数（参数列表可以不同）。（发生在基类和子类）
*/