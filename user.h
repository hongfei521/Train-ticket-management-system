#pragma once
#pragma once
#include<string>
#include<vector>
using namespace std;
struct tickets
{
	string Train_number;//che
	string origin;//��ʼ��
	string destination;//Ŀ�ĵ�
	string startTime;//����ʱ��
	string endTime;//��վʱ��
	int carriage;//�����
	int seat;//��λ��
	double price;//Ʊ��

};
class User//�û���
{
public:
	string name;
	string username;//�û���
	string password;//����
	string ID;//���֤��
	tickets my_tickets[10];//���Ʊ��

	User(string a = "\0", string b = "\0", string c = "\0") :username(a), password(b), ID(c) {}
	void Set_tickets()
	{

	}

};
class admin//����Ա��
{
private:
	string adminname;
	string password;

public:
	admin(string a = "\0", string b = "\0") :adminname(a), password(b) {}
	~admin() {}


};


