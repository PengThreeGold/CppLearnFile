// 9 字符串

// 字符串基本函数（C语言string类）

//// 解决函数不安全警告
//#define _CRT_SECURE_NO_WARNINGS
//
//#include <iostream>
//#include <cstring>
//
//using namespace std;
//
//int main() {
//	char str1[11] = "Hello";
//	char str2[11] = "World";
//	char str3[11];
//	int len;
//
//	// 复制 str1 到 str3
//	strcpy(str3, str1);
//	cout << "strcpy(str3, str1) : " << str3 << endl;
//
//	// 连接 str1 与 str2
//	strcat(str1, str2);
//	cout << "strcat(str3, str1) : " << str1 << endl;
//
//	// 输出连接后 str1 的总长度
//	len = (int)strlen(str1);
//	cout << "strlen(str1) : " << len << endl;
//
//	return 0;
//}

// 字符串基本函数（Cpp语言string类）

//#include <iostream>
//#include <string>
//
//using namespace std;
//
//int main() {
//    string str1 = "Hello";
//    string str2 = "World";
//    string str3;
//    int  len;
//
//    // 复制 str1 到 str3
//    str3 = str1;
//    cout << "str3 : " << str3 << endl;
//
//    // 连接 str1 和 str2
//    str3 = str1 + str2;
//    cout << "str1 + str2 = " << str3 << endl;
//
//    // str3的长度
//    len = str3.size();
//    cout << "str3.size() : " << len << endl;
//
//    return 0;
//}


// 字符串读取方式 cin.getline()

//#include <iostream>
//
//using namespace std;

//#define N 100
//
//int main() {
//	char X[N];
//	// 输入
//	cin.getline(X, N);
//	int a = 0, b = 0;
//	for (int i = 0; i < N; i++) {
//		if (X[i] == '#')
//			break;
//		if (X[i] >= '0' && X[i] <= '9')
//			a++;
//		if ((X[i] >= 'a' && X[i] <= 'z') || (X[i] >= 'A' && X[i] <= 'Z'))
//			b++;
//	}
//	cout << "The digital : " << a << endl;
//	cout << "The char : " << b << endl;
//
//	return 0;
//}

// cstring 操作

// a、创建详解

//#include <iostream>
//#include <algorithm>
//#include <cmath>
//#include <cstring>
//#include <cstdio>
//
//using namespace std;
//int main()
//{
//
//    //1. 字符串的创建
//    cout << "第一:字符串的创建!\n\n";
//    string a(4, 'a');
//    cout << "1.以 a 为原字符 4单位大小\n\n";
//    cout << "string a(4,'a');\ncout<<a<<endl;\n";
//    cout << a << endl << endl;
//
//    cout << "2.任意大小的字符串\n\n";
//    cout << "string b(\"bbbbbb\");\ncout<<b<<endl;\n";
//    string b("bbbbbb");
//    cout << b << endl << endl;
//
//    cout << "3.把某一字符串的某一部分\n(0位置开始4个长度)给c\n\n";
//    cout << "string c(a,0,4) ;\ncout<<c<<endl;\n";
//    string c(a, 0, 4);
//    cout << c << endl << endl;
//
//    cout << "4. 10长度原长度不足补*;\n\n";
//    cout << "c.resize(10,'*');\ncout<<c<<endl;\n";
//    c.resize(10, '*');
//    cout << c << endl << endl;
//
//    system("pause");
//    system("cls");
//    return 0;
//}

// b、assign()、copy()详解

//#include <iostream>
//#include <algorithm>
//#include <cmath>
//#include <cstring>
//#include <cstdio>
//
//using namespace std;
//
//int main() {
//
//	// 字符串的赋值 assign() 
//	// 操作：抹除-覆盖
//
//	string e;
//	char f[10] = "123456";
//	e.assign(f);
//	e += ' ';
//	cout << e << endl;
//
//	// string区间 赋值
//	e.assign(f, 3, 3);
//	e += " ";
//	cout << e << endl;
//	e.assign(f, 3);
//	cout << e << endl;
//
//	// 某字符串char型 全部
//	char ssr[10] = "123456789";
//	e.assign(ssr);
//	cout << e << endl;
//
//	// 某字符串char型 前num个
//	e.assign(ssr, 4);
//	cout << e << endl;
//
//	// 某字符赋值
//	e.assign(3, '6');
//	cout << e << endl;
//
//	// 区间复制 copy()
//	char ss[16] = "123";
//	string dd("abcdefghijklmn");
//	dd.copy(ss, 12, 2);
//	cout << ss << endl;
//	return 0;
//}

// c、append()详解及其扩展（int、char）

//#include <iostream>
//#include <algorithm>
//#include <cmath>
//#include <cstring>
//#include <cstdio>
//
//using namespace std;
//
//int main() {
//
//	// 在字符串的末尾添加字符串（全部）
//
//	string a("string a");
//	string b("string b");
//	cout << a << endl << b << endl;
//	b.append(a);
//	cout << b << endl;
//
//	// 在字符串的末尾添加字符串（区间）
//	string c("cccc");
//	b.append(c, 0, 2);
//	cout << b << endl;
//
//	// 添加4个 ~ 字符
//	b.append(4, '~');
//	cout << b << endl;
//
//	// char 列表型添加 
//	char char1[100] = "year!";
//	string str("-_-");
//	str.append(char1);
//	cout << str << endl;
//	char char2[100] = "0123456";
//	str.append(char2, 6, 7);
//	cout << str << endl;
//
//	// int double 类型通过sprintf() <cstdio>作为转接
//#define _CRT_SECURE_NO_WARNINGS
//	int int_1 = 123456;
//	double dou_1 = 3.1415;
//	char char_1[10];
//	sprintf(char_1, "%d", int_1);
//	string str_1("");
//	str_1.append(char_1, 0, 7);
//	cout << str_1 << endl;
//	sprintf(char_1, "%f", dou_1);
//	str_1.append(char_1, 0, 6);
//	cout << str_1 << endl;
//
//	return 0;
//}

// C++中常见的几种输入字符串的方法如下
// cin cin.get() cin.getline() getline() gets() getchar()

// cin 最常用最基本的用法

//// 用法一：输入一个数字
//#include <iostream>
//using namespace std;
//int main() {
//	int a, b;
//	cin >> a >> b;
//	cout << "a+b=" << a + b << endl;
//	return 0;
//}
//
//// 用法二：接受一个字符串，遇见“空格”、“Tab”和“回车”都结束
//#include <iostream>
//using namespace std;
//int main() {
//	char a[10];
//	cin >> a;
//	cout << a << endl;
//	return 0;
//}
//
//// cin.get()
//
//// 用法一：cin.get(字符变量名)用来接受字符
//#include <iostream>
//using namespace std;
//int main() {
//	char ch;
//	ch = cin.get(); // 或者cin.get(ch);只能获取一个字符
//	cout << ch << endl;
//	return 0;
//}
//
//// 用法二：cin.get(字符数组名，接收字符数)用来接收一行字符串，可以接收空格
//#include <iostream>
//using namespace std;
//int main() {
//	char a[20];
//	cin.get(a, 20); // 类似getline()。可以输入多个单词，中间空格隔开
//	cout << a << endl;
//	return 0;
//}
//
//// 用法三：cin.get(无参数)没有参数主要是用于舍弃输入流中不需要的字符
//// 或者回车，弥补cin.get(字符数组名，接收字符数目)的不足
//#include <iostream>
//using namespace std;
//int main() {
//	char arr[10];
//	cin.get(arr, 10);
//	cin.get(); // 用于吃掉回车，相当于getchar()
//	cout << arr << endl;
//	cin.get(arr, 5);
//	cout << arr << endl;
//	return 0;
//}

// cin.getline() 接收一个字符串，可以接收空格并输出

//// 常规用法
//#include <iostream>
//using namespace std;
//int main() {
//	char m[20];
//	cin.getline(m, 5); // 与上面基本相同
//	cout << m << endl;
//	return 0;
//}
////输入：jkljkljkl
////输出：jklj
//// 其中最后一个为'\0'
//
//// 延伸
//// cin.getline(字符串接收对象, 接收个数，结束字符)
//// 多维数组 例如：cin.getline(m[i], 20)
//

// getline() 接收一个字符串，可以接收空格并输出，需包含<string>

//#include <iostream>
//#include <string>
//using namespace std;
//int main() {
//	string str;
//	getline(cin, str);
//	cout << str << endl;
//	return 0;
//}
///*和cin.getline()类似，
//但是cin.getline()属于istream流，
//而getline()属于string流，
//是不一样的两个函数*/

// gets()/gets_s() 接收一个字符串，可以接收空格并输出，需要包含<string>

//#include <iostream>
//#include <string>
//
//using namespace std;
//int main() {
//	char m[20];
//	gets_s(m); // 不能写成m=gets()
//	cout << m << endl;
//	return 0;
//}

// C++11 原始字符串输出

//#include <iostream>
//using namespace std;
//int main() {
//	cout << R"(原始\t字\n符串)" << endl;
//	return 0;
//}