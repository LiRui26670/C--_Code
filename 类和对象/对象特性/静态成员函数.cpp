//静态成员函数
//·所有对象共享同一个函数
//·静态成员函数只能访问静态成员变量
//·静态成员函数也有访问权限


#include<iostream>
using namespace std;

class Person {
public:
	//静态成员函数
	static void func()
	{
		m_A = 300;
		//m_B = 200;报错，不可访问非静态成员变量
		cout << "static void func调用" << endl;
	}
	static int m_A;
	int m_B = 100;
};

int Person::m_A = 200;
void text01()
{
	//1、通过对象访问
	Person p;
	p.func();
	//2、通过类名访问
	Person::func();
}
int main()
{
	text01();
	return 0;
}