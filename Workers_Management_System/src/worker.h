#pragma once
#include<iostream>
#include<string>

// ����һ��Ա���ĳ����࣬��Ϊ����
class Worker
{
public:
	// ��ʾ������Ϣ
	virtual void showInfo() = 0;
	// ��ȡ��λ����
	virtual std::string getDeptName() = 0;

	int m_Id; // ְ�����
	std::string m_Name;
	int m_DeptID;

};


