/*

谓词：
概念：
·返回bool类型的仿函数成为谓词
·如果operator()接受一个参数，那么叫做一元谓词
·如果operator()接受两个参数，那么叫做二元谓词

*/

////一元谓词
//
//#include<iostream>
//using namespace std;
//#include<vector>
//#include<algorithm>
//
//
//
////创建谓词
//class GreaterFive
//{
//public:
//	bool operator()(int v)
//	{
//		return v > 5;
//	}
//};
//void text()
//{
//	vector<int> v;
//	for (int i = 0; i < 10; i++)
//	{
//		v.push_back(i);
//	}
//
//	//查找容器中有没有大于5的数字
//	//find_if查找到返回当前迭代器，否则返回end（）
//	//find_if参数列表————区间的开始迭代器，区间的末尾迭代器，谓词
//	//GreaterFive（）为匿名对象，传对象也可以
//	vector<int>::iterator it = find_if(v.begin(), v.end(), GreaterFive());
//	if (it == v.end())
//	{
//		cout << "未找到大于5的数据" << endl;
//	}
//	else
//	{
//		cout << "已找到大于5的数据：" << *it << endl;
//	}
//
//}
//int main()
//{
//	text();
//	return 0;
//}

//二元谓词

#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>


//二元谓词
class MySort
{
public:
	bool operator()(int v1,int v2)
	{
		return v1 > v2;
	}
};
void text()
{
	vector<int>v;
	v.push_back(30);
	v.push_back(10);
	v.push_back(50);
	v.push_back(20);
	v.push_back(40);

	cout << "排序前：" << endl;
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << endl;
	}

	//sort默认排序
	sort(v.begin(), v.end());
	cout << "默认sort排序（升序）后：" << endl;
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << endl;
	}

	//降序
	sort(v.begin(), v.end(),MySort());
	cout << "更改sort排序（降序）后：" << endl;
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << endl;
	}

}

int main()
{
	text();
	return 0;
}