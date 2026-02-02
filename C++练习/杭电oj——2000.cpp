/*
输入三个字符后，按各字符的ASCII码从小到大的顺序输出这三个字符。


Input
输入数据有多组，每组占一行，有三个字符组成，之间无空格。


Output
对于每组输入数据，输出一行，字符中间用一个空格分开。


Sample Input
qwe
asd
zxc


Sample Output
e q w
a d s
c x z
*/


#include<iostream>
using namespace std;

class Problem {
public:
	void Input()
	{
		cin >> p_a >> p_b >> p_c;
	}
	void Output()
	{
		char arr[3] = { p_a,p_b,p_c };
		for (int i = 0; i < 3 - i; i++)
		{
			for (int j = 0; j < 2 - i; j++)
			{
				if (arr[j] > arr[j + 1])
				{
					char tem = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = tem;
				}
			}
		}
		cout << arr[0] << " " << arr[1] << " " << arr[2] << endl;
	}
	char p_a;
	char p_b;
	char p_c;
};
int main()
{
	Problem p[3];
	for (int i = 0; i < 3; i++)
	{
		p[i].Input();
	}
	for (int i = 0; i < 3; i++)
	{
		p[i].Output();
	}
	
	return 0;
}