//设计立方体类，求立方体的面积和体积，并利用全局函数和成员函数判断两个立方体是否相等

#include<iostream>
using namespace std;

class Cube {
public:
	double m_L;
	double m_W;
	double m_H;
	void Input_L_W_H(double L, double W, double H)
	{
		m_L = L;
		m_W = W;
		m_H = H;
	}
	double get_L()
	{
		return m_L;
	}
	double get_W()
	{
		return m_W;
	}
	double get_H()
	{
		return m_H;
	}
	double getS()
	{
		return (m_L * m_W + m_L * m_H + m_W * m_H) * 2;
	}
	double getV()
	{
		return m_L * m_W * m_H;
	}
};

//判断是否相同的全局函数
bool Isone(Cube c1, Cube c2)
{
	if (c1.m_L == c2.m_L && c1.m_W == c2.m_W && c1.m_H == c2.m_H)
	{
		return true;
	}
	return false;
}

int main()
{
	Cube c1;
	c1.Input_L_W_H(1.5, 0.5, 1.7);
	cout << "该立方体的表面积为：" << c1.getS() << endl;
	cout << "该立方体的体积为：" << c1.getV() << endl;

	Cube c2;
	c2.Input_L_W_H(1.5, 0.5, 1.7);

	//全局
	if (Isone(c1,c2))
	{
		cout << "是同一个立方体！" << endl;
	}
	else
	{
		cout << "不是同一个立方体！" << endl;
	}

	//成员函数
	if (c1.m_H == c2.get_H() && c1.m_L == c2.get_L() && c1.m_W == c2.get_W())
	{
		cout << "是同一个立方体！" << endl;
	}
	else
	{
		cout << "不是同一个立方体！" << endl;
	}
	return 0;
}