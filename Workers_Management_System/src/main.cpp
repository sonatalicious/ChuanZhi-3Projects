/********************
 ��Ŀ��ְ������ϵͳ
 Ŀ�ģ��Ӵ����������OOP��Ϊ������Ŀ���̵�
 ��������װ�̳ж�ָ̬���ļ��ڴ��Ӧ��
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
		std::cout << "��������������" << std::endl;
		std::cin >> choice;

		switch (choice)
		{
		case 0: // 0.�˳��������
			wm.exitSystem();
			break;
		case 1: // 1.����ְ����Ϣ
			wm.Add_Emp();
			break;
		case 2: // 2.��ʾְ����Ϣ
			wm.show_Emp();
			break;
		case 3: // 3.ɾ����ְְ��
			wm.del_Emp();
			break;
		case 4: // 4.�޸�ְ����Ϣ
			wm.mod_Emp();
			break;
		case 5: // 5.����ְ����Ϣ
			wm.find_Emp();
			break;
		case 6: // 6.���ձ������
			wm.sort_Emp();
			break;
		case 7: // 7.��������ĵ�
			wm.clean_File();
			break;
		default:
			system("cls");
			break;
		}


	}


}



