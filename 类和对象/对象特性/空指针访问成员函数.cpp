//C++中空指针也可以调用成员函数，但要注意有无this指针的使用
//如果用到this指针，要加以判断保证代码的健壮性

#include<iostream>
using namespace std;


class Person {
public:
	void showname()
	{
		cout << "this class name is Person" << endl;
	}
	void showage()
	{
		if (this == NULL)//判断语句
		{
			cout << "指针为NULL" << endl;
			return;
		}
		cout << "this age is " << m_age /*m_age === this->m_age*/ << endl;
	}
	int m_age = 10;
};

void text01()
{
	Person *p = NULL;
	p->showname();//可以执行
	p->showage();//报错，因为空指针在函数内试图访问m_age,非法，需要在函数内添加判断语句
}

int main()
{
	text01();
	return 0;
}