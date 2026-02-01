#include<iostream>
using namespace std;

//加号运算符重载
//
//class num {
//public:
//	/*num operator+(num n) {
//		m_a += n.m_a;
//		m_b += n.m_b;
//		return *this;
//	}*/
//	
//	int m_a;
//	int m_b;
//};
//num operator+(num n1,num n2) {
//	num tem;
//	tem.m_a = n1.m_a + n2.m_a;
//	tem.m_b = n1.m_b + n2.m_b;
//	return tem;
//	}
//
//
//void text()
//{
//	num n1;
//	num n2;
//	n1.m_a = 9; n1.m_b = 11;
//	n2.m_a = 11; n2.m_b = 9;
//	num n3 = n1 + n2;
//
//	cout << "m_a = " << n3.m_a << "	m_b = " << n3.m_b << endl;
//}
//
//int main()
//{
//	text();
//	return 0;
//}


//左移运算符
/*
class num {
public:
	int m_a = 10;
};


ostream & operator<<(ostream &cout,num n)
{
	cout << n.m_a;
	return cout;
}
void text()
{
	num n;
	cout << n << endl;
}

int main()
{
	text();
	return 0;
}
*/


//自增运算符

class num {
public:
	num& operator++()
	{
		m_a++;
		return *this;
	}

	num operator++(int)
	{
		num tem = *this;
		m_a++;
		return tem;
	}
	int m_a;
};

ostream& operator<<(ostream& cout, num n)
{
	cout << n.m_a;
	return cout;
}
void text()
{
	/*num n;
	n.m_a = 0;
	cout << n << endl;
	cout << ++(++n) << endl;
	cout << n << endl;*/


	num m;
	m.m_a = 0;
	cout << m << endl;
	cout << m++ << m++<<endl;
	cout << m << endl;
	
}

int main()
{
	text();
	return 0;
}