#pragma once
#include<iostream>
#include"worker.h"


class Manager :public Worker
{
public:
	Manager(int id, std::string name, int dId);
	virtual void showInfo();
	virtual std::string getDeptName();
};