#pragma once
#include<iostream>
#include"worker.h"


class Boss :public Worker
{
public:
	Boss(int id, std::string name, int dId);
	virtual void showInfo();
	virtual std::string getDeptName();
};