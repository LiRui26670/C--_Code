#include<iostream>
using namespace std;

//左移运算符重载
//左移运算符重载只能用全局函数重载，用成员函数也可以实现，但是所得结构与目标不符
class Person {
	////如果要打印私有成员，做友元操作即可
	//friend ostream& operator<<(ostream& cout, Person& p);
public:
	int m_A;
	int m_B;
};

//全局函数重载左移运算符
ostream &operator<<(ostream &cout,Person &p)
{
	cout << "m_A = " << p.m_A << endl << "m_B = " << p.m_B;
	//返回cout ,因为实际应用中，cout一般链式使用
	return cout;
}

void text()
{
	Person p;
	p.m_A = 10;
	p.m_B = 11;
	//重载左移运算符，使cout可以打印p的所有成员
	cout << p << endl;
}
int main()
{
	text();
	return 0;
}
