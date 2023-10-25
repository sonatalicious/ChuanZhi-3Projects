/********************
 ��Ŀ������ԤԼ����ϵͳ
 Ŀ�ģ��ܵĴ���ϰ
 ������C++�﷨����Ӧ��
********************/



#include<iostream>
#include"identity.h"
#include<fstream>
#include<string>
#include"globalFile.h"
#include"student.h"
#include"teacher.h"
#include"manager.h"

//�������Ա�Ӳ˵�����
void managerMenu(Identity * &manager)
{
	while (true)
	{
		manager->operMenu();

		Manager* man = (Manager*)manager;
		int select = 0;

		std::cin >> select;

		if (select == 1) //����˺�
		{
			std::cout << "����˺�" << std::endl;
			man->addPerson();
		}
		else if (select == 2) //�鿴�˺�
		{
			std::cout << "�鿴�˺�" << std::endl;
			man->showPerson();
		}
		else if (select == 3) //�鿴����
		{
			std::cout << "�鿴����" << std::endl;
			man->showComputer();
		}
		else if (select == 4) //���ԤԼ
		{
			std::cout << "���ԤԼ" << std::endl;
			man->cleanFile();
		}
		else
		{
			delete manager;
			std::cout << "ע���ɹ�" << std::endl;
			system("pause");
			system("cls");
			return;
		}
	}


}



//��¼���� ����1-�����ļ���  ����2-����������� 1��ѧ�� 2����ʦ 3.����Ա
void LogIn(std::string fileName, int type)
{
	Identity* person = NULL;

	std::ifstream ifs;
	ifs.open(fileName, std::ios::in);

	//�ļ����������
	if (!ifs.is_open())
	{
		std::cout << "�ļ�������" << std::endl;
		ifs.close();
		return;
	}

	int id = 0;
	std::string name;
	std::string pwd;

	if (type == 1) //ѧ����¼
	{
		std::cout << "���������ѧ��" << std::endl;
		std::cin >> id;
	}
	else if (type == 2) //��ʦ��¼
	{
		std::cout << "���������ְ����" << std::endl;
		std::cin >> id;
			}

	std::cout << "�������û�����" << std::endl;
	std::cin >> name;
	std::cout << "���������룺" << std::endl;
	std::cin >> pwd;

	if (type == 1) //ѧ����¼��֤
	{
		int fId;
		std::string fName;
		std::string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (id == fId && fName == name && fPwd == pwd)
			{
				std::cout << "ѧ����֤��¼�ɹ���" << std::endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				//����ѧ����ݵ��Ӳ˵�


				return;
			}

		}
	}
	else if (type == 2) //��ʦ��¼��֤
	{
		int fId;
		std::string fName;
		std::string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (id == fId && fName == name && fPwd == pwd)
			{
				std::cout << "��ʦ��֤��¼�ɹ���" << std::endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				//�����ʦ��ݵ��Ӳ˵�


				return;
			}

		}
	}
	else if (type == 3) // ����Ա��¼��֤
	{

		std::string fName;
		std::string fPwd;
		while (ifs >> fName && ifs >> fPwd)
		{
			if (fName == name && fPwd == pwd)
			{
				std::cout << "����Ա��֤��¼�ɹ���" << std::endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);
				//�������Ա��ݵ��Ӳ˵�
				managerMenu(person);

				return;
			}

		}
	}

	std::cout << "��֤��¼ʧ��" << std::endl;

	system("pause");
	system("cls");
	return;

}



int main()
{
	int select = 0;
	while (true)
	{


		std::cout << "================   ��ӭ��������ԤԼϵͳ   ================" << std::endl;
		std::cout << std::endl << "�������������" << std::endl;
		std::cout << "\t\t| ------------------------------------- |\n";
		std::cout << "\t\t|                                       |\n";
		std::cout << "\t\t|             1.ѧ������                |\n";
		std::cout << "\t\t|                                       |\n";
		std::cout << "\t\t|             2.��    ʦ                |\n";
		std::cout << "\t\t|                                       |\n";
		std::cout << "\t\t|             3.�� �� Ա                |\n";
		std::cout << "\t\t|                                       |\n";
		std::cout << "\t\t|             0.��    ��                |\n";
		std::cout << "\t\t|                                       |\n";
		std::cout << "\t\t| ------------------------------------- |\n";
		std::cout << "��������ѡ��" << std::endl;

		std::cin >> select;

		switch (select)
		{
		case 1: //ѧ�����
		{
			LogIn(STUDENT_FILE, 1);
		}
			break;
		case 2: //��ʦ���
		{
			LogIn(TEACHER_FILE, 2);
		}
			break;
		case 3: //����Ա���
		{
			LogIn(ADMIN_FILE, 3);
		}
			break;
		case 0: //�˳�ϵͳ
		{
			std::cout << "��ӭ��һ��ʹ��" << std::endl;
			system("pause");
			return 0;
		}
			break;

		default:
		{
			std::cout << "��������������ѡ��" << std::endl;
			system("pause");
			system("cls");
		}
			break;

		}

	}

	system("pause");
	return 0;
}

