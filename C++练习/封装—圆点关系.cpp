//设计一个圆类，一个点类，计算判断圆与点的位置关系
#include<iostream>
using namespace std;


//点类
class Point {
public:
	//设置点坐标
	void setx_y(int x, int y)
	{
		m_x = x;
		m_y = y;
	}
	//获取坐标
	int getx()
	{
		return m_x;
	}
	int gety()
	{
		return m_y;
	}
private:
	int m_x;
	int m_y;
};
//圆类
class Circle {
public:
	//设置半径
	void setr(double r)
	{
		m_r = r;
	}
	//获取半径
	double getr()
	{
		return m_r;
	}
	//设置圆心
	void setcenter(int x,int y)
	{
		m_center.setx_y(x, y);
	}
	//获取圆心
	int get_c_x()
	{
		return m_center.getx();
	}
	int get_c_y()
	{
		return m_center.gety();
	}
private:
	Point m_center;
	double m_r;
};

//判断圆与点的位置关系
void IsIn(Point p,Circle c)
{
	double n1 = (p.getx() - c.get_c_x()) * (p.getx() - c.get_c_x()) + (p.gety() - c.get_c_y()) * (p.gety() - c.get_c_y());
	double n2 = c.getr()*c.getr();

	if (n1 == n2)
	{
		cout << "点在圆上。" << endl;
	}
	else if (n1 > n2)
	{
		cout << "点在圆外。" << endl;
	}
	else
	{
		cout << "点在圆内。" << endl;
	}
}

int main()
{
	Point p;
	Circle c;
	p.setx_y(10, 10);
	c.setr(10);
	c.setcenter(10, 0);
	IsIn(p, c);
}