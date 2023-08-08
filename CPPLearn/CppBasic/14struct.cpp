#include <iostream>
#include <cstring>

using namespace std;

void prinbook(struct Books book);
void prinbook_ptr(struct Books *book);

struct Books{
	char title[50];
	char author[50];
	char subject[100];
	int book_id;
};

// typedef 关键字
typedef struct Student{
	char name[50];
    int age;
} Student;
// typedef 关键字定义非结构类型
typedef long int *li; // 长整型指针结构类型

int main(){
	// 常用结构定义
	Books Book1;
	Books Book2;

	// Book1定义
	strcpy(Book1.title, "C++ 教程");
	strcpy(Book1.author, "李四");
	strcpy(Book1.subject, "编程语言");
	Book1.book_id = 1;

	// Book2定义
	strcpy(Book2.title, "Java 教程");
    strcpy(Book2.author, "张三");
    strcpy(Book2.subject, "编程语言");
    Book2.book_id = 2;

    prinbook(Book1);
    prinbook(Book2);

	prinbook_ptr(&Book1);
	prinbook_ptr(&Book2);

	// typedef 结构
	Student Student1;
	cout << Student1.name << " " << Student1.age << endl;

	return 0;
}

void prinbook(struct Books book){
	cout << "using theirself" << endl;
	cout << "Book title: " << book.title << endl;
    cout << "Book author: " << book.author << endl;
    cout << "Book subject: " << book.subject << endl;
    cout << "Book book_id: " << book.book_id << endl;
}

void prinbook_ptr(struct Books *book){
	cout << "using theirptr" << endl;
	cout << "Book title: " << book->title << endl;
    cout << "Book author: " << book->author << endl;
    cout << "Book subject: " << book->subject << endl;
    cout << "Book book_id: " << book->book_id << endl;
}
