#pragma once
#include<iostream>
#include<fstream>
#include"Worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"

#define FILENAME "empFile.txt"


class WorkerManager
{
public:
	WorkerManager();
	~WorkerManager();

	void Add_Emp();
	void save();
	int get_EmpNum();
	void init_Emp();
	void show_Emp();
	void del_Emp();
	int IsExist(int id);
	void mod_Emp();
	void find_Emp();
	void sort_Emp();
	void clean_File();

	int m_EmpNum;
	Worker** m_EmpArray;
	bool m_FileIsEmpty;

public:
	void showMenu()
	{
		std::cout << "**************************************" << std::endl;
		std::cout << "*********��ӭʹ��ְ������ϵͳ*********" << std::endl;
		std::cout << "**********  0.�˳��������  **********" << std::endl;
		std::cout << "**********  1.����ְ����Ϣ  **********" << std::endl;
		std::cout << "**********  2.��ʾְ����Ϣ  **********" << std::endl;
		std::cout << "**********  3.ɾ����ְְ��  **********" << std::endl;
		std::cout << "**********  4.�޸�ְ����Ϣ  **********" << std::endl;
		std::cout << "**********  5.����ְ����Ϣ  **********" << std::endl;
		std::cout << "**********  6.���ձ������  **********" << std::endl;
		std::cout << "**********  7.��������ĵ�  **********" << std::endl;
		std::cout << "**************************************" << std::endl;
		std::cout << std::endl;
	}

	void exitSystem()
	{
		std::cout << "��ӭ�´�ʹ�ã�" << std::endl;
		system("pause");
		exit(0);
	}

};

// ���캯��
WorkerManager::WorkerManager(): m_EmpNum(0), m_EmpArray(NULL)
{
	std::ifstream ifs;
	ifs.open(FILENAME, std::ios::in);

	// ���ݴ洢�ļ����������
	if (!ifs.is_open())
	{
		std::cout << "���ݴ洢�ļ�������" << std::endl;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	// ���ݴ洢�ļ�������Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		std::cout << "���ݴ洢�ļ�Ϊ��" << std::endl;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	// ���ݴ洢�ļ������Ҽ�¼������
	int num = this->get_EmpNum();
	std::cout << "���ݴ洢�ļ����洢��" << num << "��ְ������" << std::endl;
	this->m_EmpNum = num;
	
	// �����ݴ洢�ļ������ݴ浽������
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	this->init_Emp();
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		std::cout << "ְ����ţ�" << this->m_EmpArray[i]->m_Id
			<< "\tְ��������" << this->m_EmpArray[i]->m_Name
			<< "\t���ű�ţ�" << this->m_EmpArray[i]->m_DeptID << std::endl;

	}

}

// ��������
WorkerManager::~WorkerManager()
{

	if (this->m_EmpArray != NULL)
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			if (this->m_EmpArray[i] != NULL)
			{
				delete this->m_EmpArray[i]; // ��ն���
			}
		}
		delete[] this->m_EmpArray; // �ͷ��ڴ�
		this->m_EmpArray = NULL;
	}
}

// ����ְ������
void WorkerManager::Add_Emp()
{
	std::cout << "����������ְ��������" << std::endl;
	int addNum = 0;
	std::cin >> addNum;

	if (addNum > 0)
	{
		int newSize = this->m_EmpNum + addNum; // �����¿ռ��С
		Worker** newSpace = new Worker* [newSize]; // �����¿ռ�
		// ��ԭ�����ݸ��Ƶ��¿ռ���
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}
		// ���������
		for (int i = 0; i < addNum; i++)
		{
			int id;
			std::string name;
			int dSelect;

			std::cout << "�������" << i + 1 << "λ��ְ����ţ�" << std::endl;
			std::cin >> id;
			std::cout << "�������" << i + 1 << "λ��ְ��������" << std::endl;
			std::cin >> name;
			std::cout << "��ѡ��ְ����λ��" << std::endl;
			std::cout << "1����ְͨ��" << std::endl;
			std::cout << "2������" << std::endl;
			std::cout << "3���ϰ�" << std::endl;
			std::cin >> dSelect;

			Worker* worker = NULL;

			switch (dSelect)
			{
			case 1:
				worker = new Employee(id, name, dSelect);
				break;
			case 2:
				worker = new Manager(id, name, dSelect);
				break;
			case 3:
				worker = new Boss(id, name, dSelect);
				break;
			default:
				break;
			}
			
			// ����ְ��ְ�𣬱��浽������
			newSpace[this->m_EmpNum + i] = worker;
		}
		// �ͷ�ԭ�пռ�
		delete[] this->m_EmpArray;
		// �����¿ռ�ָ��
		this->m_EmpArray = newSpace;
		// ����ְ��������
		this->m_EmpNum = newSize;
		// �ļ���Ϊ��
		this->m_FileIsEmpty = false;
		// ��ʾ��ӳɹ�
		std::cout << "�ɹ����" << addNum << "����ְ��" << std::endl;
		// ��������
		this->save();

	}
	else
	{
		std::cout << "��������" << std::endl;
	}
	system("pause");
	system("cls");
}

// �������ݵ��ļ���
void WorkerManager::save()
{
	std::ofstream ofs; // �ļ����������
	ofs.open(FILENAME, std::ios::out);
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptID << std::endl;
	}
	ofs.close();
}

// �õ��ļ��д洢ְ������
int WorkerManager::get_EmpNum()
{
	std::ifstream ifs;
	ifs.open(FILENAME, std::ios::in);

	int id;
	std::string name;
	int dId;

	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		num++;
	}
	ifs.close();
	return num;

}

// �õ����ݴ洢�ļ��е�ְ����Ϣ������ʼ�����ش���Ϣ
void WorkerManager::init_Emp()
{
	std::ifstream ifs;
	ifs.open(FILENAME, std::ios::in);

	int id;
	std::string name;
	int dId;

	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		Worker* worker = NULL;
		switch (dId)
		{
		case 1:
			worker = new Employee(id, name, dId);
			break;
		case 2:
			worker = new Manager(id, name, dId);
			break;
		case 3:
			worker = new Boss(id, name, dId);
			break;
		default:
			break;
		}

		this->m_EmpArray[index] = worker;
		index++;
	}
	ifs.close();

}

// ��ʾְ����Ϣ
void WorkerManager::show_Emp()
{
	if (this->m_FileIsEmpty)
	{
		std::cout << "�ļ������ڻ�Ϊ��" << std::endl;
	}
	else
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			this->m_EmpArray[i]->showInfo(); // ���ö�̬�ӿ�
		}
	}
	system("pause");
	system("cls");
}

// ɾ��ְ����Ϣ
void WorkerManager::del_Emp()
{
	if (this->m_FileIsEmpty)
		std::cout << "�ļ������ڻ��¼Ϊ��" << std::endl;
	else
	{
		int id;
		std::cout << "������ɾ��ְ����ID��" << std::endl;
		std::cin >> id;
		int index = this->IsExist(id);
		if (index != -1) // ְ�����ڲ�Ҫɾ��
		{
			for (int i = index; i < this->m_EmpNum; i++) // ��һ������ǰ��
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			this->m_EmpNum--; // ���²���������
			this->save();
			std::cout << "ɾ���ɹ�" << std::endl;
		}
		else // ְ��������
		{
			std::cout << "ְ�������ڣ�ɾ��ʧ��" << std::endl;
		}
	}
	system("pause");
	system("cls");
}

// �ж�ְ���Ƿ����
int WorkerManager::IsExist(int id)
{
	for (int i = 0; i < this->m_EmpNum; i++)
		if (this->m_EmpArray[i]->m_Id == id)
			return i;
	return -1;
}

// �޸�ְ����Ϣ
void WorkerManager::mod_Emp()
{
	if (this->m_FileIsEmpty)
		std::cout << "�ļ������ڻ��¼Ϊ��" << std::endl;
	else
	{
		int id;
		std::cout << "�������޸�ְ����ID��" << std::endl;
		std::cin >> id;
		int index = this->IsExist(id);
		if (index != -1) // ְ�����ڲ�Ҫ�޸�
		{
			delete this->m_EmpArray[index]; // �ͷ��ڴ�
			int nId;
			std::string nName;
			int nDepSlesct;

			std::cout << "�ҵ�IDΪ��" << id << "��ְ����������ְ����ID��"  << std::endl;
			std::cin >> nId;

			std::cout << "�������λ��" << std::endl;
			std::cin >> nName;

			std::cout << "��ѡ��ְ����λ��" << std::endl;
			std::cout << "1����ְͨ��" << std::endl;
			std::cout << "2������" << std::endl;
			std::cout << "3���ϰ�" << std::endl;
			std::cin >> nDepSlesct;

			Worker* worker = NULL;
			switch(nDepSlesct)
			{
			case 1:
				worker = new Employee(nId, nName, nDepSlesct);
				break;
			case 2:
				worker = new Manager(nId, nName, nDepSlesct);
				break;
			case 3:
				worker = new Boss(nId, nName, nDepSlesct);
				break;
			default:
				break;
			}
			this->m_EmpArray[index] = worker;

			this->save(); // ���²���������
			std::cout << "�޸ĳɹ�" << std::endl;
		}
		else // ְ��������
		{
			std::cout << "ְ�������ڣ��޸�ʧ��" << std::endl;
		}
	}
	system("pause");
	system("cls");

}

// ����ְ����Ϣ
void WorkerManager::find_Emp()
{
	if (this->m_FileIsEmpty)
		std::cout << "�ļ������ڻ��¼Ϊ��" << std::endl;
	else
	{
		std::cout << "��������ҷ�ʽ" << std::endl;
		std::cout << "1����ְ��ID����" << std::endl;
		std::cout << "2����ְ����������" << std::endl;

		int select = 0;
		std::cin >> select;

		switch (select)
		{
		case 1:
		{
			int id;
			std::cout << "������ְ��ID:" << std::endl;
			std::cin >> id;

			int index = this->IsExist(id);
			if (index != -1)
			{
				this->m_EmpArray[index]->showInfo();
			}
			else
			{
				std::cout << "ְ�������ڣ���ʾʧ��" << std::endl;
			}
			break;
		}
		case 2:
		{
			std::string name;
			std::cout << "������ְ������:" << std::endl;
			std::cin >> name;
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_Name == name)
				{
					std::cout << "���ҳɹ�: ";
					m_EmpArray[i]->showInfo();
					break;
				}
			}
			std::cout << "ְ�������ڣ���ʾʧ��" << std::endl;
			break;
		}
		default:
			std::cout << "�������" << std::endl;
			break;
		}
	}
	system("pause");
	system("cls");
}

void WorkerManager::sort_Emp()
{
	if (this->m_FileIsEmpty)
		std::cout << "�ļ������ڻ��¼Ϊ��" << std::endl;
	else
	{
		std::cout << "����������ʽ" << std::endl;
		std::cout << "1����ְ��ID��������" << std::endl;
		std::cout << "2����ְ��ID���н���" << std::endl;

		int select = 0;
		std::cin >> select;

		for (int i = 0; i < this->m_EmpNum; i++) // ��ʼѡ������
		{
			int minOrMax = i;
			for (int j = i + 1; j < this->m_EmpNum; j++)
			{
				if (select == 1)
				{
					if (this->m_EmpArray[minOrMax]->m_Id > this->m_EmpArray[j]->m_Id)
					{
						minOrMax = j;
					}
				}
				else
				{
					if (this->m_EmpArray[minOrMax]->m_Id < this->m_EmpArray[j]->m_Id)
					{
						minOrMax = j;
					}
				}
			}

			if (i != minOrMax)
			{
				Worker* temp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[minOrMax];
				this->m_EmpArray[minOrMax] = temp;
			}
		}
		std::cout << "����ɹ�" << std::endl;
		this->save();
	}
	system("pause");
	system("cls");
}

void WorkerManager::clean_File()
{
	std::cout << "ȷ���Ƿ���գ�" << std::endl;
	std::cout << "1��ȷ��" << std::endl;
	std::cout << "2������" << std::endl;

	int select = 0;
	std::cin >> select;

	if (select == 1)
	{
		// ��ģʽ ios::trunc���������ɾ���ļ������´���
		std::ofstream ofs(FILENAME, std::ios::trunc);
		ofs.close();

		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i] != NULL)
				{
					delete this->m_EmpArray[i]; // ��ն���
				}
			}
			this->m_EmpNum = 0;
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_FileIsEmpty = true;
		}
		std::cout << "��ճɹ�" << std::endl;
	}

	system("pause");
	system("cls");

}

