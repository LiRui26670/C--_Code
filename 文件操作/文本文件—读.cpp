/*

读文件的操作步骤：

1、头文件
	#include<fstream>
2、创建流对象
	ifstream ifs;
3、打开文件  并判断文件打开是否成功(利用C++提供的函数：ifs.is_open(),成功打开返回1，失败返回0)
	ifs.open("文件路径"，打开方式);
	if(!ifs.is_open())
	{
		cout<<"文件打开失败"<<endl;
		return ;
	}
4、写数据
	四种方式：

	第一种：
	char buf[1024] = {0};
	while(ifs>>buf)
	{
		cout<<buf<<endl;
	}

	第二种：
	char buf[1024] = {0};
	while(ifs.getline(buf,sizeof(buf)))
	{
		cout<<buf<<endl;
	}

	第三种：
	string buf;
	while(getline(ifs,buf))
	{
		cout<<buf<<endl;
	}

	第四种（不常用）：
	char c;
	while((c = ifs,get())!=EOF)
	{
		cout<<c;
	}
5、关闭文件
	ifs.close();


打开方式		解释
ios::in			为读文件而打开文件
ios::out		为写文件而打开文件
ios::ate		初始位置：文件尾
ios::app		追加方式写文件
ios::trunc		如果文件存在先删除，再创建
ios::binary		二进制方式

注意：文件打开方式可以配合使用，利用操作符

例如：用二进制方式写文件
ios::binary || ios::out
*/