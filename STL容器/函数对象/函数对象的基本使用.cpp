/*
函数对象
·概念：重载函数调用操作符的类，其对象称为函数对象
·函数对象使用重载()时，行为类似函数调用，也叫仿函数
本质：
·函数对象是一个类，不是函数

函数对象使用特点：
·可以像普通函数那样调用，有参数和返回值
·函数对象超出普通函数的概念，函数对象可以有自己的状态
·函数对象可以作为参数传递

*/

#include<iostream>
using namespace std;
#include<string>

class Myadd
{
public:
	int operator()(int v1,int v2)
	{
		return v1 + v2;
	}
};

class Myprint
{
public:
	void operator()(string str)
	{
		cout << str << endl;
		this->m_count++;
	}

	int m_count = 0;;
};
//·可以像普通函数那样调用，有参数和返回值
void text01()
{
	Myadd myadd;
	cout << myadd(10, 20) << endl;
}

//·函数对象超出普通函数的概念，函数对象可以有自己的状态
void text02()
{
	Myprint myprint;
	myprint("Hello c++");
	myprint("Hello c++");
	myprint("Hello c++");
	myprint("Hello c++");
	//如果是普通函数，统计调用次数要用全局变量或静态变量，而函数对象则用这种方式
	cout << myprint.m_count << endl;
}

//·函数对象可以作为参数传递
void doprint(Myprint& mp, string str)
{
	mp(str);
}
void text03()
{
	Myprint myprint;
	doprint(myprint, "Hello c++!");
}

int main()
{
	//text01();
	//text02();
	text03();
	return 0;
}