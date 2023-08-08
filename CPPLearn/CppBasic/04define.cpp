// 4.define 预处理器

#include <iostream>
using namespace std;

#define LENGTH 10
#define WIDTH 5
#define END endl

int main() {
	int area = 0;
	area = LENGTH * WIDTH;

	cout << "area = LENGTH * WIDTH = " << area << END;
	
	return 0;
}
