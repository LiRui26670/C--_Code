#include"workerManager.h"

//构造函数
WorkerManager::WorkerManager()
{
	//1、文件不存在
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		//初始化属性
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//2、文件数据为空
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//文件为空
		cout << "文件为空" << endl;
		//初始化属性
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//3、文件存在且有数据
	this->m_EmpNum = this->get_EmpNum();
	cout << "职工人数为：" << this->m_EmpNum << endl;

	//开辟空间
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	//初始化
	this->init_Emp();

}

//菜单显示
void WorkerManager::Show_Menu()
{
	cout << "**********************************************" << endl;
	cout << "**********" << "  欢迎使用职工管理系统！  " << "**********" << endl;
	cout << "**************" << "  0.退出管理程序  " << "**************" << endl;
	cout << "**************" << "  1.增加职工信息  " << "**************" << endl;
	cout << "**************" << "  2.显示职工信息  " << "**************" << endl;
	cout << "**************" << "  3.删除离职职工  " << "**************" << endl;
	cout << "**************" << "  4.修改职工信息  " << "**************" << endl;
	cout << "**************" << "  5.查找职工信息  " << "**************" << endl;
	cout << "**************" << "  6.按照编号排序  " << "**************" << endl;
	cout << "**************" << "  7.清空所有文档  " << "**************" << endl;
	cout << "**********************************************" << endl;
	cout << endl;
}

//退出系统
void WorkerManager::ExitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);//退出程序
}

//保存文件
void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);

	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptId << endl;
	}

	ofs.close();
}


//统计文件中职工人数
int WorkerManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int num = 0;
	int id;
	string name;
	int dId;

	while(ifs >> id && ifs >> name && ifs >> dId)
	{
		//统计人数
		num++;
	}

	ifs.close();

	return num;
}

//初始化员工
void WorkerManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int index = 0;

	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		Worker* worker = NULL;
		if (dId == 1)
		{
			worker = new Employee(id,name,dId);
		}
		else if (dId == 2)
		{
			worker = new Manager(id, name, dId);
		}
		else if (dId == 3)
		{
			worker = new Boss(id, name, dId);
		}

		this->m_EmpArray[index] = worker;
		index++;
	}

	ifs.close();

}


//添加职工
void WorkerManager::Add_Emp()
{
	cout << "请输入添加职工的数量：" << endl;

	int addNum = 0;//保存用户的输入数量
	cin >> addNum;

	if (addNum > 0)
	{
		//添加
		//计算添加的新空间大小
		int newSize = this->m_EmpNum + addNum;//新空间人数 = 原来记录的人数 + 新增人数

		//开辟新空间
		Worker** newSpace = new Worker * [newSize];

		//将原来的数据拷贝到新空间
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		//开始添加新数据
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int dSelect;

			cout << "请输入第" << i + 1 << "个新职工编号：" << endl;
			cin >> id;

			cout << "请输入第" << i + 1 << "个新职工姓名：" << endl;
			cin >> name;
			cout << "请选择该职工工作岗位：" << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(id, name, 1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;
			case 3:
				worker = new Boss(id, name, 3);
				break;
			default:
				break;
			}
			//将职工指针保存到数组中
			newSpace[this->m_EmpNum + i] = worker;
		}
		//释放原有空间
		delete[] this->m_EmpArray;

		//更改新空间指向
		this->m_EmpArray = newSpace;

		//更新职工人数
		this->m_EmpNum = newSize;

		//更新职工文件不为空
		this->m_FileIsEmpty = false;

		//提示添加成功
		cout << "成功添加" << addNum << "名新职工" << endl;

		//保存到问文件
		this->save();

	}
	else
	{
		cout << "输入数据有误" << endl;
	}

	system("pause");
	system("cls");
}

//显示职工信息
void WorkerManager::Show_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			this->m_EmpArray[i]->showInfo();
		}
	}

	system("pause");
	system("cls");
}

//职工是否存在(存在返回下标，不存在返回-1)
int WorkerManager::IsExist(int id)
{
	int index = -1;

	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (id == this->m_EmpArray[i]->m_Id)
		{
			index = i;
			break;
		}
	}
	return index;
}

//删除离职职工
void WorkerManager::Del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或者记录为空" << endl;
	}
	else
	{
		//按照职工编号删除
		cout << "请输入想要删除的职工编号：" << endl;
		int id = 0;
		cin >> id;

		int index = this->IsExist(id);

		if (index != -1)//说明职工存在，开始删除
		{
			//数据前移
			for (int i = 0; i < this->m_EmpNum - 1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;//更新职工数

			//更新文件
			this->save();

			cout << "删除成功！" << endl;
		}
		else 
		{
			cout << "删除失败，未找到该职工" << endl;
		}
	}system("pause");
	system("cls");
}

//修改职工信息
void WorkerManager::Mod_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或文件记录为空" << endl;
	}
	else
	{
		cout << "请输入要修改的职工编号：" << endl;
		int id;
		cin >> id;

		int index = this->IsExist(id);
		if (index != -1)
		{
			//找到职工，开始更改
			delete this->m_EmpArray[index];

			int nId;
			string nName;
			int nDId;

			cout << "查到：" << index << "号职工，请输入新职工编号：" << endl;
			cin >> nId;
			cout << "请输入新姓名：" << endl;
			cin >> nName;
			cout << "请选择该职工工作岗位：" << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> nDId;

			Worker* worker = NULL;
			switch (nDId)
			{
			case 1:
				worker = new Employee(nId, nName, 1);
				break;
			case 2:
				worker = new Manager(nId, nName, 2);
				break;
			case 3:
				worker = new Boss(nId, nName, 3);
				break;
			default:
				break;
			}

			//更改数据
			this->m_EmpArray[index] = worker;

			cout << "修改成功！" << endl; 

			//更新文件
			this->save();
		}
		else
		{
			cout << "修改失败，未找到该职工" << endl;
		}
	}
	system("pause");
	system("cls");
}

//查找职工信息
void WorkerManager::Find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		cout << "请选择查找方式：" << endl;
		cout << "1、按职工编号查找" << endl;
		cout << "2、按职工姓名查找" << endl;

		int select = 0;
		cin >> select;
		
		if (select == 1)
		{
			int id;
			cout << "请输入要查找的职工编号：" << endl;
			cin >> id;

			int index = this->IsExist(id);
			if (index != -1)
			{
				cout << "查找成功！该职工信息如下：" << endl;
				this->m_EmpArray[index]->showInfo();
			}
			else
			{
				cout << "查找失败，查无此人！" << endl;
			}
		}
		else if (select == 2)
		{
			cout << "请输入查找的姓名：" << endl;
			string name;
			cin >> name;

			bool flag = false;
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (name == this->m_EmpArray[i]->m_Name)
				{
					cout << "查找成功，该职工的信息如下：" << endl;
					this->m_EmpArray[i]->showInfo();

					flag = true;
				}
			}
			if (flag == false)
			{
				cout << "查找失败，查无此人！" << endl;
			}
		}
	}
}

//按照编号排序
void WorkerManager::Sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		cout << "请选择排序方式：" << endl;
		cout << "1、按职工编号升序" << endl;
		cout << "2、按职工编号降序" << endl;

		int select;
		cin >> select;

		for (int i = 0; i < this->m_EmpNum - 1; i++)
		{
			for (int j = 0; j < this->m_EmpNum - 1 - i; j++)
			{
				if (select == 1)
				{
					if (this->m_EmpArray[j]->m_Id > this->m_EmpArray[j + 1]->m_Id)
					{
						Worker* worker = this->m_EmpArray[j];
						this->m_EmpArray[j] = this->m_EmpArray[j+1];
						this->m_EmpArray[j + 1] = worker;
					}
				}
				else
				{
					if (this->m_EmpArray[j]->m_Id < this->m_EmpArray[j + 1]->m_Id)
					{
						Worker* worker = this->m_EmpArray[j];
						this->m_EmpArray[j] = this->m_EmpArray[j + 1];
						this->m_EmpArray[j + 1] = worker;
					}
				}
			}
		}
		cout << "排序成功，排序后的结果为：" << endl;

		this->save();
		this->Show_Emp();
	}
	system("pause");
	system("cls");
}

//清空文档
void WorkerManager::Clean_File()
{
	cout << "确认清空？" << endl;
	cout << "1、确认" << endl;
	cout << "2、返回" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		//打开模式 ios::trunc 如果存在，删除文件并重建
		ofstream ofs;
		ofs.open(FILENAME, ios::trunc);
		ofs.close();

		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i] != NULL)
				{
					delete this->m_EmpArray[i];
				}
			}
			this->m_EmpNum = 0;
			this->m_FileIsEmpty = true;
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
		}
		cout << "清空成功！" << endl;
	}
	system("pause");
	system("cls");
}

//析构函数
WorkerManager::~WorkerManager()
{
	if (this->m_EmpArray!= NULL)
	{
		for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i] != NULL)
				{
					delete this->m_EmpArray[i];
				}
			}

		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}