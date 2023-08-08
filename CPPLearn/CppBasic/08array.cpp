// 8 数组

// 数组初始化与赋值

//#include <iostream>
//#include <iomanip>
//
//using namespace std;
//using std::setw;
//
//int main() {
//	int n[10]; // n 是一个包含 10 个整数的数组
//	// 初始化数组元素
//	for (int i = 0; i < 10; i++) {
//		n[i] = i + 100;
//	}
//	// 输出表头
//	cout << "Element" << setw(13) << "Value" << endl;
//	// 输出数组中的元素
//	for (int j = 0; j < 10; j++) {
//		cout << setw(4) << j << setw(15) << n[j] << endl;
//	}
//	return 0;
//}

// 数组的函数调用

// 指向数组的指针

//#include <iostream>
//using namespace std;
//
//int main() {
//	// 带有 5 个元素的整形数组
//	double balance[5] = { 1.1,1.2,1.3,1.4,1.5 };
//	double* p;
//
//	p = balance;
//
//	// 输出数组中每个元素的值
//	cout << "使用指针的数组值" << endl;
//	for (int i = 0; i < 5; i++) {
//		cout << "*(p + " << i << "):";
//		cout << *(p + i) << endl;
//	}
//
//	return 0;
//}

// 传递数组给函数

//#include <iostream>
//using namespace std;
//
//// 函数声明
//double getAverage(int arr[], int size);
//
//int main()
//{
//    // 带有 5 个元素的整型数组
//    int balance[5] = { 1000, 2, 3, 17, 50 };
//    double avg;
//
//    // 传递一个指向数组的指针作为参数
//    avg = getAverage(balance, 5);
//
//    // 输出返回值
//    cout << "平均值是：" << avg << endl;
//
//    return 0;
//}
//
//// 函数定义
//double getAverage(int arr[], int size)
//{
//    int    i, sum = 0;
//    double avg;
//
//    for (i = 0; i < size; ++i)
//    {
//        sum += arr[i];
//    }  
//
//    avg = double(sum) / size;
//
//    return avg;
//}

// 从函数返回数组
// CPP不允许返回一个完整的数组作为函数的参数
// 但是可以通过制定不带索引的数组名来返回一个指向数组的指针

//#include <iostream>
//#include <ctime>
//
//using namespace std;
//
//// 函数声明
//int* getRandom();
//
//int main() {
//	//一个指向整数的指针
//	int* ptr;
//
//	ptr = getRandom();
//	for (int i = 0; i < 10; i++) {
//		cout << "(ptr + " << i << ") = ";
//		cout << *(ptr + i) << endl;
//	}
//	
//	return 0;
//}
//
//// 定义生成随机数数组并返回该数组的函数
//int* getRandom() {
//	static int r[10];
//
//	// 设置种子
//	srand((unsigned)time(NULL));
//	for (int i = 0; i < 10; i++) {
//		r[i] = rand();
//		cout << r[i] << endl;
//	}
//	
//	return r;
//}