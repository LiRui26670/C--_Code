//静态成员就是在成员变量和成员函数前加上关键字static

//静态成员变量
//·所有对象共享一份数据
//·在编译阶段分配内存
//·类内声明，类外初始化
//·静态成员变量也有访问权限

#include<iostream>
using namespace std;

class Person {
public:
	static int m_A;//类内声明

};

//类外初始化
int Person:: m_A = 100;

void text01()
{
	Person p;
	cout << p.m_A << endl;

	Person p2;
	p2.m_A = 200;
	cout << p.m_A << endl;
}

void text02()
{
	//静态成员变量，不属于某个对象，所有对象共享
	//因此静态成员变量有两种访问方式

	//1、通过对象访问
	Person p;
	cout << p.m_A << endl;
	//2、通过类名访问
	cout << Person::m_A << endl;

}
int main()
{
	//text01();
	text02();
	return 0;
}