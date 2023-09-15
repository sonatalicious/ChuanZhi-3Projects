/********************
 项目：演讲比赛管理系统
 目的：泛型编程与STL的基本使用
 包含：容器迭代器算法的应用
********************/


#include<iostream>
#include<ctime>
#include"speechManager.h"

int main()
{

	// 随机数种子
	srand((unsigned int)time(NULL));

	SpeechManager sm;

	//for (std::map<int, Speaker>::iterator it = sm.m_Speaker.begin(); it != sm.m_Speaker.end(); it++)
	//{
	//	std::cout << "选手编号：" << it->first << "姓名：" << it->second.m_Name << "分数：" << it->second.m_Score[0] << std::endl;
	//}

	int choice = 0;

	while (true)
	{
		sm.show_Menu();
		std::cout << "请输入您的选择：" << std::endl;
		std::cin >> choice;

		switch (choice)
		{
		case 1: // 开始比赛
			sm.startSpeech();
			break;
		case 2: // 查看记录
			sm.showRecord();
			break;
		case 3: // 清空记录
			sm.clearRecord();
			break;
		case 0: // 退出系统
			sm.exitSystem();
			break;
		default:
		{
			std::cout << "输入错误" << std::endl;
			system("pause");
			system("cls");
		}
			break;

		}
		

	}

	system("pause");

}



