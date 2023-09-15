/********************
 项目：职工管理系统
 目的：接触面向对象编程OOP，为大型项目做铺垫
 包含：封装继承多态指针文件内存的应用
********************/

#include<iostream>
#include"workerManager.h"
//#include"worker.h"
//#include"manager.h"
//#include"employee.h"
//#include"boss.h"

int main()
{
	WorkerManager wm;

	int choice = 0;
	while (true)
	{
		wm.showMenu();
		std::cout << "请输入您的请求：" << std::endl;
		std::cin >> choice;

		switch (choice)
		{
		case 0: // 0.退出管理程序
			wm.exitSystem();
			break;
		case 1: // 1.增加职工信息
			wm.Add_Emp();
			break;
		case 2: // 2.显示职工信息
			wm.show_Emp();
			break;
		case 3: // 3.删除离职职工
			wm.del_Emp();
			break;
		case 4: // 4.修改职工信息
			wm.mod_Emp();
			break;
		case 5: // 5.查找职工信息
			wm.find_Emp();
			break;
		case 6: // 6.按照编号排序
			wm.sort_Emp();
			break;
		case 7: // 7.清空所有文档
			wm.clean_File();
			break;
		default:
			system("cls");
			break;
		}


	}


}



