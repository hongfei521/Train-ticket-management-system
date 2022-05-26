#pragma once
#pragma once
#include<string>
#include<vector>
using namespace std;
struct tickets
{
	string Train_number;//che
	string origin;//起始地
	string destination;//目的地
	string startTime;//开车时间
	string endTime;//到站时间
	int carriage;//车厢号
	int seat;//座位号
	double price;//票价

};
class User//用户类
{
public:
	string name;
	string username;//用户名
	string password;//密码
	string ID;//身份证号
	tickets my_tickets[10];//最大购票量

	User(string a = "\0", string b = "\0", string c = "\0") :username(a), password(b), ID(c) {}
	void Set_tickets()
	{

	}

};
class admin//管理员类
{
private:
	string adminname;
	string password;

public:
	admin(string a = "\0", string b = "\0") :adminname(a), password(b) {}
	~admin() {}


};


