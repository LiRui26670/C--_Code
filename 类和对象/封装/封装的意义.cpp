/*
封装的意义：
		1、将属性与行为作为一个整体，表现生活中的事物
		2、将属性与行为加以权限控制

*/

#include<iostream>
using namespace std;

#define PI 3.14

//设计一个圆类，求周长面积

//class 代表设计一个类，类后面紧跟类名称
class Circle {
	//访问权限
	//公共权限
public:
	//属性
	double m_r;
	//行为
	//获取圆的周长
	double calculateC()
	{
		return 2 * PI * m_r;
	}
	//获取圆的面积
	double calculateS()
	{
		return PI * m_r * m_r;
	}
};

int main()
{
	//通过圆类，创建具体的圆（对象）
	Circle c1;
	//给对象的属性赋值
	c1.m_r = 2.5;

	cout << "圆的周长为：" << c1.calculateC() << endl;
	cout << "圆的周长为：" << c1.calculateS() << endl;
	return 0;
}

//访问权限共有三种：
// public（公共权限）		成员 类内可以访问 类外可以访问
// protected（保护权限）	成员 类内可以访问 类外不可以访问		继承中：儿子可以访问父亲的保护内容
// private（私有权限）		成员 类内可以访问 类外不可以访问		继承中：儿子不可以访问父亲的私有内容

class Person {
public:
	string m_Name;//姓名
protected:
	string m_Car;//车
private:
	int m_Password;//银行卡密码

public:
	void func()
	{
		m_Name = "张三";
		m_Car = "拖拉机";
		m_Password = 123456;			//均不报错，说明类内可以访问
	}
};

int main()
{
	//实例化具体对象
	Person p1;
	p1.func();
	p1.m_Name = "李四";		//没有报错，说明类外可以访问
	p1.m_Car = "奔驰";		//报错，类外不可以访问
	p1.m_Password = 123;		//报错，类外不可以访问
	return 0;
}






//************************struct    和       class的区别是默认权限不同，struct默认公共，class默认私有