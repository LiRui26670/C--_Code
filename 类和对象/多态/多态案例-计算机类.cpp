//分别利用普通写法和多态技术，设计实现两个操作数进行运算的计算机类

/*
多态的优点：
	·代码组织结构清晰
	·可读性强
	·利于前期和后期的扩展以及维护

*/
#include<iostream>
using namespace std;
#include<string>
//普通实现
/*
class Calculator {
public:
	int getResult(string oper)
	{
		if (oper == "+")
			return m_num1 + m_num2;
		else if (oper == "-")
			return m_num1 - m_num2;
		else if (oper == "*")
			return m_num1 * m_num2;
	}
	int m_num1;
	int m_num2;
};

void text01()
{
	Calculator c;
	c.m_num1 = 10;
	c.m_num2 = 11;

	cout << c.m_num1 << "+" << c.m_num2 << "=" << c.getResult("+") << endl;
	cout << c.m_num1 << "-" << c.m_num2 << "=" << c.getResult("-") << endl;
	cout << c.m_num1 << "*" << c.m_num2 << "=" << c.getResult("*") << endl;
}

int main()
{
	text01();
	return 0;
}
*/
//目前来看比较简便，但如果想要扩展新功能，需要修改源码
//在真正的开发中，提倡开闭原则：对扩展进行开放，对修改进行关闭
//上述如果要增加相处的运算，必须去计算机类里修改代码，违反开闭原则

//利用多态

//计算机抽象类
class Calculator {
public:
	virtual int getResult()
	{
		return 0;
	}
	int m_num1;
	int m_num2;
};

//加法类
class Add :public Calculator {
public:
	int getResult()
	{
		return m_num1 + m_num2;
	}
};

//减法类
class Sub :public Calculator {
public:
	int getResult()
	{
		return m_num1 - m_num2;
	}
};
//乘法类
class Mul :public Calculator {
public:
	int getResult()
	{
		return m_num1 * m_num2;
	}
};

void text02()
{
	//多态使用条件
	//父类指针或者引用指向子类对象

	//加法
	Calculator* a = new Add;
	a->m_num1 = 10;
	a->m_num2 = 11;
	cout << a->getResult() << endl;
}

int main()
{
	text02();
	return 0;
}