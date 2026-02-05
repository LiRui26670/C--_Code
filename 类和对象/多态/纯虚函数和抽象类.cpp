/*
在多态中，通常父类中的虚函数实现是毫无意义的，主要都是子类重写的内容

因此可以将虚函数改写为纯虚函数

语法：virtual 返回值类型  函数名  （参数列表） = 0;

当类中有了纯虚函数，该类成为抽象类

抽象类特点：
	·无法实例化对象
	·子类必须重写抽象类重点纯虚函数，否则子类也是抽象类

*/

/*
多态案例：制作饮品

制作饮品的大致流程为，煮水、冲泡、倒入杯子、加入辅料

利用多态，提供抽象制作饮品基类，子类为咖啡和茶叶


*/

#include<iostream>
using namespace std;

//抽象饮品基类
class MakeDrink {
public:
	//煮水
	void shui()
	{
		cout << "正在煮水......" << endl << "煮水完成。" << endl;
	}
	//冲泡(纯虚函数)
	virtual void chongpao() = 0;
	//倒入杯子
	void daobeizi()
	{
		cout << "正在倒入杯子......" << endl << "已倒入杯子。" << endl;
	}
	//加入辅料(纯虚函数)
	virtual void fuliao() = 0;

	//制作流程
	void Making()
	{
		shui();
		chongpao();
		daobeizi();
		fuliao();
	}
};

//咖啡类
class Coffee :public MakeDrink {
public:
	//冲泡
	void chongpao()
	{
		cout << "冲泡咖啡" << endl;
	}
	//加入辅料
	virtual void fuliao()
	{
		cout << "加入糖和牛奶" << endl;
	}
};

//茶类
class Tea :public MakeDrink {
public:
	//冲泡
	void chongpao()
	{
		cout << "冲泡茶叶" << endl;
	}
	//加入辅料
	virtual void fuliao()
	{
		cout << "加入枸杞" << endl;
	}
};

void text()
{
	MakeDrink* c = new Coffee;
	c->Making();
	cout << "---------------------------------------" << endl;
	Tea tea;
	MakeDrink& t = tea;
	t.Making();

}
int main()
{
	text();
	return 0;
}