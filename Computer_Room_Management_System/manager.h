#pragma once
#include<iostream>
#include"identity.h"

//����Ա�����
class Manager :public Identity
{
public:
	//Ĭ�Ϲ���
	Manager();

	//�вι��죨����Ա���������룩
	Manager(std::string name, std::string pwd);

	//ѡ��˵�
	virtual void operMenu();

	//����˺�
	void addPerson();

	//�鿴�˺�
	void showPerson();

	//�鿴������Ϣ
	void showComputer();

	//���ԤԼ��¼
	void cleanFile();






};
