#pragma once
#include<iostream>
#include<string>

// 这是一个员工的抽象类，作为基类
class Worker
{
public:
	// 显示个人信息
	virtual void showInfo() = 0;
	// 获取岗位名称
	virtual std::string getDeptName() = 0;

	int m_Id; // 职工编号
	std::string m_Name;
	int m_DeptID;

};


