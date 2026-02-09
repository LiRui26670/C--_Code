//自己的通用数组类
#pragma once
#include<iostream>
using namespace std;

//类
template<class T>
class MyArray
{
private:
	T* pAddress;//通用数组，开辟在堆区
	int m_Capacity;//数组容量
	int m_Size;//数组大小

public:
	//构造函数（容量）
	MyArray(int capacity)
	{
		//初始化属性
		this->m_Capacity = capacity;
		this->m_Size = 0;
		//开辟相应大小空间
		this->pAddress = new T[this->m_Capacity];
	}
	//拷贝构造（深拷贝）
	MyArray(const MyArray& arr)
	{
		//拷贝相应属性
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		//深拷贝
		this->pAddress = new T[arr.m_Capacity];
		//赋值
		for (int i = 0; i < this->m_Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
	}
	//赋值运算符重载（深拷贝）
	MyArray& operator=(const MyArray&arr)
	{
		if (this->pAddress != NULL)
		{
			delete[]this->pAddress;
			this->pAddress = NULL;
			this->m_Capacity = 0;
			this->m_Size = 0;
		}
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		this->pAddress = new T[arr.m_Capacity];
		for (int i = 0; i < this->m_Size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
		return *this;
	}
	//利用下标访问数组
	T& operator[](int index)
	{
		return this->pAddress[index];
	}
	//尾插法
	void Push_Back(const T &val)
	{
		if (this->m_Size < this->m_Capacity)
		{
			this->pAddress[this->m_Size] = val;
			this->m_Size++;
		}
		else
		{
			cout << "数组已满，插入失败" << endl;
		}
	}
	//尾删法
	void Pop_Back()
	{
		if (this->m_Size == 0)
		{
			cout << "数组为空，删除失败" << endl;
		}
		else
		{
			this->m_Size--;
		}
	}
	//获取数组容量
	int get_Capacity()
	{
		return this->m_Capacity;
	}
	//获取数组大小
	int get_Size()
	{
		return this->m_Size;
	}
	//析构
	~MyArray()
	{
		if (this->pAddress != NULL)
		{
			delete[]this->pAddress;
			this->pAddress = NULL;
		}
	}
};
