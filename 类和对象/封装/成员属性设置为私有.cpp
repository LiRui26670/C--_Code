#include<iostream>
using namespace std;
#include<string>

//成员属性设置为私有
//1、可以自己控制读写权限
//2、对于写可以检测数据有效性

//人类
class Person {
public:
	//获取姓名
	string getname()
	{
		return m_name;
	}
	//写入姓名
	void inputname(string name)
	{
		m_name = name;
	}
	//写入年龄（0-150）
	void inputage(int age)
	{
		if (age < 0 || age>150)
		{
			cout << "年龄输入有误，赋值失败！" << endl;
			return;
		}
		m_age = age;
	}
	//获取年龄
	int getage()
	{
		return m_age;
	}
	//写入偶像
	void inputidol(string idol)
	{
		m_idol = idol;
	}
private:
	string m_name;		//姓名     可读可写
	int m_age = 18;		//年龄     只读       可写
	string m_idol;		//偶像     只写
};

int main()
{
	Person p1;
	p1.inputname("李锐");
	cout << "姓名：" << p1.getname() << endl;
	p1.inputage(19);
	cout << "年龄：" << p1.getage() << endl;
	p1.inputidol("杨紫");
}