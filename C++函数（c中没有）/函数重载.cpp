#include<iostream>
using namespace std;

//函数重载
//可以让函数名相同，提高复用性

/*函数重载的条件
		1、同一个作用域下
		2、函数名相同
		3、函数参数类型不同，或者个数不同，或者顺序不同
*/
/*
void func()
{
	cout << "func 的调用" << endl;
}
void func(char)
{
	cout << "func 的调用！" << endl;
}

int main()
{
	func();
	func('!');
	return 0;
}*/

//注意
//函数返回值类型不可以作为函数重载的条件








//函数重载的注意事项
//1、引用作为函数参数

void func(int& a)
{
	cout << "func(int & a) 的调用" << endl;
}
void func(const int& a)
{
	cout << "func(const int & a) 的调用" << endl;
}
#define c 10
int main()
{
	int a = 10;
	const int b = 10;
	func(a);
	func(10);
	func(b);
	func(c);
	return 0;
}

//2、函数重载碰到默认参数
void func2(int a, int b = 10)
{
	cout << "func2(int a,int b = 10) 的调用" << endl;
}
void func2(int a)
{
	cout << "func2(int a) 的调用" << endl;
}

int main()
{
	func2(10);//错误，两个fun2都可以调用，系统不知道调用哪个
	return 0;
}