#pragma once

#include<iostream>
#include"identity.h"

//��ʦ�����
class Teacher : public Identity
{
public:

	//Ĭ�Ϲ���
	Teacher();

	//�вι��죨ְ����ţ����������룩
	Teacher(int empId, std::string name, std::string pwd);

	//�˵�����
	virtual void operMenu();

	//�鿴����ԤԼ
	void showAllOrder();

	//���ԤԼ
	void validOrder();

	int m_EmpId; //��ʦ���

};
