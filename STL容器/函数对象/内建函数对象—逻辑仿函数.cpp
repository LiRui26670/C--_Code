/*
函数原型：
	·template<class T> bool logical_and<T>			//逻辑与
	·template<class T> bool logical_or<T>			//逻辑或
	·template<class T> bool logical_not<T>			//逻辑非

*/



//逻辑非
#include<iostream>
using namespace std;
#include<functional>
#include<vector>
#include<algorithm>

void text()
{
	vector<bool> v1;
	v1.push_back(true);
	v1.push_back(false);
	v1.push_back(false);
	v1.push_back(true);
	v1.push_back(false);
	
	cout << "v1:" << endl;
	for (vector<bool> ::iterator it = v1.begin(); it != v1.end(); it++)
	{
		cout << *it << endl;
	}

	vector<bool> v2;
	v2.resize(v1.size());

	transform(v1.begin(), v1.end(), v2.begin(), logical_not<bool>());

	cout << "v2:" << endl;
	for (vector<bool> ::iterator it = v2.begin(); it != v2.end(); it++)
	{
		cout << *it << endl;
	}
}

int main()
{
	text();
	return 0;
}