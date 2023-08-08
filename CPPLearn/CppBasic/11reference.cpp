// 11引用

// 引用变量是一个别名，也就是说它是某个已存在变量的另一个名字
// 一旦把引用初始化为某个变量，就可以使用该引用名称或变量名称指向该变量

// c++ 引用 vs 指针
/*
引用和指针容易混淆，它们之间主要有三个不同点：
1、不存在空引用。引用必须连接到一块合法的内存。
2、一旦引用被初始化为一个对象，就不能被指向到另一个对象。指针可以在任何时候指向到另一个对象。
3、引用必须在创建时被初始化。指针可以在任何时间被初始化。
*/

// 实例
#include <iostream>
using namespace std;

// 基本引用用法
void exa1(){
		// 声明简单的变量
	int i = 0;
	double d = 0.0;

	// 声明引用变量
	int& i_ = i;
	double& d_ = d;

	i = 123;
	cout << "Value of i: " << i << endl;
	cout << "Value of i_(i reference): " << i_ << endl;
	d = 3.14;
	cout << "Value of d: " << d << endl;
	cout << "Value of d_(d reference)" << d_ << endl;
}

// 把引用作为参数
void swap(int& x, int& y){
	int temp = x; // 保存地址为 x 的值
	x = y;
	y = temp;
}

void exa2(int x, int y){
	cout << "交换前x: " << x << endl;
	cout << "交换前y: " << y << endl;
	swap(x,y);
	cout << "交换后x: " << x << endl;
	cout << "交换后y: " << y << endl;
}

// 把引用作为返回值
/*
当函数返回一个引用时，则返回一下指向返回值的隐式指针，
这样函数就可以放在赋值语句的左边。
同时引用作为返回值必须遵守以下规则：
1、不能返回局部变量（用后销毁）
2、不能返回函数内部new分配内存的引用。（临时变量无法释放->memory leak（内存泄漏））
3、可以返回类成员的引用，但最好是const。
*/
double vals[] = { 1.0, 1.1, 1.2, 1.3 ,1.5 };

double& setValues(int i){
	double& ref = vals[i];
	return ref; // 返回第 i 个元素的引用，ref是一个引用变量（引用vals[i]）。
}

void exa3(){
	cout << "改变前的值" << endl;
	for ( int i = 0; i < 5; i++ ){
		cout << "vals[" << i << "] = " << vals[i] << endl;
	}

	setValues(4) = 1.4;

	cout << "改变后的值" << endl;
	for ( int i = 0; i < 5; i++ ){
		cout << "vals[" << i << "] = " << vals[i] << endl;
	}
}

int main(){
	// exa1();
	// exa2(10,20);
	exa3();
	return 0;
}