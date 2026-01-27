#include <iostream>
#include<string>
using namespace std;

class Student {
public:
	int m_id;
	string m_name;
	void Input_id(int id)
	{
		m_id = id;
	}
	void Input_name(string name)
	{
		m_name = name;
	}
	void Show_student(int id,string name)
	{
		cout << "Ñ§ºÅ£º" << id << endl << "ÐÕÃû£º" << name << endl;
	}
};

int main()
{
	Student st1;
	st1.Input_id(1001);
	st1.Input_name("ÀîÈñ");
	st1.Show_student(st1.m_id,st1.m_name);
	return 0;
}