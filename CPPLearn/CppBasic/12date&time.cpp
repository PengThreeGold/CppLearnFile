// 12 日期和时间
/*
C++标准库中没有提供所谓的日期类型。
C++继承了C语言用于日期和时间操作的结构和函数。
为了使用日期和时间相关的函数和结构，需要在C++程序中引用<ctime>头文件。
有四个与时间相关的类型：
clock_t, time_t, size_t, tm
clock_t,size_t和time_t能够把系统时间和日期表示为某种整数
结构类型tm把日期和时间以C结构的形式保存
tm结构的定义如下：
struct tm {
	int tm_sec; // 秒，正常范围从 0 到 59，但允许至 61
	int tm_min; // 分，范围从 0 到 59
	int tm_hour; // 小时，范围从 0 到 23
	int tm_mday; // 天，一个月中的第几天，范围从 1 到 31
	int tm_mon;   // 月，范围从 0 到 11
	int tm_year;  // 自 1900 年起的年数
	int tm_wday;  // 一周中的第几天，范围从 0 到 6，从星期日算起
	int tm_yday;  // 一年中的第几天，范围从 0 到 365，从 1 月 1 日算起
	int tm_isdst; // 夏令时
}
*/
#include <iostream>
#include <ctime>

using namespace std;

void exa1(){
	// 基于当前系统的当前日期与时间
	time_t now = time(0);

	// 把 now 转换为字符串形式
	char* dt = ctime(&now);

	cout << "本地日期和时间：" << dt << endl;
	
	// 把 now 转换为 tm 结构
	tm *gmtm = gmtime(&now);
	dt = asctime(gmtm);
	cout << "UTC日期和时间：" << dt << endl;
}

void exa2(){
	// 基于当前系统的当前时间与日期
	time_t now = time(0);

	cout << "1970到当前时间的总秒数：" << now << endl;

	tm *ltm = localtime(&now);

	// 输出 tm 结构的各个组成部分
	cout << "年：" << 1900 + ltm->tm_year << endl;
	cout << "月：" << 1 + ltm->tm_mon << endl;
    cout << "日：" << 1 + ltm->tm_mday << endl;
	cout << "时间：" << ltm->tm_hour << ":" 
	<< ltm->tm_min << ":" << ltm->tm_sec << endl;
}

void exa3(){
	time_t now;
	now = time(NULL); // 获取日历时间
	char tmp[64];
	strftime(tmp, sizeof(tmp), "%Y-%m-%d %H:%M:%S", localtime(&now));
	cout << string(tmp) << endl;
}

int main(){
	// exa1();
	// exa2();
	exa3();
	return 0;
}