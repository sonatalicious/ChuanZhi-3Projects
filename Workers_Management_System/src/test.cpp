#include<iostream>
#include"worker.h"
#include"manager.h"
#include"employee.h"
#include"boss.h"

// ��̬�Ĳ���	
void test()
{
	Worker* worker = NULL; // �ø���ָ��ʵ�ֶ�̬
	worker = new Employee(1, "����", 1);
	worker->showInfo();
	delete worker;

	worker = new Manager(2, "����", 2);
	worker->showInfo();
	delete worker;

	worker = new Boss(3, "����", 3);
	worker->showInfo();
	delete worker;
}

