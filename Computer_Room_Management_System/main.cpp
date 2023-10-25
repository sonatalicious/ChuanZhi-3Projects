/********************
 项目：机房预约管理系统
 目的：总的大练习
 包含：C++语法总体应用
********************/



#include<iostream>
#include"identity.h"
#include<fstream>
#include<string>
#include"globalFile.h"
#include"student.h"
#include"teacher.h"
#include"manager.h"

//进入管理员子菜单界面
void managerMenu(Identity * &manager)
{
	while (true)
	{
		manager->operMenu();

		Manager* man = (Manager*)manager;
		int select = 0;

		std::cin >> select;

		if (select == 1) //添加账号
		{
			std::cout << "添加账号" << std::endl;
			man->addPerson();
		}
		else if (select == 2) //查看账号
		{
			std::cout << "查看账号" << std::endl;
			man->showPerson();
		}
		else if (select == 3) //查看机房
		{
			std::cout << "查看机房" << std::endl;
			man->showComputer();
		}
		else if (select == 4) //清空预约
		{
			std::cout << "清空预约" << std::endl;
			man->cleanFile();
		}
		else
		{
			delete manager;
			std::cout << "注销成功" << std::endl;
			system("pause");
			system("cls");
			return;
		}
	}


}



//登录功能 参数1-操作文件名  参数2-操作身份类型 1：学生 2：老师 3.管理员
void LogIn(std::string fileName, int type)
{
	Identity* person = NULL;

	std::ifstream ifs;
	ifs.open(fileName, std::ios::in);

	//文件不存在情况
	if (!ifs.is_open())
	{
		std::cout << "文件不存在" << std::endl;
		ifs.close();
		return;
	}

	int id = 0;
	std::string name;
	std::string pwd;

	if (type == 1) //学生登录
	{
		std::cout << "请输入你的学号" << std::endl;
		std::cin >> id;
	}
	else if (type == 2) //教师登录
	{
		std::cout << "请输入你的职工号" << std::endl;
		std::cin >> id;
			}

	std::cout << "请输入用户名：" << std::endl;
	std::cin >> name;
	std::cout << "请输入密码：" << std::endl;
	std::cin >> pwd;

	if (type == 1) //学生登录验证
	{
		int fId;
		std::string fName;
		std::string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (id == fId && fName == name && fPwd == pwd)
			{
				std::cout << "学生验证登录成功！" << std::endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				//进入学生身份的子菜单


				return;
			}

		}
	}
	else if (type == 2) //教师登录验证
	{
		int fId;
		std::string fName;
		std::string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (id == fId && fName == name && fPwd == pwd)
			{
				std::cout << "教师验证登录成功！" << std::endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				//进入教师身份的子菜单


				return;
			}

		}
	}
	else if (type == 3) // 管理员登录验证
	{

		std::string fName;
		std::string fPwd;
		while (ifs >> fName && ifs >> fPwd)
		{
			if (fName == name && fPwd == pwd)
			{
				std::cout << "管理员验证登录成功！" << std::endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);
				//进入管理员身份的子菜单
				managerMenu(person);

				return;
			}

		}
	}

	std::cout << "验证登录失败" << std::endl;

	system("pause");
	system("cls");
	return;

}



int main()
{
	int select = 0;
	while (true)
	{


		std::cout << "================   欢迎来到机房预约系统   ================" << std::endl;
		std::cout << std::endl << "请输入您的身份" << std::endl;
		std::cout << "\t\t| ------------------------------------- |\n";
		std::cout << "\t\t|                                       |\n";
		std::cout << "\t\t|             1.学生代表                |\n";
		std::cout << "\t\t|                                       |\n";
		std::cout << "\t\t|             2.老    师                |\n";
		std::cout << "\t\t|                                       |\n";
		std::cout << "\t\t|             3.管 理 员                |\n";
		std::cout << "\t\t|                                       |\n";
		std::cout << "\t\t|             0.退    出                |\n";
		std::cout << "\t\t|                                       |\n";
		std::cout << "\t\t| ------------------------------------- |\n";
		std::cout << "输入您的选择：" << std::endl;

		std::cin >> select;

		switch (select)
		{
		case 1: //学生身份
		{
			LogIn(STUDENT_FILE, 1);
		}
			break;
		case 2: //老师身份
		{
			LogIn(TEACHER_FILE, 2);
		}
			break;
		case 3: //管理员身份
		{
			LogIn(ADMIN_FILE, 3);
		}
			break;
		case 0: //退出系统
		{
			std::cout << "欢迎下一次使用" << std::endl;
			system("pause");
			return 0;
		}
			break;

		default:
		{
			std::cout << "输入有误，请重新选择！" << std::endl;
			system("pause");
			system("cls");
		}
			break;

		}

	}

	system("pause");
	return 0;
}

