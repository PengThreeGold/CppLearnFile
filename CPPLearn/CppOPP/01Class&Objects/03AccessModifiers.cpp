#include <iostream>

using namespace std;

/*
	数据封装是面向对象编程的一个重要特点，
	它防止函数直接访问类类型的内部成员，
	类成员的访问限制是通过在类主体内部对各个区域标记：
	public, private, protected来指定的（访问修饰符）
*/
/*
	一个类可以有多个标记区域，
	每个标记区域在下一个标记区域开始之前
	或者在遇到类主体结束右括号之前都是有效的
	成员和类的默认访问修饰符是private。
*/

class Base{
	public:
		// 共有成员
		// 在程序中类的外部是可以访问的
		// 可以不使用人格成员函数来设置和获取公有变量的值

	private:
		// 私有成员
		// 成员变量或函数在类的外部是不可访问的（不可查看）
		// 只有 类 和 友元函数 可以访问私有成员
		// 默认即为私有

	protected:
		// 受保护成员
		// 派生类（子类）是可访问的
};

// 公有成员实例 

////
class Line
{
    public:
        double length;
        void setLength( double len );
        double getLength( void );
};

// 成员函数定义
double Line::getLength(void)
{
    return length ;
}

void Line::setLength( double len )
{
    length = len;
}

void PublicExa(){
	Line line;

    // 设置长度
    line.setLength(6.0); 
    cout << "Length of line : " << line.getLength() <<endl;

    // 不使用成员函数设置长度
    line.length = 10.0; // OK: 因为 length 是公有的
    cout << "Length of line : " << line.length <<endl;
    
}
////

// 私有成员实例
////
class Box
{
    public:
        double length;
        void setWidth( double wid );
        double getWidth( void );
    
    private:
        double width;
};

// 成员函数定义
double Box::getWidth(void)
{
    return width ;
}

void Box::setWidth( double wid )
{
    width = wid;
}

void PrivateExa(){
	Box box;

    // 不使用成员函数设置长度
    box.length = 10.0; // OK: 因为 length 是公有的
    cout << "Length of box : " << box.length <<endl;

    // 不使用成员函数设置宽度
    // box.width = 10.0; // Error: 因为 width 是私有的
    box.setWidth(10.0);  // 使用成员函数设置宽度
    cout << "Width of box : " << box.getWidth() <<endl;
}
////

// 受保护成员实例
////
// 父类
class Animal{
    protected:
        string name;
};

// 子类（派生类）
class Dog:Animal{
    public:
        void setDogname(string name_);
        string getDogname(void);
};

// 子类成员函数
void Dog::setDogname(string name){
    this->name = name;
}

string Dog::getDogname(){
    return name;
}

void ProtectedExa(){
    Dog Dog1;
    Dog1.setDogname("lizhihao");
    cout << "Name of this dog : " << Dog1.getDogname() << endl;
}
////

// 继承中的特点

// 有public, protected, private三种继承方式
// 
/*
                   基类 public 成员 | protected成员 | private成员
    1、public继承：     public        protected       private
    2、protected继承：  protected     protected       private
    3、private继承：    private       private         private
*/

int main( )
{
    // PublicExa();
    // PrivateExa();
    ProtectedExa();
    return 0;
}
