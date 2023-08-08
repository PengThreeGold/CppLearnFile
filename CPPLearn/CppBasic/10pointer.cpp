// 10 c++ 指针

// 指针的基础用法

// 获取变量的地址

//#include <iostream>
//
//using namespace std;
//
//int main() {
//	int var1;
//	char var2[10];
//
//	cout << "&var1 : " << &var1 << endl;
//	cout << "&var2 : " << &var2 << endl;
//
//	return 0;
//}

// 常用的指针类型
//int* p; // 一个整型的指针
//double* p; // 一个double型的指针
//float* P; // 一个浮点型的指针
//char* p; // 一个字符型指针

// 使用指针

//#include <iostream>
//
//using namespace std;
//
//int main() {
//	int var = 20; // 实际变量的声明
//	int* p; // 指针变量的声明
//
//	p = &var; // 指针变量中存储 变量var 的地址
//
//	// 输出实际变量的值
//	cout << "var : " << var << endl;
//	// 输出指针变量中存储的地址
//	cout << "p : " << p << endl;
//	// 访问指针变量存储的地址的值
//	cout << "*p : " << *p << endl;
//
//	return 0;
//}

// NULL指针（空指针）
// 在变量声明的时候，如果没有确切的地址可以赋值，为指针变量赋值一个NULL值是一个良好的编程习惯

//#include <iostream>
//
//using namespace std;
//
//int main() {
//	int* ptr = NULL;
//
//	cout << "ptr : " << ptr << endl;
//
//	return 0;
//}

// 指针的算术运算
// 指针是一个用数值表示的地址
// 可以对指针进行四种算术运算：++，--，+，-
// 递增一个指针（递减同理）

//#include <iostream>
//
//using namespace std;
//const int MAX = 3;
//int main() {
//	int var[MAX] = { 10,100,200 };
//	int* ptr = NULL;
//
//	// 指针中的数组地址
//	ptr = var;
//	for (int i = 0; i < MAX; i++) {
//		cout << "var[" << i << "]'s address : " << ptr << endl;
//		cout << "var[" << i << "] : " << *ptr << endl;
//
//		// 移动到下一个位置
//		ptr++;
//	}
//	return 0;
//}

// 指针的比较
// 指针可以用关系运算符进行比较 如==,<和>
// 如果某两个指针同事指向两个相关的变量（同一个数组的不同元素），则可以对其进行大小比较

//#include <iostream>
//
//using namespace std;
//const int MAX = 3;
//
//int main() {
//	int  var[MAX] = { 10, 100, 200 };
//	int* ptr;
//
//	// 指针中第一个元素的地址
//	ptr = var;
//	int i = 0;
//	while (ptr <= &var[MAX - 1]) {
//		cout << "var[" << i << "]'s address : " << ptr << endl;
//		cout << "var[" << i << "] : " << *ptr << endl;
//
//		// 移动到下一个位置
//		ptr++;
//		i++;
//	}
//	return 0;
//}



//#include <iostream>
//
//using namespace std;
//const int MAX = 4;
//
//int main()
//{
//    const char* names[MAX] = {
//        "Zara Ali",
//        "Hina Ali",
//        "Nuha Ali",
//        "Sara Ali",
//    };
//
//    for (int i = 0; i < MAX; i++)
//    {
//        cout << "Value of names[" << i << "] = ";
//        cout << *names[i] << endl;
//    }
//    return 0;
//}

// 函数指针
// 例如：int (*fp)(int a);
// 这里就定义了一个指向函数
// (这个函数参数仅仅为一个 int 类型，函数返回值是 int 类型)的指针 fp

//int a(int b) {
//	cout << b << endl;
//	return ++b;
//}
//int(*p)(int);
//p = a;

// CPP中指针分配与释放一个空间

//#include <iostream>
//using namespace std;
//int main() {
//	// 分配
//	int* p;
//	p = new int;
//	*p = 3;
//	delete p;
//	p = NULL;
//
//	int* p;
//	p = new int(3);
//	delete p;
//	p = NULL;
//
//	int* p;
//	p = new int[4];
//	delete []p;
//	p = NULL;
//}

// 例子：利用动态内存技术实现不定长度的整型数组的输入和输出。

//#include <iostream>
//using namespace std;
//
//int main() {
//	int n = 0;
//	cout << "请输入数组的长度：";
//	cin >> n;
//	int* p = new int[n];
//	if (p != NULL) {
//		for (int i = 0; i < n; i++) {
//			p[i] = i + 1;
//		}
//		for (int j = 0; j < n; j++) {
//			cout << p[j] << " ";
//		}
//		cout << endl;
//	}
//	else {
//		cout << "分配内存空间失败！" << endl;
//	}
//	delete[]p;
//	p = nullptr;
//	return 0;
//}

// 例子：使用void指针作为函数的参数。实现两个数的交换。

//#include <iostream>
//#include <string>
//using namespace std;
//
//void swap(void* x, void* y, int size);
//
//void swap(void* x, void* y, int size) {
//	char temp;
//	for (int i = 1; i < size; i++) {
//		temp = *((char*)x + (i - 1));
//		*((char*)x + (i - 1)) = *((char*)y + (i - 1));
//		*((char*)y + (i - 1)) = temp;
//	}
//}
//
//int main() {
//	int x = 0, y = 0;
//	string s1, s2;
//	cout << "请输入x,y的值：";
//	cin >> x >> y;
//	swap(&x, &y, sizeof(x));
//	cout << "x=" << x << " y=" << y << endl;
//
//	cout << "请输入两个字符串：";
//	cin >> s1 >> s2;
//	swap(&s1, &s2, sizeof(s1));
//	cout << "s1=" << s1 << " s2=" << s2 << endl;
//	return 0;
//}

// 指针类型的强制转换
// #include <iostream>
// #include <cstdlib>

// using namespace std;

// int main() {
// 	char char_arr[4] = { 0x12,0x34,0x56,0x78 };
// 	char* ptr = char_arr;
	
// 	// hex输出必须对应int类型，否则输出ASCII码
// 	cout << "value of *ptr " << hex << (int)(*ptr) << endl;
// 	cout << "value of *ptr " << hex << (int)(*(int *)ptr) << endl;

// 	return 0;
// }