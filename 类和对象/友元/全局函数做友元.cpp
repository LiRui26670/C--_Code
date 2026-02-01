#include<iostream>
using namespace std;
#include<string>

//全局函数做友元

class House {
	//goodGay是我的好朋友，可以访问我的卧室（私有成员）
	friend void goodGay(House* h);//写到类的最上面，格式：friend 返回值 函数名（参数）;
public:
	House()
	{
		m_SittingRoom = "客厅";
		m_BedRoom = "卧室";
	}
public:
	string m_SittingRoom;//客厅
private:
	string m_BedRoom;//卧室
};

//全局函数
void goodGay(House *h)
{
	cout << "好基友正在访问你的：" << h->m_SittingRoom << endl;

	cout << "好基友正在访问你的：" << h->m_BedRoom << endl;
}
int main()
{
	House h;
	goodGay(&h);
	return 0;
}