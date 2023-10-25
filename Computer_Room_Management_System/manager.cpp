#include <iostream>
#include <fstream>
#include "manager.h"
#include "globalFile.h"

//默认构造
Manager::Manager()
{

}

//有参构造（管理员姓名，密码）
Manager::Manager(std::string name, std::string pwd)
{
	this->m_Name = name;
	this->m_Pwd = pwd;
}

//选择菜单
void Manager::operMenu()
{
	std::cout << "欢迎管理员" << this->m_Name << "登录" << std::endl;
	std::cout << "\t\t ----------------------------\n";
	std::cout << "\t\t ---------1.添加账号---------\n";
	std::cout << "\t\t ---------2.查看账号---------\n";
	std::cout << "\t\t ---------3.查看机房---------\n";
	std::cout << "\t\t ---------4.清空预约---------\n";
	std::cout << "\t\t ---------0.注销登录---------\n";
	std::cout << "\t\t ----------------------------\n";
	std::cout << "请选择您的操作:" << std::endl;
	return;

}

//添加账号
void Manager::addPerson()
{
	std::cout << "请输入添加账号的类型" << std::endl;
	std::cout << "1.添加学生" << std::endl;
	std::cout << "2.添加老师" << std::endl;

	std::string fileName;
	std::string tip;
	std::ofstream ofs;

	int select = 0;
	std::cin >> select;

	if (select == 1)
	{
		fileName = STUDENT_FILE;

	}

}

//查看账号
void Manager::showPerson()
{

}

//查看机房信息
void Manager::showComputer()
{

}

//清空预约记录
void Manager::cleanFile()
{

}

