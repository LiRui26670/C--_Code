//浅拷贝：简单的复制拷贝操作
//深拷贝：在堆区重新申请空间，进行拷贝操作
#include<iostream>
using namespace std;

//深拷贝与浅拷贝

class Person {
public:
	Person()
	{
		cout << "Person的默认构造函数调用" << endl;
	}
	Person(int age,int height)
	{
		cout << "Person的有参构造函数调用" << endl;
		m_age = age;
		m_height = new int(height);
	}
	//自己实现拷贝构造函数，解决浅拷贝带来的问题
	Person(const Person &p)
	{
		cout << "Person的拷贝构造函数调用" << endl;
		m_age = p.m_age;
		//m_height = p.m_height;编译器默认实现是这行代码
		//深拷贝操作
		m_height = new int(*p.m_height);
	}
	~Person()
	{
		//析构代码，将堆区开辟数据做释放操作 
		if (m_height != NULL)
		{
			delete m_height;
			m_height = NULL;
		}

		cout << "Person的析构函数调用" << endl;
	}
	int m_age;
	int* m_height;
};

void text01()
{
	Person p1(18,180);
	cout << "p1的年龄为：" << p1.m_age << "p1的身高为：" << *p1.m_height << endl;

	Person p2(p1);
	cout << "p2的年龄为：" << p2.m_age << "p2的身高为：" << *p2.m_height << endl;
}
int main()
{
	text01();
	return 0;
}