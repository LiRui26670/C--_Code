/*
C++中拷贝构造的调用时机通常有三种情况
		使用一个已经创建完毕的对象来初始化一个新对象
		值传递的方式给函数参数传值
		以值方式返回局部对象
*/

#include<iostream>
using namespace std;


class Person {
public:
	Person()
	{
		cout << "Person默认构造函数的调用" << endl;
	}
	Person(int a)
	{
		cout << "Person有参构造函数的调用" << endl;
		age = a;
	}
	Person(const Person &p)
	{
		cout << "Person拷贝构造函数的调用" << endl;
		age = p.age;
	}
	~Person()
	{
		cout << "Person析构函数的调用" << endl;
	}
	int age;
};

//拷贝构造的调用时机

//1、使用一个已经创建完毕的对象来初始化一个新对象
void text01()
{
	Person p1(20);
	Person p2(p1);
	cout << "P2的年龄为：" << p2.age << endl;
}

//2、值传递的方式给函数参数传值
void dowork(Person p)
{

}
void text02()
{
	Person p;
	dowork(p);
}

//3、以值方式返回局部对象
Person dowork2()
{
	Person p(40);
	cout << (int*)&p << endl;
	return p;
}
void text03()
{
	Person p = dowork2();
	cout << (int*) &p << endl;
}

int main()
{
	//text01();
	//text02();
	text03();
	return 0;
}