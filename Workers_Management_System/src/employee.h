#pragma once
#include<iostream>
#include"worker.h"


class Employee :public Worker
{
public:
	Employee(int id, std::string name, int dId);
	virtual void showInfo();
	virtual std::string getDeptName();
};
