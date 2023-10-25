#pragma once
#include<iostream>
#include"Identity.h"

//学生类设计
class Student :public Identity
{
public:
	//默认构造
	Student();

	//有参构造（学号，姓名，密码）
	Student(int id, std::string name, std::string pwd);

	//菜单界面
	virtual void operMenu();

	//申请预约
	void applyOrder();

	//查看我的预约
	void showMyOrder();

	//查看所有预约
	void showAllOrder();

	//取消预约
	void cancelOrder();

	int m_Id; //学生学号


};


