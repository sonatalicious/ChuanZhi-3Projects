#include<iostream>
#include"manager.h"

Manager::Manager(int id, std::string name, int dId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptID = dId;
}

void Manager::showInfo()
{
	std::cout << "ְ����ţ�" << this->m_Id
		<< "\tְ��������" << this->m_Name
		<< "\t��λ��" << this->getDeptName()
		<< "\t��λְ������ϰ彻�������񣬲��·������Ա��" << std::endl;
}

std::string Manager::getDeptName()
{
	return std::string("����");
}

