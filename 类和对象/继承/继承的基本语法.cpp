//当一些类除了有上一级类的共性外还有一些自己的特性，这是可以用继承，目的是减少代码量
//继承的好处;减少重复的代码量
//语法:class 子类 ： 继承方式  父类
//子类也叫派生类
//父类也叫基类


#include<iostream>
using namespace std;

//网页实现举例

class BasePage {
public:
	void header()
	{
		cout << "首页、公开课、登录、注册....（公共头部）" << endl;
	}
	void footer()
	{
		cout << "帮助中心、交流合作、站内地图....(公共尾部)" << endl;
	}
	void left()
	{
		cout << "Java、Python、C++、.....(公共分类列表)" << endl;
	}
};

//Java页面
class Java :public BasePage
{
public:
	void content()
	{
		cout << "Java视频课" << endl;
	}
};

//Python页面
class Python :public BasePage
{
public:
	void content()
	{
		cout << "Python视频课" << endl;
	}
};

// C++页面
class CPP :public BasePage
{
public:
	void content()
	{
		cout << "CPP视频课" << endl;
	}
};

void text()
{
	cout << "Java页面如下：" << endl;
	Java ja;
	ja.header();
	ja.footer();
	ja.left();
	ja.content();
	cout << "Python页面如下：" << endl;
	Python p;
	p.header();
	p.footer();
	p.left();
	p.content();
}

int main()
{
	text();
	return 0;
}