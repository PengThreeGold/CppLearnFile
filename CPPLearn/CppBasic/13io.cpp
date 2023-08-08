#include <iostream>
#include <iomanip>

using namespace std;

int main(){
	// 设置左对齐，以一般实数方式显示
	cout << setiosflags(ios::left | ios::showpoint);
	// 设置除小数点外有五位有效数字
	cout.precision(5);
	cout << 123.456789 << endl;

	// 设置显示域宽 10
	cout.width(10);
	// 设置在显示域空白处用 * 填充
	cout.fill('*');
	// 清除左对齐状态
	cout << resetiosflags(ios::left);
	// 设置右对齐
	cout << setiosflags(ios::right);
	cout << 123.456789 << endl;

	// 设置左对齐，以固定小数位显示
	cout << setiosflags(ios::left | ios::fixed);
	// 设置实数显示三位小数
	cout.precision(3);
	cout << 123.456789 << endl;

	// 清除左对齐和定点格式状态
	cout << resetiosflags(ios::left | ios::fixed);
	// 设置左对齐，以科学计数法显示
	cout << setiosflags(ios::left | ios::scientific);
	// 设置保留三位小数
	cout.precision(3);
	cout << 123.456789 << endl;

	return 0;
}