#include<iostream>
#include"boss.h"

Boss::Boss(int id, std::string name, int dId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptID = dId;
}

void Boss::showInfo()
{
	std::cout << "ְ����ţ�" << this->m_Id
		<< "\tְ��������" << this->m_Name
		<< "\t��λ��" << this->getDeptName()
		<< "\t��λְ�𣺹���˾��������" << std::endl;
}

std::string Boss::getDeptName()
{
	return std::string("�ܲ�");
}

