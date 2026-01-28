//C++提供了初始化列表语法，用来初始化属性

//语法：构造函数（）：属性1（值1），属性2（值2），.....{}

#include<iostream>
using namespace std;

class Person {
public:
	//传统初始化操作（有参构造）
	/*Person(int a, int b, int c)
	{
		m_A = a;
		m_B = b;
		m_C = c;
	}*/

	//初始化列表初始化属性
	Person() :m_A(10), m_B(20), m_C(30) {

	}
	//进阶版
	Person(int a,int b,int c) :m_A(a), m_B(b), m_C(c) {

	}
	int m_A;
	int m_B;
	int m_C;
};
void text01()
{
	/*Person p(10,20,30);*/
	Person p(30,20,10);
	cout << p.m_A << "    " << p.m_B << "    " << p.m_C << endl;
}
int main()
{
	text01();
	return 0;
}