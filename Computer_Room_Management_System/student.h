#pragma once
#include<iostream>
#include"Identity.h"

//ѧ�������
class Student :public Identity
{
public:
	//Ĭ�Ϲ���
	Student();

	//�вι��죨ѧ�ţ����������룩
	Student(int id, std::string name, std::string pwd);

	//�˵�����
	virtual void operMenu();

	//����ԤԼ
	void applyOrder();

	//�鿴�ҵ�ԤԼ
	void showMyOrder();

	//�鿴����ԤԼ
	void showAllOrder();

	//ȡ��ԤԼ
	void cancelOrder();

	int m_Id; //ѧ��ѧ��


};


