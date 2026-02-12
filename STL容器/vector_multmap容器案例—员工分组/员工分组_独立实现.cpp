/*

案例要求
·公司招聘10名员工（姓名：A～J）。

·员工信息包含姓名、工资。

·部门分为：策划、美术、研发。

·随机为10名员工分配部门及工资。

·使用 multimap 存储数据，其中 key 为部门编号，value 为员工对象。

·最终按部门分组显示所有员工信息。

实现步骤
·创建员工：生成10名员工对象，存入 vector 容器。

·随机分组：遍历 vector，为每个员工随机分配部门及工资。

·数据存储：将员工按部门编号为 key，员工对象为 value，插入 multimap 容器。

·分部门显示：遍历 multimap，按部门分组输出员工信息。

*/

#include<iostream>
using namespace std;
#include<vector>
#include<map>
#include<string>
#include<ctime>

//员工类
class Employee
{
public:
	void Show_inf()
	{
		cout << this->m_Name << "\t\t" << this->m_salary << endl;
	}
	string m_Name;
	int m_dId;
	int m_salary;
};

//给员工基础信息
void get_base(vector<Employee> &e)
{
	int i = 0;
	for (vector<Employee>::iterator it = e.begin(); it != e.end(); it++)
	{
		string nameseed = "ABCDDEFGHIJ";
		it->m_Name = nameseed[i];
		it->m_salary = rand() % 1501 + 3000;
		i++;
	}
}

//随机分组
void get_dId(vector<Employee>& e)
{
	for (vector<Employee>::iterator it = e.begin(); it != e.end(); it++)
	{
		it->m_dId = rand() % 3 + 1;
	}
}

//将员工存储到multimap
void transfer(vector<Employee>& e, multimap<int, Employee>& mul)
{
	for (vector<Employee>::iterator it = e.begin(); it != e.end(); it++)
	{
		mul.insert(make_pair(it->m_dId, *it));
	}
}

//显示信息
void Show(multimap<int, Employee>& mul) 
{
	
		cout << "策划组：" << endl;
		for (multimap<int, Employee>::iterator it = mul.begin(); it != mul.end(); it++)
		{
			if (it->first == 1)
			{
				it->second.Show_inf();
			}
		}
		
		cout << "美术组：" << endl;
		for (multimap<int, Employee>::iterator it = mul.begin(); it != mul.end(); it++)
		{
			if (it->first == 2)
			{
				it->second.Show_inf();
			}
		}
		cout << "研发组：" << endl;
		for (multimap<int, Employee>::iterator it = mul.begin(); it != mul.end(); it++)
		{
			if (it->first == 3)
			{
				it->second.Show_inf();
			}
		}
}

int main()
{
	srand((unsigned int)time(NULL));

	//创建vector容器
	vector<Employee> emps;
	//将员工存入容器
	Employee e1,e2,e3,e4,e5,e6,e7,e8,e9,e10;
	emps.push_back(e1);
	emps.push_back(e2);
	emps.push_back(e3);
	emps.push_back(e4);
	emps.push_back(e5);
	emps.push_back(e6);
	emps.push_back(e7);
	emps.push_back(e8);
	emps.push_back(e9);
	emps.push_back(e10);

	//员工基础信息
	get_base(emps);

	//员工分组
	get_dId(emps);

	//存储到multmap
	multimap<int ,Employee> mul;
	transfer(emps,mul);

	//显示信息
	Show(mul);
	return 0;
}