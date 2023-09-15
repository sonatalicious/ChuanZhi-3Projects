#include<iostream>
#include"worker.h"
#include"manager.h"
#include"employee.h"
#include"boss.h"

// 多态的测试	
void test()
{
	Worker* worker = NULL; // 用父类指针实现多态
	worker = new Employee(1, "张三", 1);
	worker->showInfo();
	delete worker;

	worker = new Manager(2, "李四", 2);
	worker->showInfo();
	delete worker;

	worker = new Boss(3, "王五", 3);
	worker->showInfo();
	delete worker;
}

