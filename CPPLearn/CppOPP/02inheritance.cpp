/*
面向对象中最重要的一个概念就是继承。

1、继承允许依据另一个类来定义类，是的创建和维护一个程序变得更容易
2、能够重用代码功能与提高执行效率

-----基类&派生类-----
1、当创建一个类时，您不需要重新编写新的数据成员和成员函数，
只需指定新建的类继承了一个已有的类的成员即可。这个已有的类称为基类，
新建的类称为派生类。

2、一个类可以派生自多个类，即为类可以从多个基类继承数据和函数。
定义一个派生类，我们使用一个类派生列表来指定基类，类派生列表以一个或多个基类命名、
例如：class derived-class(派生类) ： access-specifier(访问修饰符) base-class(基类)
其中访问修饰符为：public、protected和private其中的一个，默认为private。

-----访问控制和继承-----
派生类可以访问基类中所有的非私有成员，
因此基类成员如果不想被派生类的成员函数访问，则应在基类中声明为private。

访问     public    protected    private
同一个类   yes         yes         yes
派生类     yes         yes         no
外部的类   yes         no          no

一个派生类继承了所有的基类方法，但下列情况例外：
1、基类的构造函数、析构函数和拷贝构造函数；
2、基类的重载运算符；
3、基类的友元函数；

-----继承类型（访问修饰符access-specifier指定）-----
                        public  protected   private
1、公有继承（public）：    pub      pro         no
2、保护继承（protected）： pro      pro         no
3、私有继承（private）:    pri      pri         no
注意：公有继承下基类的私有成员不能直接北派生类访问，
但是可以通过调用基类的公有和保护成员来访问。

-----多继承-----
多继承即一个子类可以有多个父类，它继承了多个父类的特性。
C++类可以从副歌类继承成员，语法如下；
class <派生类名> : <继承方式1><基类名1>, <继承方式2><基类名2>, ……
{
    <派生类类体>;
};


-----构造函数调用顺序-----
构造函数调用顺序：基类>成员类>派生类
多继承派生类：《基类构造顺序》依照《基类继承顺序》进行调用
类成员：依照类成员对象的《定义顺序》调用成员类构造函数
*/
#include <iostream>
using namespace std;

// 基类 Shape
class Shape
{
public:
    void setWidth(int w)
    {
        width = w;
    }

    void setHeight(int h)
    {
        height = h;
    }

protected:
    int width;
    int height;
};

// 基类 PaintCost
class PaintCost
{
public:
    int getCost(int area)
    {
        return area * 70;
    }
};

// 继承实例

// 派生类
class Rectangle : public Shape
{
public:
    int getArea()
    {
        return (width * height);
    }
};

void exa1()
{
    Rectangle rect;
    rect.setWidth(1);
    rect.setHeight(2);

    // 输出对象的面积
    cout << "Total area : " << rect.getArea() << endl;
}

// 多继承实例

class Triangle : public Shape, public PaintCost
{
public:
    int getArea()
    {
        return (width * height / 2);
    }
};

void exa2()
{
    Triangle train;
    int area;
    train.setWidth(2);
    train.setHeight(1);

    area = train.getArea();

    // 输出对象的面积
    cout << "Total area : " << train.getArea() << endl;

    // 输出油漆花费
    cout << "Total print cost : $ " << train.getCost(area) << endl;
}

int main()
{
    exa1();
    exa2();
    return 0;
}

/*
-----菱形继承-----
有一种多继承（环状继承是如下格式）
示例：
class D{......};
class B: public D{......};
class A: public D{......};
class C: public B, public A{.....};
图例
    D
A       B
    C

若直接继承会使 D 创建两个对象，要解决此问题则需要用到虚拟继承格式
格式：class 类名 : virtual 继承方式 父类名
示例：
class D{......};
class B: virtual public D{......};
class A: virtual public D{......};
class C: public B, public A{.....};

虚继承：在创建对象的时候回创建一个虚表（在创建父类对象的时候）

Q: 子类的构造函数会在初始化列表里面给父类构造函数传参的原因？

*/