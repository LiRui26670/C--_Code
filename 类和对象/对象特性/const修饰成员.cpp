/*

常函数：
		·成员函数后加const后，我们称这个函数为常函数
		·常函数内不可以修改成员属性
		·成员属性声明时加关键字mutable后，在常函数中依然可以修改

常对象：
		·声明对象前加const称该对象为常对象
		·常对象只能调用常函数

*/

#include<iostream>
using namespace std;

class Person {
public:
	void showPerson()const
	{

		//this指针的本质为指针常量  Person * const this ，此时this指针指向的对象不能变，但是可以通过this指针修改指向对象的值
		//而常函数后加的const 则将this 转换为 const Person * const this 
		//this->m_A = 100;报错
		m_B = 100;
	}

	void show()
	{

	}

	int m_A;
	mutable int m_B;//特殊变量，在常函数中也可修改值
};
void text01()
{
	Person p;
	p.showPerson();
}

//常对象
void text02()
{
	const Person p;//常对象

	p.m_A = 100;//报错
	p.m_B = 100;//可以执行

	//常对象只能调用常函数
	p.showPerson();//可以执行
	p.show();//报错
}