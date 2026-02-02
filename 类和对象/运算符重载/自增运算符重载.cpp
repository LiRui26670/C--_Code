#include<iostream>
using namespace std;
//自增运算符重载（自减同理）
class MYINT {
public:
	//前置自增重载
	//返回值类型为引用，为了链式结构
	MYINT & operator++()
	{
		m_A++;
		return *this;
	}
	//后置自增重载
	//返回值类型不是引用，因为后置是先传原值，后加加
	MYINT operator++(int)//int为占位参数，区分前置与后置
	{
		MYINT tem = *this;
		m_A++;
		return tem;
	}
	int m_A;
};

//左移运算符重载
ostream& operator<<(ostream& cout, MYINT m)
{
	cout << "my_int = " << m.m_A;
	return cout;
}

void text01()
{
	MYINT my_int;
	my_int.m_A = 0;
	cout << my_int << endl;
	cout << ++(++my_int) << endl;
	cout << my_int << endl;
}

void text02()
{
	MYINT my_int;
	my_int.m_A = 0;
	cout << my_int << endl;
	cout << (my_int++)<< endl;
	cout << (my_int++) << endl;
	cout << my_int << endl;
}

int main()
{
	//text01();
	text02();
	return 0;
}