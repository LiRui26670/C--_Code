//this 指针指向被调用的成员函数所属的对象

//this指针是隐含每一个非静态成员函数内的一种指针
//this指针不需要定义，直接使用

//this指针的用途
//		·当形参和成员变量同名时，用this指针区分
//		·在类的非静态成员函数中返回对象本身，用return *this


#include<iostream>
using namespace std;

//·当形参和成员变量同名时，用this指针区分
class Person {
public:
	Person(int age) 
	{
		this->age = age;
	}

	Person & Add(const Person& p)//返回值为引用，不然返回的是匿名对象，text02中链式语句后续对象不再是p2
	{
		this->age += p.age;
		return *this;
	}

	int age;//都用age，不能成功构造，两种办法：1、成员变量命名为m_age(推荐用法)  2、用this指针
};

void text01() 
{
	Person p(18);
	cout << p.age << endl;
}

//·在类的非静态成员函数中返回对象本身，用return *this
void text02()
{
	Person p1(10);
	Person p2(10);
	p2.Add(p1).Add(p1).Add(p1);
	cout << "p2 的年龄为：" << p2.age << endl;
}

int main()
{
	//text01();
	text02();
	return 0;
}