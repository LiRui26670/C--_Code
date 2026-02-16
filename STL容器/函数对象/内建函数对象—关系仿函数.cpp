/*

仿函数原型：
		·template<class T> bool equal_to<T>			//等于
		·template<class T> bool not_equal_to<T>			//不等于
		·template<class T> bool greater<T>			//大于
		·template<class T> bool greater_equal<T>			//大于等于
		·template<class T> bool less<T>			//小于
		·template<class T> bool less_equal<T>			//小于等于
*/


//大于

#include<iostream>
using namespace std;
#include<functional>
#include<vector>
#include<algorithm>


void text()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(30);
	v.push_back(50);
	v.push_back(40);
	v.push_back(20);

	cout << "升序：" << endl;
	sort(v.begin(), v.end());

	for (vector<int> ::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << endl;
	}

	cout << "降序：" << endl;
	sort(v.begin(), v.end(), greater<int>());

	for (vector<int> ::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << endl;
	}


}

int main()
{
	text();
	return 0;
}