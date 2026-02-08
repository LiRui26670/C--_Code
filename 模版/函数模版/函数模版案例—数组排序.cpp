/*
要求：
	·实现通用对数组进行排序的函数
	·规则：从小到大
	·算法：选择排序
	·测试：用char 数组和int 数组测试

*/

#include<iostream>
using namespace std;

//两数交换模版
template<typename T>
void MySwap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}
//排序模版-选择排序
template<typename T>
void MySort(T arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		int min = i;
		for (int j = i + 1; j < size; j++)
		{
			if (arr[min] > arr[j])
			{
				min = j;
			}
		}
		if (min != i)
		{
			MySwap(arr[min], arr[i]);
		}
	}
}

//打印数组模版
template<typename T>
void MyPrint(T arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}


int main()
{
	char CharArr[] = "bcfadeg";
	//排序
	int size_c = sizeof(CharArr) / sizeof(char)-1;
	MySort(CharArr, size_c);

	//打印
	MyPrint(CharArr, size_c);


	int IntArr[] = { 3,2,6,4,1,7,5 };
	//排序
	int size_i = sizeof(IntArr) / sizeof(int);
	MySort(IntArr, size_i);

	//打印
	MyPrint(IntArr, size_i);

	return 0;
}