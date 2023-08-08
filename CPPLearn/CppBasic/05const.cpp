// 5 const关键字

#include <iostream>
using namespace std;

int main() {
	const int LENGTH = 10;
	const int WIDTH = 5;
	const char END = '\n';
	int area = 0;

	area = LENGTH * WIDTH;
	cout << "area = LENGTH * WIDTH = " << area << END;

	return 0;
}