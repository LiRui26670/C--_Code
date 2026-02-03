#include<iostream>
using namespace std;
#include<string>

class Person {
public:
	Person(string name, int age)
	{
		Name = name;
		Age = age;
	}
	//==运算符重载
	bool operator == (Person&p)
	{
		if (Name == p.Name && Age == p.Age)
		{
			return true;
		}
		return false;
	}
	string Name;
	int Age;
};

void text()
{
	Person p1("Tom", 18);
	Person p2("Tom", 18);
	if (p1 == p2)
	{
		cout << "p1 和 p1 是相等的！" << endl;
	}
	else
	{
		cout << "p1 和 p1 是不相等的！" << endl;
	}
}
int main()
{
	text();
	return 0;
}

//其他关系运算符实现与==类似，在此不再重复实现
