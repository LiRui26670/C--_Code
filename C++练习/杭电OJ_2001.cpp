/*
Problem Description
输入两点坐标（X1, Y1）, （X2, Y2）, 计算并输出两点间的距离。


Input
输入数据有多组，每组占一行，由4个实数组成，分别表示x1, y1, x2, y2, 数据之间用空格隔开。


Output
对于每组输入数据，输出一行，结果保留两位小数。


Sample Input
0 0 0 1
0 1 1 0


Sample Output
1.00
1.41
*/

#include<iostream>
using namespace std;
#include<math.h>
int num = 0;
class Point {
public:
	void Input(Point &p)
	{
		cin >> m_X >> m_Y  >> p.m_X  >> p.m_Y;
	}
	void calculation(double *arr, Point p2)
	{
		int x2 = (m_X - p2.m_X) * (m_X - p2.m_X);
		int y2 = (m_Y - p2.m_Y) * (m_Y - p2.m_Y);
		double tem = std::sqrt(x2 + y2);
		arr[num] = tem;
		num++;
	}
	
	int m_X;
	int m_Y;
};
void Output(double* arr)
{
	for (int i = 0; i < num; i++)
	{
		cout << arr[i] << endl;
	}
}
int main()
{
	Point p1, p2;
	double* arr = new double[100];
	for (int i = 0; i < 2; i++)
	{
		p1.Input(p2);
		p1.calculation(arr, p2);
	}
	Output(arr);
	delete[]arr;
	return 0;
}