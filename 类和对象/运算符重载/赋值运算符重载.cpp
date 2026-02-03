#include<iostream>
using namespace std;

class Person {
public:
	Person(int age)
	{
		m_Age = new int(age);
	}
	~Person()
	{
		if (m_Age != NULL)
		{
			delete m_Age;
			m_Age = NULL;
		}
	}
	Person&operator= (Person& p)
	{
		//判断自身是否已经有值，有则清空
		if (m_Age != NULL)
		{
			delete m_Age;
			m_Age = NULL;
		}

		//编译器提供的浅拷贝
		//m_Age = p.m_Age;//会有堆区内存重释放危险
		//深拷贝
		m_Age = new int(*p.m_Age);

		//返回类型，保持链式
		return *this;
	}
	int *m_Age;

};

void text()
{
	Person p1(18),p2(20),p3(30);

	cout << "p1的年龄为：" << *p1.m_Age << endl;
	cout << "p2的年龄为：" << *p2.m_Age << endl;
	cout << "p3的年龄为：" << *p3.m_Age << endl;

	p2 = p1;
	p3 = p2;
	cout << "p1的年龄为：" << *p1.m_Age << endl;
	cout << "p2的年龄为：" << *p2.m_Age << endl;
	cout << "p3的年龄为：" << *p3.m_Age << endl;
}

int main()
{
	text();
	return 0;
}