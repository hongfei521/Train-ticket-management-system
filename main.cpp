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
bool users_login();//用户登录
void user_Register(); //用户注册
void user_mmenu();//用户菜单

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
    cout << "=                             欢迎访问火车票售票系统!                            " << endl;
    cout << "=                             现在时间:" << showTime() << endl;
    cout << "=                             1.用户登录                             " << endl;
    cout << "=                             2.用户注册                             " << endl;
    cout << "=                             3.管理员登录                             " << endl;
    cout << "=                             0.退出系统                             " << endl;
    cout << setfill('=') << setw(100) << "=" << endl;
    cout << "请选择" << endl;

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
void user_mmenu()//用户菜单
{
    if (users_login())
    {
        system("cls");
        cout << setfill('=') << setw(100) << "=" << endl;
        cout << "                                   您好,尊贵的用户!" << endl;
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
        cout << "登录失败，按任意键返回主菜单" << endl;
        getchar(); getchar();
        mnue();
    }


}
void adminmnue()//管理员菜单
{

    if (1)
    {
        system("cls");
        cout << setfill('=') << setw(100) << "=" << endl;
        cout << "                                   您好，管理员!" << endl;
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
        cout << "登录失败，按任意键返回主菜单" << endl;
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
    t = to_string(year) + "年" + to_string(month) + "月" + to_string(day) + "日" + to_string(h) + ":" + to_string(m) + ":"
        + to_string(s);
    return t;
}

bool users_login() //登录
{
    char name1[20];
    char password1[10], password2[10];
    char account1[20], account2[20];//已注册账户  输入账户
    FILE* fp = NULL;
    int ch;
    fp = fopen("user.txt", "r");
    if (fp) {
        ch = fgetc(fp);
        if (ch == EOF) {
            cout << "您还没有注册" << endl;
            fclose(fp);
            return false;
        }
        else {
            cout << "您已注册" << endl;
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
    int n = 3, i, faly = 1, faly1 = 0;//三次输入机会
    int flag = 1, flag1 = 0;
    while (n) {
        cout << "账户:";
        cin >> account2;//输入账户
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
            cout << "密码: ";
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
            cout << "账户输入错误" << endl;
            n--;
            continue;
        }
    }
}

void user_Register() //用户注册
{
    string ID;
    string password;
    char account[20];
    cout << "欢迎使用用户信息注册系统" << endl;
    cout << "请输入身份证号:";
    cin >> ID;
    cout << "请输入密码:(六位数):";

    cin >> password;
    char password1[64], ch;
    int i = 0;
    cout << "请输入密码:" << endl;
    while (true)
    {
        ch = _getch();//无回显的输入
        password1[i++] = ch;
        if (ch == '\r')//getch()函数如果读到回车符号返回'/r'
        {
            password1[i] = '\0';
            break;
        }
        putchar('*');
    }
    cout << endl << "你输入的密码是:" << password1;	cout << "请输入账号:(八位数):";


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
    cout << "账户创建成功，请重新登录" << endl;
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
bool admin_login()//管理员登录
{
    return true;
}


