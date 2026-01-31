//C++类中的成员可以是另一个类的对象，我们称该成员为对象成员

//设A 的对象是B 的成员，则A为对象成员

//则创建B对象时，构造和析构的顺序为：A构造->B构造->B析构->A析构

#include<iostream>
using namespace std;
#include<string>

//类对象作为类成员

//手机类
class Phone {
public:
	
	//设置手机品牌名称
	Phone(string pname)
	{
		//有参函数构造
		cout << "Phone的构造" << endl;
		m_pname = pname;
	}
	~Phone()
	{
		cout << "Phone的析构" << endl;
	}
	//手机品牌名称
	string m_pname;
};

//人类
class Person {
public:
	
	//初始化列表赋初始值
	Person(string name, string pname) :m_name(name), m_phone(pname) {
		cout << "Person的构造" << endl;
	}
	~Person()
	{
		cout << "Person的析构" << endl;
	}
	//姓名
	string m_name;
	//手机
	Phone m_phone;
};

void text01()
{
	Person p("张三","苹果");
	cout << p.m_name << "拿着:" << p.m_phone.m_pname << endl;
}
int main()
{
	text01();
	return 0;
}