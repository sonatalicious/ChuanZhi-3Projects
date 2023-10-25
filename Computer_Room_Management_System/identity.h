#pragma once
#include<iostream>


//身份抽象类
class Identity
{
public:

	//操作菜单
	virtual void operMenu() = 0;

	std::string m_Name; //用户名
	std::string m_Pwd; //密码


};


