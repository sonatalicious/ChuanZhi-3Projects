/********************
 项目：通讯录管理系统
 目的：拥有基础c++编程能力
 包含：语法函数分支引用结构体命名方法的应用
********************/

#include <iostream>
#include <string>

#define MAX 1000 // 最大人数

// 菜单界面
void showMenu() 
{
	std::cout << "*************************" << std::endl;
	std::cout << "***** 1、添加联系人 *****" << std::endl;
	std::cout << "***** 2、显示联系人 *****" << std::endl;
	std::cout << "***** 3、删除联系人 *****" << std::endl;
	std::cout << "***** 4、查找联系人 *****" << std::endl;
	std::cout << "***** 5、修改联系人 *****" << std::endl;
	std::cout << "***** 6、清空联系人 *****" << std::endl;
	std::cout << "***** 0、退出通讯录 *****" << std::endl;
	std::cout << "*************************" << std::endl;
}

// 联系人结构体
struct Person 
{
public:
	std::string m_Name; // 姓名
	int  m_Sex; // 性别：1男 2女
	int m_Age; // 年龄
	std::string m_Phone; // 电话
	std::string m_Addr; // 住址
};

// 通讯录结构体
struct AdressBook
{
public:
	Person personArray[MAX]; // 通讯录保存的人员信息数组
	int m_Size = 0; //通讯录中人员个数
};

// 1、添加联系人
void addPerson(AdressBook& abk)
{
	// 判断通讯录是否已满
	if (abk.m_Size == MAX)
	{
		std::cout << "通讯录已满，无法添加！" << std:: endl;
		return;
	}
	else // 添加联系人
	{
		// 姓名
		std::cout << "请输入姓名:" << std::endl;
		std::cin >> abk.personArray[abk.m_Size].m_Name;
		// 性别
		int sex;
		while (true) {
			std::cout << "请输入性别: \n 1 --- 男 2 --- 女" << std::endl;
			std::cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abk.personArray[abk.m_Size].m_Sex = sex;
				break;
			}
			std::cout << "输入错误，请重新输入" << std::endl;
		}
		// 年龄
		std::cout << "请输入年龄:" << std::endl;
		std::cin >> abk.personArray[abk.m_Size].m_Age;
		// 电话
		std::cout << "请输入电话:" << std::endl;
		std::cin >> abk.personArray[abk.m_Size].m_Phone;
		// 住址
		std::cout << "请输入住址:" << std::endl;
		std::cin >> abk.personArray[abk.m_Size].m_Addr;

		abk.m_Size++;
		std::cout << "添加成功" << std::endl;
	}
	system("pause");
	system("cls");
}

// 2、显示联系人
void showPerson(AdressBook& abk)
{
	if (abk.m_Size == 0)
	{
		std::cout << "当前项目为空" << std::endl;
	}
	else
	{
		for (int i = 0; i < abk.m_Size; i++)
		{
			std::cout << "姓名：" << abk.personArray[i].m_Name << "\t";
			std::cout << "性别：" << (abk.personArray[i].m_Sex == 1 ? "男" : "女") << "\t";
			std::cout << "年龄：" << abk.personArray[i].m_Age << "\t";
			std::cout << "电话：" << abk.personArray[i].m_Phone << "\t";
			std::cout << "住址：" << abk.personArray[i].m_Addr << std::endl;
		}
	}
	system("pause");
	system("cls");
}

// 检测联系人是否存在，存在则返回其在数组中位置
int isExist(AdressBook& abk, std::string name)
{
	for (int i = 0; i < abk.m_Size; i++)
	{
		if (abk.personArray[i].m_Name == name)
			return i;
	}
	return -1;
}

// 3、删除联系人
void deletePerson(AdressBook& abk)
{
	std::cout << "请输入删除联系人姓名：" << std::endl;
	std::string name;
	std::cin >> name;
	int index = isExist(abk, name);
	if (index == -1)
	{
		std::cout << "查无此人" << std::endl;
		return;
	}
	else if(abk.m_Size != MAX) // 数据数量不为最大值MAX时
	{
		for (int i = index; i < abk.m_Size; i++) // 数据前移
		{
			abk.personArray[i] = abk.personArray[i + 1]; // 数据量为最大值MAX时会发生内存溢出
		}
		abk.m_Size--;
		std::cout << "删除成功" << std::endl;
	}
	else // 数据数量为最大值时
	{
		for (int i = index; i < MAX - 1; i++) // 注意数量的数据前移
		{
			abk.personArray[i] = abk.personArray[i + 1];
		}
		abk.m_Size--;
		std::cout << "删除成功" << std::endl;
	}
	system("pause");
	system("cls");
}

// 4、查找联系人信息
void findPerson(AdressBook& abk)
{
	std::cout << "请输入查找联系人姓名：" << std::endl;
	std::string name;
	std::cin >> name;
	int index = isExist(abk, name);
	if(index == -1)
	{
		std::cout << "查无此人" << std::endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < abk.m_Size; i++)
	{
		if (abk.personArray[i].m_Name == name) // 同名的也查
		{
			std::cout << "姓名：" << abk.personArray[i].m_Name << "\t";
			std::cout << "性别：" << (abk.personArray[i].m_Sex == 1 ? "男" : "女") << "\t";
			std::cout << "年龄：" << abk.personArray[i].m_Age << "\t";
			std::cout << "电话：" << abk.personArray[i].m_Phone << "\t";
			std::cout << "住址：" << abk.personArray[i].m_Addr << std::endl;
		}
	}
	system("pause");
	system("cls");
}

// 修改联系人信息
void modifyPerson(AdressBook& abk)
{
	std::cout << "请输入修改联系人姓名：" << std::endl;
	std::string name;
	std::cin >> name;
	int index = isExist(abk, name);
	if (index == -1)
	{
		std::cout << "查无此人" << std::endl;
		system("pause");
		system("cls");
		return;
	}

	// 姓名
	std::cout << "请输入姓名:" << std::endl;
	std::cin >> abk.personArray[index].m_Name;
	// 性别
	int sex;
	while (true) {
		std::cout << "请输入性别: \n 1 --- 男 2 --- 女" << std::endl;
		std::cin >> sex;
		if (sex == 1 || sex == 2)
		{
			abk.personArray[index].m_Sex = sex;
			break;
		}
		std::cout << "输入错误，请重新输入" << std::endl;
	}
	// 年龄
	std::cout << "请输入年龄:" << std::endl;
	std::cin >> abk.personArray[index].m_Age;
	// 电话
	std::cout << "请输入电话:" << std::endl;
	std::cin >> abk.personArray[index].m_Phone;
	// 住址
	std::cout << "请输入住址:" << std::endl;
	std::cin >> abk.personArray[index].m_Addr;
	std::cout << "修改成功" << std::endl;
	system("pause");
	system("cls");
}

// 清空所有联系人（逻辑上）
void clearPerson(AdressBook& abk)
{
	abk.m_Size = 0;
	std::cout << "通讯录已清空" << std::endl;
	system("pause");
	system("cls");
}

int main() {

	AdressBook abk; // 创建通讯录结构体变量

	int select = 0; // 创建用户操作代码变量


	while(true)
	{
		// 清除屏幕并显示菜单
		system("cls");
		showMenu();
		std::cout << "请输入操作代码：";
		std::cin >> select;
		switch (select)
		{
		case 1: // 1、添加联系人
		{
			addPerson(abk); // 传递引用，修改实参
		}
			break;
		case 2: // 2、显示联系人
		{
			showPerson(abk);
		}
			break;
		case 3: // 3、删除联系人
		{
			deletePerson(abk);
		}
			break;
		case 4: // 4、查找联系人
		{
			findPerson(abk);
		}
			break;
		case 5: // 5、修改联系人
		{
			modifyPerson(abk);
		}
			break;
		case 6: // 6、清空联系人
		{
			clearPerson(abk);
		}
			break;
		case 0: // 0、退出通讯录
		{
			std::cout << "欢迎下次使用" << std::endl;
			system("pause");
			return 0;
		}
		default:
			break;
		}
	}


}
