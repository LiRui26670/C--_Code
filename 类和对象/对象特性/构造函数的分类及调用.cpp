#include<iostream>
using namespace std;

//1、构造函数的分类及调用
//分类
//	按照参数分类		无参构造（默认构造）和有参构造
//	按照类型分类		普通构造	拷贝构造
class Person {
public:
	//构造函数
	//无参构造（普通）
	Person()
	{
		cout << "Person的无参构造函数调用" << endl;
	}
	//有参构造（普通）
	Person(int a)
	{
		age = a;
		cout << "Person的有参构造函数调用" << endl;
	}
	//拷贝构造
	Person(const Person &p)
	{
		//将传入的人身上的所有属性，拷贝到我身上
		cout << "Person的拷贝构造函数调用" << endl;
		age = p.age;
	}
	~Person()
	{
		cout << "Person的析构函数调用" << endl;
	}
	int age;
};

void text01()
{
	//1、括号法
	/*Person p1;//默认构造调用
	Person p2(10);//有参构造调用
	Person p3(p2);//拷贝构造调用*/

	//注意：
	//调用默认构造函数，不要加小括号
	
	//2、显示法
	/*Person p1;//默认构造
	Person p2 = Person(10);//有参构造
	Person p3 = Person(p2);//拷贝构造*/

	//Person(10);  //匿名对象	特点：当前行结束后，系统会立即回收匿名对象
	//cout << "qqqqqqqqqqqq";

	//注意事项
	//不要利用拷贝构造函数初始化匿名对象    因为编译器会认为Person(p3)===Person p3
	//Person(p3);
	 
	//3、隐式转换法
	Person p4 = 10;//有参构造     相当于Person p4 = Person(10);
	Person p5 = p4;//拷贝构造
}








int main()
{
	text01();
	return 0;
}