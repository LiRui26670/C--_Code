#include<iostream>
using namespace std;
#include<string>

//成员函数做友元

class House;//类似于函数声明，此处为类声明

//好基友类
class GoodGay {
public:
	GoodGay();
public:
	void visit();//访问函数，访问House中的属性
	House* h;
};

//家类
class House {
	
	friend void GoodGay::visit();//写到类的最上面，格式：friend 返回值 类名::函数名（参数）；
public:
	House();
public:
	string m_SittingRoom;//客厅
private:
	string m_BedRoom;//卧室
};

//类外写构造函数
GoodGay::GoodGay()
{
	//创建对象
	h = new House;
}
House::House()
{
	m_SittingRoom = "客厅";
	m_BedRoom = "卧室";
}
//类外实现成员函数
void GoodGay::visit()
{
	cout << "好基友类正在访问：" << h->m_SittingRoom << endl;

	cout << "好基友类正在访问：" << h->m_BedRoom << endl;
}

void text01()
{
	GoodGay gg;
	gg.visit();
}
int main()
{
	text01();

	return 0;
}