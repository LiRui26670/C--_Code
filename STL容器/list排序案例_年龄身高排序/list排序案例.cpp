/*
案例要求
数据类型

自定义 Person 类，包含以下属性：

姓名

年龄

身高

排序规则（list排序）

主排序：按年龄升序排列（从小到大）

次排序：若年龄相同，则按身高降序排列（从高到矮）

*/


#include<iostream>
using namespace std;
#include<string>
#include<list>

//Person类
class Person
{
public:

	Person(string name, int age, double height)
	{
		this->m_Name = name;
		this->m_Age = age;
		this->m_Height = height;
	}
	string m_Name;
	int m_Age;
	double m_Height;
};

//打印函数
void printPerson(const list<Person>& L)
{
	for (list<Person>::const_iterator it = L.begin(); it != L.end(); it++)
	{
		cout << "姓名：" << it->m_Name << " 年龄：" << it->m_Age << " 身高：" << it->m_Height << endl;
	}
}

//list排序必需函数
bool mysort(Person &p1,Person &p2)
{
	if (p1.m_Age == p2.m_Age)
	{
		return p1.m_Height > p2.m_Height;
	}
	return p1.m_Age < p2.m_Age;
}
int main()
{
	//创建容器
	list<Person> L;

	//给几个Person赋值
	Person p1("刘备 ", 35 , 175);
	Person p2("曹操 ", 45 , 180);
	Person p3("孙权 ", 40 , 170);
	Person p4("赵云 ", 25 , 190);
	Person p5("张飞 ", 35 , 160);
	Person p6("关羽 ", 35 , 200);

	//尾插进list
	L.push_back(p1);
	L.push_back(p2);
	L.push_back(p3);
	L.push_back(p4);
	L.push_back(p5);
	L.push_back(p6);

	//打印list
	cout << "排序前：" << endl;
	printPerson(L);

	//调用函数排序
	L.sort(mysort);

	cout << "------------------------------------------------------------" << endl;
	cout << "排序后：" << endl;
	printPerson(L);

	return 0;
}