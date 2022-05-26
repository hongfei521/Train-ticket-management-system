#include <cstdio>
#include<iostream>
#include <vector>
#include<iomanip>
#include<ctime>
#include<string>
#include<fstream>
#include<conio.h>
#include<stdlib.h>
#include"user.h"
using namespace std;
bool amdin_login();
void mnue();
string showTime();
void adminmnue();
void printfile();
void adminRegister();
bool users_login();//�û���¼
void user_Register(); //�û�ע��
void user_mmenu();//�û��˵�

int main()
{
    mnue();
}
void mnue()
{
    bool mainFlag = true;
    int n;
    system("cls");
    cout << setfill('=') << setw(100) << "=" << endl;
    cout << "=                             ��ӭ���ʻ�Ʊ��Ʊϵͳ!                            " << endl;
    cout << "=                             ����ʱ��:" << showTime() << endl;
    cout << "=                             1.�û���¼                             " << endl;
    cout << "=                             2.�û�ע��                             " << endl;
    cout << "=                             3.����Ա��¼                             " << endl;
    cout << "=                             0.�˳�ϵͳ                             " << endl;
    cout << setfill('=') << setw(100) << "=" << endl;
    cout << "��ѡ��" << endl;

    cin >> n;
    switch (n)
    {
    case 1:
    {
        user_mmenu();
        break;
    }
    case 2:
    {
        user_Register();
        break;
    }
    case 3:
    {
        adminmnue();
        break;
    }
    case 0:
    {
        exit(0);
        break;
    }
    }

}
void user_mmenu()//�û��˵�
{
    if (users_login())
    {
        system("cls");
        cout << setfill('=') << setw(100) << "=" << endl;
        cout << "                                   ����,�����û�!" << endl;
        cout << "                                   1." << endl;
        cout << "                                   2." << endl;
        cout << "                                   3." << endl;
        cout << "                                   4." << endl;
        cout << "                                   5." << endl;
        cout << "                                   6." << endl;
        cout << "                                   7." << endl;
        cout << "                                   8." << endl;
        cout << "                                   9." << endl;
        cout << setfill('=') << setw(100) << "=" << endl;
    }
    else {
        cout << "��¼ʧ�ܣ���������������˵�" << endl;
        getchar(); getchar();
        mnue();
    }


}
void adminmnue()//����Ա�˵�
{

    if (1)
    {
        system("cls");
        cout << setfill('=') << setw(100) << "=" << endl;
        cout << "                                   ���ã�����Ա!" << endl;
        cout << "                                   1." << endl;
        cout << "                                   2." << endl;
        cout << "                                   3." << endl;
        cout << "                                   4." << endl;
        cout << "                                   5." << endl;
        cout << "                                   6." << endl;
        cout << "                                   7." << endl;
        cout << "                                   8." << endl;
        cout << "                                   9." << endl;
        cout << setfill('=') << setw(100) << "=" << endl;
    }
    else {
        cout << "��¼ʧ�ܣ���������������˵�" << endl;
        getchar(); getchar();
        mnue();
    }
    printfile();
}

string showTime()
{
    time_t now = time(0);
    tm* ltm = localtime(&now);
    int year, month, day, h, m, s;
    year = 1900 + ltm->tm_year;
    month = 1 + ltm->tm_mon;
    day = ltm->tm_mday;
    h = ltm->tm_hour;
    m = ltm->tm_min;
    s = ltm->tm_sec;
    string t;
    t = to_string(year) + "��" + to_string(month) + "��" + to_string(day) + "��" + to_string(h) + ":" + to_string(m) + ":"
        + to_string(s);
    return t;
}

bool users_login() //��¼
{
    char name1[20];
    char password1[10], password2[10];
    char account1[20], account2[20];//��ע���˻�  �����˻�
    FILE* fp = NULL;
    int ch;
    fp = fopen("user.txt", "r");
    if (fp) {
        ch = fgetc(fp);
        if (ch == EOF) {
            cout << "����û��ע��" << endl;
            fclose(fp);
            return false;
        }
        else {
            cout << "����ע��" << endl;
        }
        fscanf(fp, "%s", name1);
        fscanf(fp, "%s", password1);
        fscanf(fp, "%s", account1);
        fclose(fp);
    }
    else {
        cout << "open file  failed!" << endl;
        return false;
    }
    int n = 3, i, faly = 1, faly1 = 0;//�����������
    int flag = 1, flag1 = 0;
    while (n) {
        cout << "�˻�:";
        cin >> account2;//�����˻�
        for (i = 0; i < 20; i++) {
            if (account2[i] == account1[i]) {
                faly = 1;
            }
            else {
                faly1 = 1;
                faly = 0;
                break;
            }
        }
        if (faly == 1 || faly1 == 0) {
            cout << "����: ";
            cin >> password2;
            for (i = 0; i < 10; i++) {

                if (password2[i] == password1[i]) {
                    flag = 1;
                }
                else {
                    flag1 = 1;
                    flag = 0;
                    break;
                }
            }

        }
        else {
            cout << "�˻��������" << endl;
            n--;
            continue;
        }
    }
}

void user_Register() //�û�ע��
{
    string ID;
    string password;
    char account[20];
    cout << "��ӭʹ���û���Ϣע��ϵͳ" << endl;
    cout << "���������֤��:";
    cin >> ID;
    cout << "����������:(��λ��):";

    cin >> password;
    char password1[64], ch;
    int i = 0;
    cout << "����������:" << endl;
    while (true)
    {
        ch = _getch();//�޻��Ե�����
        password1[i++] = ch;
        if (ch == '\r')//getch()������������س����ŷ���'/r'
        {
            password1[i] = '\0';
            break;
        }
        putchar('*');
    }
    cout << endl << "�������������:" << password1;	cout << "�������˺�:(��λ��):";


    scanf("%s", account);
    FILE* fp = NULL;
    fp = fopen("user.txt", "w");
    if (fp) {
        fprintf(fp, " %s %s %s", ID, password, account);
        fclose(fp);
    }
    else {
        cout << "open file failed!";
        return;
    }
    cout << "�˻������ɹ��������µ�¼" << endl;
    return;
}

void printfile()
{
    FILE* fp = NULL;
    fp = fopen("admin.txt", "w");
    if (fp != NULL)
    {
        fprintf(fp, "%d", 1);
    }
    else
    {
        cout << "file can not open!";
        exit(0);
    }
    fclose(fp);
}
bool admin_login()//����Ա��¼
{
    return true;
}


