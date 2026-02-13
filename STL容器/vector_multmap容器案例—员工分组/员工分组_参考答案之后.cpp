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

//枚举
enum Depart
{
	CEHUA = 1,MEISHU,YANFA
};
//创建员工类
class Worker
{
public:
	//有参函数构造
	Worker(string name, int salary)
	{
		this->m_Name = name;
		this->m_Salary = salary;
	}
	string m_Name;
	int m_Salary;
};

//初始化员工，并插入vector
void init(vector<Worker> &v)
{
	for (int i = 0; i < 10; i++)
	{
		string nameseed = "ABCDEFGHIJ";
		string name = "员工";
		name += nameseed[i];
		int salary = rand() % 6001 + 4000;
		Worker w(name,salary);
		v.push_back(w);
	}
}

//随机分组，并插入到multimap容器
void get_group(vector<Worker>& v, multimap<int, Worker> &m)
{
	for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++)
	{
		int k = rand() % 3 + 1;
		m.insert(make_pair(k, *it));
	}
}

//打印信息
void printinf(multimap<int, Worker>& m)
{
	cout << "策划组：" << endl;
	multimap<int,Worker>::iterator pos = m.find(CEHUA);
	int num = m.count(CEHUA);
	for (int i = 0; i < num; i++)
	{
		cout << "姓名：" << pos->second.m_Name << "\t薪水：" << pos->second.m_Salary << endl;
		pos++;
	}
	cout << "美术组：" << endl;
	pos = m.find(MEISHU);
	num = m.count(MEISHU);
	for (int i = 0; i < num; i++)
	{
		cout << "姓名：" << pos->second.m_Name << "\t薪水：" << pos->second.m_Salary << endl;
		pos++;
	}
	cout << "研发组：" << endl;
	pos = m.find(YANFA);
	num = m.count(YANFA);
	for (int i = 0; i < num; i++)
	{
		cout << "姓名：" << pos->second.m_Name << "\t薪水：" << pos->second.m_Salary << endl;
		pos++;
	}
}
int main()
{
	//设置时间种子节点
	srand((unsigned int)time(NULL));

	//创建vector容器
	vector<Worker> v;

	//初始化员工，并插入vector
	init(v);

	//创建multimap
	multimap<int, Worker> m;

	//随机分组，并插入到multimap容器
	get_group(v, m);

	//打印信息
	printinf(m);

	return 0;
}