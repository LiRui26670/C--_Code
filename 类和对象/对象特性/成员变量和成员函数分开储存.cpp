//C++中，类内成员变量和成员函数分开存储
//只有非静态成员变量才属于类的对象上

#include<iostream>
using namespace std;

class Person {

	int m_A;//非静态成员变量     属于类的对象

	static int m_B;//静态成员变量    不属于类的对象

	void func1()//非静态成员函数   不属于类的对象
	{

	}

	static void func2()//静态成员函数    不属于类的对象
	{

	}
};
int Person::m_B = 10;

void text01()
{
	Person p;
	//空对象占用内存空间为 1个字节
	cout << "size of p = " << sizeof(p) << endl;
}

void text02()
{
	Person p;
	
	cout << "size of p = " << sizeof(p) << endl;

	cout << "size of Person = " << sizeof(Person) << endl;
}

int main()
{
	//text01();
	text02();
	return 0;
}