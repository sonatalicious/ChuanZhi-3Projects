#include <iostream>
#include <fstream>
#include "manager.h"
#include "globalFile.h"

//Ĭ�Ϲ���
Manager::Manager()
{

}

//�вι��죨����Ա���������룩
Manager::Manager(std::string name, std::string pwd)
{
	this->m_Name = name;
	this->m_Pwd = pwd;
}

//ѡ��˵�
void Manager::operMenu()
{
	std::cout << "��ӭ����Ա" << this->m_Name << "��¼" << std::endl;
	std::cout << "\t\t ----------------------------\n";
	std::cout << "\t\t ---------1.����˺�---------\n";
	std::cout << "\t\t ---------2.�鿴�˺�---------\n";
	std::cout << "\t\t ---------3.�鿴����---------\n";
	std::cout << "\t\t ---------4.���ԤԼ---------\n";
	std::cout << "\t\t ---------0.ע����¼---------\n";
	std::cout << "\t\t ----------------------------\n";
	std::cout << "��ѡ�����Ĳ���:" << std::endl;
	return;

}

//����˺�
void Manager::addPerson()
{
	std::cout << "����������˺ŵ�����" << std::endl;
	std::cout << "1.���ѧ��" << std::endl;
	std::cout << "2.�����ʦ" << std::endl;

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

//�鿴�˺�
void Manager::showPerson()
{

}

//�鿴������Ϣ
void Manager::showComputer()
{

}

//���ԤԼ��¼
void Manager::cleanFile()
{

}

