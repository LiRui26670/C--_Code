/*
Problem Description
根据输入的半径值，计算球的体积。


Input
输入数据有多组，每组占一行，每行包括一个实数，表示球的半径。


Output
输出对应的球的体积，对于每组输入数据，输出一行，计算结果保留三位小数。


Sample Input
1
1.5


Sample Output
4.189
14.137


Hint

#define PI 3.1415927

*/

#include<iostream>
using namespace std;
#define PI 3.1415927
int num = 0;

class QIU {
public:
	void Input()
	{
		cin >> m_r;
	}
	void caiculation_V(float *arr)
	{
		float tem = PI * m_r * m_r * m_r * 4 / 3;
		arr[num] = tem;
		num++;
	}
	float m_r;
};
int main()
{
	float *arr = new float[100];
	QIU q;
	for (int i = 0; i < 2; i++)
	{
		q.Input();
		q.caiculation_V(arr);
	}
	for (int i = 0; i < num; i++)
	{
		cout << arr[i] << endl;
	}

	return 0;
}