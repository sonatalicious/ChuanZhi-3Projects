#include<iostream>
#include"employee.h"

Employee::Employee(int id, std::string name, int dId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptID = dId;
}

void Employee::showInfo()
{
	std::cout << "ְ����ţ�" << this->m_Id
		<< "\tְ��������" << this->m_Name
		<< "\t��λ��" << this->getDeptName()
		<< "\t��λְ����ɾ�����������" << std::endl;
}

std::string Employee::getDeptName()
{
	return std::string("Ա��");
}
