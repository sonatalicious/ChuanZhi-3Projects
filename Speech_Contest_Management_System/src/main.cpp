/********************
 ��Ŀ���ݽ���������ϵͳ
 Ŀ�ģ����ͱ����STL�Ļ���ʹ��
 �����������������㷨��Ӧ��
********************/


#include<iostream>
#include<ctime>
#include"speechManager.h"

int main()
{

	// ���������
	srand((unsigned int)time(NULL));

	SpeechManager sm;

	//for (std::map<int, Speaker>::iterator it = sm.m_Speaker.begin(); it != sm.m_Speaker.end(); it++)
	//{
	//	std::cout << "ѡ�ֱ�ţ�" << it->first << "������" << it->second.m_Name << "������" << it->second.m_Score[0] << std::endl;
	//}

	int choice = 0;

	while (true)
	{
		sm.show_Menu();
		std::cout << "����������ѡ��" << std::endl;
		std::cin >> choice;

		switch (choice)
		{
		case 1: // ��ʼ����
			sm.startSpeech();
			break;
		case 2: // �鿴��¼
			sm.showRecord();
			break;
		case 3: // ��ռ�¼
			sm.clearRecord();
			break;
		case 0: // �˳�ϵͳ
			sm.exitSystem();
			break;
		default:
		{
			std::cout << "�������" << std::endl;
			system("pause");
			system("cls");
		}
			break;

		}
		

	}

	system("pause");

}



