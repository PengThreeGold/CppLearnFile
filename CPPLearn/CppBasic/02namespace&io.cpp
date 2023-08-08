// 2 命名空间与输入输出

#include <iostream>
#include <string>

int main() {
	// 声明命名空间std
	using namespace std;

	// 定义字符串变量
	std::string str;
	// 定义int变量
	int age;
	// 从控制台获取用户输入
	cin >> str >> age;
	// 将数据输出到控制台
	cout << str << ",已经" << age << "岁了！" << endl;

	return 0;
}