// 3 字符串的使用方式

#include <iostream>

int main() {
	using namespace std;

	std::string str_1 = "hello, dear";
	std::string str_2 = "hello, \
dear";
	std::string str_3 = "hello," " d" "ear";

	cout << "str_1:" << str_1 << endl;
	cout << "str_2:" << str_2 << endl;
	cout << "str_3:" << str_3 << endl;

	return 0;
}