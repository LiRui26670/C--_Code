/*

多态是C++面向对象三大特性之一
多态分为两种：
	·静态多态：函数重载、运算符重载
	·动态多态：派生类和虚函数实现运行时多态

静态多态和动态多态的区别：
	·静态多态函数地址早绑定--编译阶段确定函数地址
	·动态多态的函数地址晚绑定--运行阶段确定函数地址

动态多态满足的条件：
	·有继承关系
	·子类重写父类虚函数

*/

#include<iostream>
using namespace std;

//多态

//动物类
class Animal {
public:
	/*void dospeak()//静态多态，编译阶段就已经确定函数地址在Animal
	{
		cout << "动物在说话" << endl;
	}*/
	//虚函数
	virtual void dospeak()//动态多态，运行时地址才确定在Cat
	{
		cout << "动物在说话" << endl;
	}
};

//猫类
class Cat :public Animal {
public:
	//重写  （virtual） 返回值类型  函数名  参数列表  完全相同
	void dospeak()
	{
		cout << "猫在说话" << endl;
	}
};

void text01(Animal &animal)//C++支持父类引用子类
{
	animal.dospeak();
}
int main()
{
	Cat c;
	text01(c);
	return 0;
}

