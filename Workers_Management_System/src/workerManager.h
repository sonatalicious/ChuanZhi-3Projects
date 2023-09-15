#pragma once
#include<iostream>
#include<fstream>
#include"Worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"

#define FILENAME "empFile.txt"


class WorkerManager
{
public:
	WorkerManager();
	~WorkerManager();

	void Add_Emp();
	void save();
	int get_EmpNum();
	void init_Emp();
	void show_Emp();
	void del_Emp();
	int IsExist(int id);
	void mod_Emp();
	void find_Emp();
	void sort_Emp();
	void clean_File();

	int m_EmpNum;
	Worker** m_EmpArray;
	bool m_FileIsEmpty;

public:
	void showMenu()
	{
		std::cout << "**************************************" << std::endl;
		std::cout << "*********欢迎使用职工管理系统*********" << std::endl;
		std::cout << "**********  0.退出管理程序  **********" << std::endl;
		std::cout << "**********  1.增加职工信息  **********" << std::endl;
		std::cout << "**********  2.显示职工信息  **********" << std::endl;
		std::cout << "**********  3.删除离职职工  **********" << std::endl;
		std::cout << "**********  4.修改职工信息  **********" << std::endl;
		std::cout << "**********  5.查找职工信息  **********" << std::endl;
		std::cout << "**********  6.按照编号排序  **********" << std::endl;
		std::cout << "**********  7.清空所有文档  **********" << std::endl;
		std::cout << "**************************************" << std::endl;
		std::cout << std::endl;
	}

	void exitSystem()
	{
		std::cout << "欢迎下次使用！" << std::endl;
		system("pause");
		exit(0);
	}

};

// 构造函数
WorkerManager::WorkerManager(): m_EmpNum(0), m_EmpArray(NULL)
{
	std::ifstream ifs;
	ifs.open(FILENAME, std::ios::in);

	// 数据存储文件不存在情况
	if (!ifs.is_open())
	{
		std::cout << "数据存储文件不存在" << std::endl;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	// 数据存储文件存在且为空
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		std::cout << "数据存储文件为空" << std::endl;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	// 数据存储文件存在且记录了数据
	int num = this->get_EmpNum();
	std::cout << "数据存储文件共存储了" << num << "条职工数据" << std::endl;
	this->m_EmpNum = num;
	
	// 将数据存储文件中数据存到数组中
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	this->init_Emp();
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		std::cout << "职工编号：" << this->m_EmpArray[i]->m_Id
			<< "\t职工姓名：" << this->m_EmpArray[i]->m_Name
			<< "\t部门编号：" << this->m_EmpArray[i]->m_DeptID << std::endl;

	}

}

// 析构函数
WorkerManager::~WorkerManager()
{

	if (this->m_EmpArray != NULL)
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			if (this->m_EmpArray[i] != NULL)
			{
				delete this->m_EmpArray[i]; // 清空堆区
			}
		}
		delete[] this->m_EmpArray; // 释放内存
		this->m_EmpArray = NULL;
	}
}

// 增加职工数据
void WorkerManager::Add_Emp()
{
	std::cout << "请输入增加职工数量：" << std::endl;
	int addNum = 0;
	std::cin >> addNum;

	if (addNum > 0)
	{
		int newSize = this->m_EmpNum + addNum; // 计算新空间大小
		Worker** newSpace = new Worker* [newSize]; // 分配新空间
		// 将原来数据复制到新空间中
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}
		// 添加新数据
		for (int i = 0; i < addNum; i++)
		{
			int id;
			std::string name;
			int dSelect;

			std::cout << "请输入第" << i + 1 << "位新职工编号：" << std::endl;
			std::cin >> id;
			std::cout << "请输入第" << i + 1 << "位新职工姓名：" << std::endl;
			std::cin >> name;
			std::cout << "请选择职工岗位：" << std::endl;
			std::cout << "1、普通职工" << std::endl;
			std::cout << "2、经理" << std::endl;
			std::cout << "3、老板" << std::endl;
			std::cin >> dSelect;

			Worker* worker = NULL;

			switch (dSelect)
			{
			case 1:
				worker = new Employee(id, name, dSelect);
				break;
			case 2:
				worker = new Manager(id, name, dSelect);
				break;
			case 3:
				worker = new Boss(id, name, dSelect);
				break;
			default:
				break;
			}
			
			// 创造职工职责，保存到数组中
			newSpace[this->m_EmpNum + i] = worker;
		}
		// 释放原有空间
		delete[] this->m_EmpArray;
		// 更改新空间指向
		this->m_EmpArray = newSpace;
		// 更新职工总人数
		this->m_EmpNum = newSize;
		// 文件不为空
		this->m_FileIsEmpty = false;
		// 提示添加成功
		std::cout << "成功添加" << addNum << "名新职工" << std::endl;
		// 保存数据
		this->save();

	}
	else
	{
		std::cout << "输入有误" << std::endl;
	}
	system("pause");
	system("cls");
}

// 保存数据到文件中
void WorkerManager::save()
{
	std::ofstream ofs; // 文件输出流对象
	ofs.open(FILENAME, std::ios::out);
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptID << std::endl;
	}
	ofs.close();
}

// 得到文件中存储职工数量
int WorkerManager::get_EmpNum()
{
	std::ifstream ifs;
	ifs.open(FILENAME, std::ios::in);

	int id;
	std::string name;
	int dId;

	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		num++;
	}
	ifs.close();
	return num;

}

// 得到数据存储文件中的职工信息，并初始化加载此信息
void WorkerManager::init_Emp()
{
	std::ifstream ifs;
	ifs.open(FILENAME, std::ios::in);

	int id;
	std::string name;
	int dId;

	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		Worker* worker = NULL;
		switch (dId)
		{
		case 1:
			worker = new Employee(id, name, dId);
			break;
		case 2:
			worker = new Manager(id, name, dId);
			break;
		case 3:
			worker = new Boss(id, name, dId);
			break;
		default:
			break;
		}

		this->m_EmpArray[index] = worker;
		index++;
	}
	ifs.close();

}

// 显示职工信息
void WorkerManager::show_Emp()
{
	if (this->m_FileIsEmpty)
	{
		std::cout << "文件不存在或为空" << std::endl;
	}
	else
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			this->m_EmpArray[i]->showInfo(); // 调用多态接口
		}
	}
	system("pause");
	system("cls");
}

// 删除职工信息
void WorkerManager::del_Emp()
{
	if (this->m_FileIsEmpty)
		std::cout << "文件不存在或记录为空" << std::endl;
	else
	{
		int id;
		std::cout << "请输入删除职工的ID：" << std::endl;
		std::cin >> id;
		int index = this->IsExist(id);
		if (index != -1) // 职工存在并要删除
		{
			for (int i = index; i < this->m_EmpNum; i++) // 后一个数据前移
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			this->m_EmpNum--; // 更新并保存数据
			this->save();
			std::cout << "删除成功" << std::endl;
		}
		else // 职工不存在
		{
			std::cout << "职工不存在，删除失败" << std::endl;
		}
	}
	system("pause");
	system("cls");
}

// 判断职工是否存在
int WorkerManager::IsExist(int id)
{
	for (int i = 0; i < this->m_EmpNum; i++)
		if (this->m_EmpArray[i]->m_Id == id)
			return i;
	return -1;
}

// 修改职工信息
void WorkerManager::mod_Emp()
{
	if (this->m_FileIsEmpty)
		std::cout << "文件不存在或记录为空" << std::endl;
	else
	{
		int id;
		std::cout << "请输入修改职工的ID：" << std::endl;
		std::cin >> id;
		int index = this->IsExist(id);
		if (index != -1) // 职工存在并要修改
		{
			delete this->m_EmpArray[index]; // 释放内存
			int nId;
			std::string nName;
			int nDepSlesct;

			std::cout << "找到ID为：" << id << "的职工，请输入职工新ID："  << std::endl;
			std::cin >> nId;

			std::cout << "请输入岗位：" << std::endl;
			std::cin >> nName;

			std::cout << "请选择职工岗位：" << std::endl;
			std::cout << "1、普通职工" << std::endl;
			std::cout << "2、经理" << std::endl;
			std::cout << "3、老板" << std::endl;
			std::cin >> nDepSlesct;

			Worker* worker = NULL;
			switch(nDepSlesct)
			{
			case 1:
				worker = new Employee(nId, nName, nDepSlesct);
				break;
			case 2:
				worker = new Manager(nId, nName, nDepSlesct);
				break;
			case 3:
				worker = new Boss(nId, nName, nDepSlesct);
				break;
			default:
				break;
			}
			this->m_EmpArray[index] = worker;

			this->save(); // 更新并保存数据
			std::cout << "修改成功" << std::endl;
		}
		else // 职工不存在
		{
			std::cout << "职工不存在，修改失败" << std::endl;
		}
	}
	system("pause");
	system("cls");

}

// 查找职工信息
void WorkerManager::find_Emp()
{
	if (this->m_FileIsEmpty)
		std::cout << "文件不存在或记录为空" << std::endl;
	else
	{
		std::cout << "请输入查找方式" << std::endl;
		std::cout << "1、按职工ID查找" << std::endl;
		std::cout << "2、按职工姓名查找" << std::endl;

		int select = 0;
		std::cin >> select;

		switch (select)
		{
		case 1:
		{
			int id;
			std::cout << "请输入职工ID:" << std::endl;
			std::cin >> id;

			int index = this->IsExist(id);
			if (index != -1)
			{
				this->m_EmpArray[index]->showInfo();
			}
			else
			{
				std::cout << "职工不存在，显示失败" << std::endl;
			}
			break;
		}
		case 2:
		{
			std::string name;
			std::cout << "请输入职工姓名:" << std::endl;
			std::cin >> name;
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_Name == name)
				{
					std::cout << "查找成功: ";
					m_EmpArray[i]->showInfo();
					break;
				}
			}
			std::cout << "职工不存在，显示失败" << std::endl;
			break;
		}
		default:
			std::cout << "输入错误" << std::endl;
			break;
		}
	}
	system("pause");
	system("cls");
}

void WorkerManager::sort_Emp()
{
	if (this->m_FileIsEmpty)
		std::cout << "文件不存在或记录为空" << std::endl;
	else
	{
		std::cout << "请输入排序方式" << std::endl;
		std::cout << "1、按职工ID进行升序" << std::endl;
		std::cout << "2、按职工ID进行降序" << std::endl;

		int select = 0;
		std::cin >> select;

		for (int i = 0; i < this->m_EmpNum; i++) // 开始选择排序
		{
			int minOrMax = i;
			for (int j = i + 1; j < this->m_EmpNum; j++)
			{
				if (select == 1)
				{
					if (this->m_EmpArray[minOrMax]->m_Id > this->m_EmpArray[j]->m_Id)
					{
						minOrMax = j;
					}
				}
				else
				{
					if (this->m_EmpArray[minOrMax]->m_Id < this->m_EmpArray[j]->m_Id)
					{
						minOrMax = j;
					}
				}
			}

			if (i != minOrMax)
			{
				Worker* temp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[minOrMax];
				this->m_EmpArray[minOrMax] = temp;
			}
		}
		std::cout << "排序成功" << std::endl;
		this->save();
	}
	system("pause");
	system("cls");
}

void WorkerManager::clean_File()
{
	std::cout << "确定是否清空？" << std::endl;
	std::cout << "1、确认" << std::endl;
	std::cout << "2、返回" << std::endl;

	int select = 0;
	std::cin >> select;

	if (select == 1)
	{
		// 打开模式 ios::trunc，如果存在删除文件并重新创建
		std::ofstream ofs(FILENAME, std::ios::trunc);
		ofs.close();

		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i] != NULL)
				{
					delete this->m_EmpArray[i]; // 清空堆区
				}
			}
			this->m_EmpNum = 0;
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_FileIsEmpty = true;
		}
		std::cout << "清空成功" << std::endl;
	}

	system("pause");
	system("cls");

}

