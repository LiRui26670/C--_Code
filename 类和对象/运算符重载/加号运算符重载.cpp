#include<iostream>
using namespace std;

//加号运算符重载

class Person {
public:

	//1、成员函数来重载加号运算符
	Person operator+(Person& p)
	{
		Person tem;
		tem.m_A = this->m_A + p.m_A;
		tem.m_B = this->m_B + p.m_B;
		return tem;
	}
	int m_A;
	int m_B;
};

//2、全局函数重载加号运算符
Person operator+(Person& p1, Person& p2)
{
	Person tem;
	tem.m_A = p1.m_A + p2.m_A;
	tem.m_B = p1.m_B + p2.m_B;
	return tem;
}
void text01()
{
	Person p1;
	p1.m_A = 9;
	p1.m_B = 11;
	Person p2;
	p2.m_A = 11;
	p2.m_B = 9;

	Person p3 = p1 + p2;

	cout << p3.m_A << endl;
	cout << p3.m_B << endl;
}

int main()
{
	text01();
	return 0;
}



//总结：
//		·对于内置的数据类型的表达式的运算符是不可能改变的
//		·不要滥用运算符重载