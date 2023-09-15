/********************
 ��Ŀ��ͨѶ¼����ϵͳ
 Ŀ�ģ�ӵ�л���c++�������
 �������﷨������֧���ýṹ������������Ӧ��
********************/

#include <iostream>
#include <string>

#define MAX 1000 // �������

// �˵�����
void showMenu() 
{
	std::cout << "*************************" << std::endl;
	std::cout << "***** 1�������ϵ�� *****" << std::endl;
	std::cout << "***** 2����ʾ��ϵ�� *****" << std::endl;
	std::cout << "***** 3��ɾ����ϵ�� *****" << std::endl;
	std::cout << "***** 4��������ϵ�� *****" << std::endl;
	std::cout << "***** 5���޸���ϵ�� *****" << std::endl;
	std::cout << "***** 6�������ϵ�� *****" << std::endl;
	std::cout << "***** 0���˳�ͨѶ¼ *****" << std::endl;
	std::cout << "*************************" << std::endl;
}

// ��ϵ�˽ṹ��
struct Person 
{
public:
	std::string m_Name; // ����
	int  m_Sex; // �Ա�1�� 2Ů
	int m_Age; // ����
	std::string m_Phone; // �绰
	std::string m_Addr; // סַ
};

// ͨѶ¼�ṹ��
struct AdressBook
{
public:
	Person personArray[MAX]; // ͨѶ¼�������Ա��Ϣ����
	int m_Size = 0; //ͨѶ¼����Ա����
};

// 1�������ϵ��
void addPerson(AdressBook& abk)
{
	// �ж�ͨѶ¼�Ƿ�����
	if (abk.m_Size == MAX)
	{
		std::cout << "ͨѶ¼�������޷���ӣ�" << std:: endl;
		return;
	}
	else // �����ϵ��
	{
		// ����
		std::cout << "����������:" << std::endl;
		std::cin >> abk.personArray[abk.m_Size].m_Name;
		// �Ա�
		int sex;
		while (true) {
			std::cout << "�������Ա�: \n 1 --- �� 2 --- Ů" << std::endl;
			std::cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abk.personArray[abk.m_Size].m_Sex = sex;
				break;
			}
			std::cout << "�����������������" << std::endl;
		}
		// ����
		std::cout << "����������:" << std::endl;
		std::cin >> abk.personArray[abk.m_Size].m_Age;
		// �绰
		std::cout << "������绰:" << std::endl;
		std::cin >> abk.personArray[abk.m_Size].m_Phone;
		// סַ
		std::cout << "������סַ:" << std::endl;
		std::cin >> abk.personArray[abk.m_Size].m_Addr;

		abk.m_Size++;
		std::cout << "��ӳɹ�" << std::endl;
	}
	system("pause");
	system("cls");
}

// 2����ʾ��ϵ��
void showPerson(AdressBook& abk)
{
	if (abk.m_Size == 0)
	{
		std::cout << "��ǰ��ĿΪ��" << std::endl;
	}
	else
	{
		for (int i = 0; i < abk.m_Size; i++)
		{
			std::cout << "������" << abk.personArray[i].m_Name << "\t";
			std::cout << "�Ա�" << (abk.personArray[i].m_Sex == 1 ? "��" : "Ů") << "\t";
			std::cout << "���䣺" << abk.personArray[i].m_Age << "\t";
			std::cout << "�绰��" << abk.personArray[i].m_Phone << "\t";
			std::cout << "סַ��" << abk.personArray[i].m_Addr << std::endl;
		}
	}
	system("pause");
	system("cls");
}

// �����ϵ���Ƿ���ڣ������򷵻�����������λ��
int isExist(AdressBook& abk, std::string name)
{
	for (int i = 0; i < abk.m_Size; i++)
	{
		if (abk.personArray[i].m_Name == name)
			return i;
	}
	return -1;
}

// 3��ɾ����ϵ��
void deletePerson(AdressBook& abk)
{
	std::cout << "������ɾ����ϵ��������" << std::endl;
	std::string name;
	std::cin >> name;
	int index = isExist(abk, name);
	if (index == -1)
	{
		std::cout << "���޴���" << std::endl;
		return;
	}
	else if(abk.m_Size != MAX) // ����������Ϊ���ֵMAXʱ
	{
		for (int i = index; i < abk.m_Size; i++) // ����ǰ��
		{
			abk.personArray[i] = abk.personArray[i + 1]; // ������Ϊ���ֵMAXʱ�ᷢ���ڴ����
		}
		abk.m_Size--;
		std::cout << "ɾ���ɹ�" << std::endl;
	}
	else // ��������Ϊ���ֵʱ
	{
		for (int i = index; i < MAX - 1; i++) // ע������������ǰ��
		{
			abk.personArray[i] = abk.personArray[i + 1];
		}
		abk.m_Size--;
		std::cout << "ɾ���ɹ�" << std::endl;
	}
	system("pause");
	system("cls");
}

// 4��������ϵ����Ϣ
void findPerson(AdressBook& abk)
{
	std::cout << "�����������ϵ��������" << std::endl;
	std::string name;
	std::cin >> name;
	int index = isExist(abk, name);
	if(index == -1)
	{
		std::cout << "���޴���" << std::endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < abk.m_Size; i++)
	{
		if (abk.personArray[i].m_Name == name) // ͬ����Ҳ��
		{
			std::cout << "������" << abk.personArray[i].m_Name << "\t";
			std::cout << "�Ա�" << (abk.personArray[i].m_Sex == 1 ? "��" : "Ů") << "\t";
			std::cout << "���䣺" << abk.personArray[i].m_Age << "\t";
			std::cout << "�绰��" << abk.personArray[i].m_Phone << "\t";
			std::cout << "סַ��" << abk.personArray[i].m_Addr << std::endl;
		}
	}
	system("pause");
	system("cls");
}

// �޸���ϵ����Ϣ
void modifyPerson(AdressBook& abk)
{
	std::cout << "�������޸���ϵ��������" << std::endl;
	std::string name;
	std::cin >> name;
	int index = isExist(abk, name);
	if (index == -1)
	{
		std::cout << "���޴���" << std::endl;
		system("pause");
		system("cls");
		return;
	}

	// ����
	std::cout << "����������:" << std::endl;
	std::cin >> abk.personArray[index].m_Name;
	// �Ա�
	int sex;
	while (true) {
		std::cout << "�������Ա�: \n 1 --- �� 2 --- Ů" << std::endl;
		std::cin >> sex;
		if (sex == 1 || sex == 2)
		{
			abk.personArray[index].m_Sex = sex;
			break;
		}
		std::cout << "�����������������" << std::endl;
	}
	// ����
	std::cout << "����������:" << std::endl;
	std::cin >> abk.personArray[index].m_Age;
	// �绰
	std::cout << "������绰:" << std::endl;
	std::cin >> abk.personArray[index].m_Phone;
	// סַ
	std::cout << "������סַ:" << std::endl;
	std::cin >> abk.personArray[index].m_Addr;
	std::cout << "�޸ĳɹ�" << std::endl;
	system("pause");
	system("cls");
}

// ���������ϵ�ˣ��߼��ϣ�
void clearPerson(AdressBook& abk)
{
	abk.m_Size = 0;
	std::cout << "ͨѶ¼�����" << std::endl;
	system("pause");
	system("cls");
}

int main() {

	AdressBook abk; // ����ͨѶ¼�ṹ�����

	int select = 0; // �����û������������


	while(true)
	{
		// �����Ļ����ʾ�˵�
		system("cls");
		showMenu();
		std::cout << "������������룺";
		std::cin >> select;
		switch (select)
		{
		case 1: // 1�������ϵ��
		{
			addPerson(abk); // �������ã��޸�ʵ��
		}
			break;
		case 2: // 2����ʾ��ϵ��
		{
			showPerson(abk);
		}
			break;
		case 3: // 3��ɾ����ϵ��
		{
			deletePerson(abk);
		}
			break;
		case 4: // 4��������ϵ��
		{
			findPerson(abk);
		}
			break;
		case 5: // 5���޸���ϵ��
		{
			modifyPerson(abk);
		}
			break;
		case 6: // 6�������ϵ��
		{
			clearPerson(abk);
		}
			break;
		case 0: // 0���˳�ͨѶ¼
		{
			std::cout << "��ӭ�´�ʹ��" << std::endl;
			system("pause");
			return 0;
		}
		default:
			break;
		}
	}


}
