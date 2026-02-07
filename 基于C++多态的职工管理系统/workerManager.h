#pragma once//防止头文件重复包含
#include<iostream>
using namespace std;
#include<fstream>
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
#define FILENAME "empFile,txt"

//职工管理类
class WorkerManager
{
public:
	//构造函数
	WorkerManager();

	//菜单显示
	void Show_Menu();

	//退出系统
	void ExitSystem();

	//记录职工人数
	int m_EmpNum;

	//职工数组指针
	Worker** m_EmpArray;

	//保存文件
	void save();

	//添加职工
	void Add_Emp();

	//判断文件是否为空
	bool m_FileIsEmpty;

	//统计文件中职工人数
	int get_EmpNum();

	//初始化员工
	void init_Emp();

	//显示职工信息
	void Show_Emp();

	//职工是否存在(存在返回下标，不存在返回-1)
	int IsExist(int id);

	//删除离职职工
	void Del_Emp();

	//修改职工信息
	void Mod_Emp();

	//查找职工信息
	void Find_Emp();

	//按照编号排序
	void Sort_Emp();

	//清空文档
	void Clean_File();

	//析构函数
	~WorkerManager();
};
