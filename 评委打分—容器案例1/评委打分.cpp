/*

案例名称：评委打分

案例描述：

有5名选手：选手A、B、C、D、E

10个评委分别对每一名选手打分

计算选手最终得分时，需要：

·去除一个最高分
·去除一个最低分
·取剩余分数的平均分
实现步骤：

·创建五名选手，放入 vector 容器中

·遍历 vector 容器，对每个选手执行以下操作：

·将10个评委的打分存入 deque 容器中

·使用 sort 算法对 deque 容器中的分数进行排序

·去除最高分和最低分

·遍历 deque 容器，累加总分

·计算并获取平均分

******该案例是一个典型的C++编程练习，涉及STL容器（vector、deque）的使用以及排序、遍历、统计等基本算法操作。


*/


#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include<deque>
#include<time.h>
#include<algorithm>



//选手类
class Player
{
public:

	//打分
	void insert_score()
	{
		for (int i = 0; i < 10; i++)
		{
			this->m_score.push_back(rand()%41+60);
		}
	}
	//排序
	void Sort_score()
	{
		sort(this->m_score.begin(), this->m_score.end());
	}
	//去最高最低分
	void Del_MAXMIN()
	{
		this->m_score.pop_back();
		this->m_score.pop_front();
	}
	//总分
	void get_sum()
	{
		double sum = 0;
		for (deque<double>::iterator it = this->m_score.begin(); it != this->m_score.end(); it++)
		{
			sum += *it;
		}
		this->sum = sum;
	}
	//平均分
	void get_ave()
	{
		this->ave = this->sum / 8.;
	}

	string m_Name;
	deque<double> m_score;
	double sum;
	double ave;
};
void get_name(vector<Player>& players)
{
	for (int i = 0; i < 5; i++)
	{
		string nameseed = "ABCDE";
		string name = "选手";
		name += nameseed[i];
		players[i].m_Name = name;
	}
}
void text(vector<Player> &players)
{
	for (int i = 0; i < 5; i++)
	{
		players[i].insert_score();
		players[i].Sort_score();
		players[i].Del_MAXMIN();
		players[i].get_sum();
		players[i].get_ave();
	}
}

void Print_result(vector<Player> players)
{
	for (int i = 0; i < 5; i++)
	{
		cout << players[i].m_Name << "的总分为：" << players[i].sum << "\t平均分为：" << players[i].ave << endl;
	}
}
int main()
{
	srand((unsigned int )time(NULL));
	vector<Player> players(5);
	get_name(players);
	text(players);
	Print_result(players);
	return 0;
}
