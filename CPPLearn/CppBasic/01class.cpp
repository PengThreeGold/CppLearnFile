// 1 类的基本定义

#include <stdio.h>
#include <string>

class student {  // 通过class关键字类定义类
public:
	// 类包含的变量
	char name;
	int age;
	float score;
	// 类包含的函数
	void say() {
		printf("%c的年龄是：%d，成绩是：%f\n", name, age, score);
	}
};

int main() {
	// 通过类来定义变量，即创建对象
	class student stu_1;  // 也可以省略关键字class
	stu_1.name = 'p';
	stu_1.age = 22;
	stu_1.score = 100;
	// 调用类的成员函数
	stu_1.say();

	return 0;
}