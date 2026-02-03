#include<iostream>
using namespace std;
#include<string>

//函数调用运算符（）重载

//打印输出类
class Myprint {
public:
	//重载函数调用运算符
	void operator() (string text)
	{
		cout << text << endl;
	}
};

//加法类
class MyAdd {
public:
	int operator()(int a, int b)
	{
		return a + b;
	}
};

void myprint02(string text)
{
	cout << text << endl;
}

void text01()
{
	Myprint myprint;
	myprint("Hello World");//由于使用起来非常类似函数调用，因此称为仿函数
	myprint02("Hello World");
}

void text02()
{
	MyAdd myadd;
	cout << myadd(10, 20) << endl;
}

int main()
{
	text01();
	text02();
	return 0;
}


//其他类不再赘述，用法非常灵活