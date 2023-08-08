// 6 存储类

// auto存储类是所有局部变量默认的存储类
//{
//	int mount;
//	auto int mount;
//}

// register存储类（只用于需要快速访问的变量，仅仅为可能存在）
// register存储类用于定义存储在寄存器中而不是RAM中的局部变量
// 最大尺寸等于寄存器的大小&不能应用一元'&'运算符（无内存位置）
//{
//	register int miles;
//}

// static存储类
// 指示编译器在程序的生命周期保持局部变量的存在（保持局部变量的值）
// 修饰全局变量时，会使变量的作用域限制在他的声明文件中
// 用于类数据成员上时，会导致仅有一个该成员的副本被类的所有对象共享

//#include <iostream>
//
//// 函数声明
//void func(void);
//
//static int count = 10; // 全局变量
//
//int main() {
//	while (count--) {
//		func();
//	}
//
//	return 0;
//}
//
//// 函数定义
//void func() {
//	static int i = 5; // 静态局部变量
//	i++;
//	std::cout << "变量 i 为 " << i;
//	std::cout << "，变量 count 为 " << count << std::endl;
//}

// extern存储类（用于提供一个全局变量的引用）
// 对于无法初始化的变量，会把变量名指向一个之前定义过的存储位置
// 通常用于当有两个或多个文件共享相同的全局变量或函数的时候

//// mian.cpp
//#include <iostream>
//
//int count;
//extern void write_extern();
//
//int main() {
//	count = 5;
//	write_extern();
//	return 0;
//}
// 
//// support.cpp
//extern int count;
//
//void write_extern(void) {
//	std::cout << "count is " << count << std::endl;
//}

// mutabable存储类