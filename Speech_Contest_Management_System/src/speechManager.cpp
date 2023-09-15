#include<iostream>
#include "speechManager.h"


SpeechManager::SpeechManager()
{
	this->initSpeech(); // ��ʼ������������
	this->creatSpeaker(); // ����12��ѡ��
	this->loadRecord(); // ���������¼
}

SpeechManager::~SpeechManager()
{

}

void SpeechManager::show_Menu()
{
	std::cout << "*************************************" << std::endl;
	std::cout << "**********��ӭ�μ��ݽ�����***********" << std::endl;
	std::cout << "********** 1.��ʼ�ݽ����� ***********" << std::endl;
	std::cout << "********** 2.�鿴�����¼ ***********" << std::endl;
	std::cout << "********** 3.��ձ�����¼ ***********" << std::endl;
	std::cout << "********** 0.�˳��������� ***********" << std::endl;
	std::cout << "*************************************" << std::endl;

}

void SpeechManager::exitSystem()
{
	std::cout << "��ӭ�´�ʹ��" << std::endl;
	system("pause");
	exit(0);
}

void SpeechManager::initSpeech()
{
	// �����ÿ�
	this->v1.clear();
	this->v2.clear();
	this->vVictory.clear();
	this->m_Speaker.clear();

	// ��ʼ����������
	this->m_Index = 1;

	// ��ʼ����¼����
	this->m_Record.clear();

}


void SpeechManager::creatSpeaker()
{
	std::string nameSeed = "ABCDEFGHIJKL";
	for (int i = 0; i < nameSeed.size(); i++)
	{
		std::string name = "ѡ��";
		name += nameSeed[i];

		// ����ѡ��
		Speaker sp;
		sp.m_Name = name;

		for (int j = 0; j < 2; j++)
		{
			sp.m_Score[j] = 0;
		}

		// ����ѡ�ֱ�� �����뵽v1������
		this->v1.push_back(i + 10001);

		// ѡ�ֱ�ż����Ӧѡ�֣����뵽map������
		this->m_Speaker.insert(std::make_pair(i + 10001, sp));

	}


}


void SpeechManager::startSpeech()
{
	// ��һ�ֿ�ʼ����

	// 1����ǩ
	this->speechDraw();

	// 2������
	this->speechContest();

	// 3����ʾ�������
	this->showScore();

	// �ڶ��ֿ�ʼ����
	this->m_Index++;
	// 1����ǩ
	this->speechDraw();

	// 2������
	this->speechContest();

	// 3����ʾ�������
	this->showScore();

	// 4������������ļ���
	this->saveRecord();

	// ���ñ�������ȡ��¼
	this->initSpeech(); // ��ʼ������������
	this->creatSpeaker(); // ����12��ѡ��
	this->loadRecord(); // ���������¼

	std::cout << "���������ϣ�" << std::endl;
	system("pause");
	system("cls");


}


void SpeechManager::speechDraw()
{
	std::cout << "�ڡ�" << this->m_Index << "���ֱ���ѡ�����ڳ�ǩ" << std::endl;
	std::cout << "--------------------------" << std::endl;
	std::cout << "��ǩ���ݽ�˳�����£�" << std::endl;

	if (this->m_Index == 1)
	{
		// ��һ�ֱ���
		std::random_shuffle(v1.begin(), v1.end());
		for (std::vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
		{
			std::cout << *it << " ";
		}
		std::cout << std::endl;
	}
	else
	{
		// �ڶ��ֱ���
		std::random_shuffle(v2.begin(), v2.end());
		for (std::vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
		{
			std::cout << *it << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "--------------------------" << std::endl;
	system("pause");
	std::cout << std::endl;

}

void SpeechManager::speechContest()
{
	std::cout << "------------ ��" << this->m_Index << "�ֱ�����ʽ��ʼ -----------" << std::endl;

	std::multimap<double, int, std::greater<double>> groupScore; // ��ʱ���������С��ɼ�
	int num = 0; // ��¼��Ա���� 6��һ��
	std::vector<int>v_Src; // ����ѡ������
	if (this->m_Index == 1)
	{
		v_Src = this->v1;
	}
	else
	{
		v_Src = this->v2;
	}

	// ��������ѡ�ֽ��б���
	for (std::vector<int>::iterator it = v_Src.begin(); it != v_Src.end(); it++)
	{
		num++;
		// 10����ί���
		std::deque<double>d;
		for (int i = 0; i < 10; i++)
		{
			double score = (rand() % 401 + 600) / 10.f; // ���600~1000 �ٳ���10
			//std::cout << score << " ";
			d.push_back(score);
		}
		//std::cout << std::endl;
		std::sort(d.begin(), d.end(), std::greater<double>()); // ����
		d.pop_back(); // ȥ����ͷ�
		d.pop_front(); // ȥ����߷�

		double sum = std::accumulate(d.begin(), d.end(), 0.0f); // �ܷ�
		double avg = sum / (double)d.size(); // ƽ����

		//std::cout << "��ţ�" << *it << " ������" << this->m_Speaker[*it].m_Name << " ��ȡ��ƽ����Ϊ��" << avg << std::endl << std::endl;

		this->m_Speaker[*it].m_Score[this->m_Index - 1] = avg; // ��ƽ���ַŵ�map������

		groupScore.insert(std::make_pair(avg, *it)); // ��������ݷ��뵽��ʱС�������У�key�ǵ÷֣�value�Ǿ���ѡ�ֱ��
		// ÿ6��ȡ��ǰ����
		if (num % 6 == 0)
		{
			std::cout << "��" << num / 6 << "С��������Σ�" << std::endl;
			for (std::multimap<double, int, std::greater<double>>::iterator it = groupScore.begin(); it!=groupScore.end(); it++)
			{
				std::cout << "��ţ�" << it->second << " ������" << this->m_Speaker[it->second].m_Name << 
					"�ɼ���" << this->m_Speaker[it->second].m_Score[m_Index - 1] << std::endl;

			}
			// ȡ��ǰ����
			int count = 0;
			for (std::multimap<double, int, std::greater<double>>::iterator it = groupScore.begin(); it != groupScore.end() && count < 3; it++, count++)
			{
				if (this->m_Index == 1)
				{
					v2.push_back((*it).second);
				}
				else
				{
					vVictory.push_back((*it).second);
				}
			}

			groupScore.clear(); // С���������
			std::cout << std::endl;
		}
	}

	std::cout << "----------��" << this->m_Index << "�ֱ�����ϣ�-----------" << std::endl;
	system("pause");


}


void SpeechManager::showScore()
{
	std::cout << "--------- ��" << this->m_Index << "�ֽ���ѡ����Ϣ����----------" << std::endl;
	std::vector<int>v;
	if (this->m_Index == 1)
	{
		v = this->v2;
	}
	else
	{
		v = this->vVictory;
	}

	for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		std::cout << "ѡ�ֱ�ţ�" << *it << " ������" << m_Speaker[*it].m_Name << " �÷֣�" << this->m_Speaker[*it].m_Score[this->m_Index - 1] << std::endl;
	}
	std::cout << std::endl;
	system("pause");
	system("cls");
	this->show_Menu();

}

void SpeechManager::saveRecord()
{
	std::ofstream ofs;
	ofs.open("speech.csv", std::ios::out | std::ios::app);
	
	// ��ÿ��ѡ�ֵ����� д���ļ���
	for (std::vector<int>::iterator it = this->vVictory.begin(); it != vVictory.end(); it++)
	{
		ofs << *it << "," << this->m_Speaker[*it].m_Score[1] << ",";
	}
	ofs << std::endl;
	ofs.close();
	
	std::cout << "��¼�Ѿ�����" << std::endl;
	this->fileIsEmpty = false;
}

void SpeechManager::loadRecord()
{
	std::ifstream ifs("speech.csv", std::ios::in);

	if (!ifs.is_open())
	{
		this->fileIsEmpty = true;
		//std::cout << "�ļ������ڣ�" << std::endl;
		ifs.close();
		return;
	}

	char ch;
	ifs >> ch;
	if (ifs.eof()) // ��һ���ַ��������ǲ����ļ�β������Ϊ��
	{
		//std::cout << "�ļ�Ϊ�գ�" << std::endl;
		this->fileIsEmpty = true;
		ifs.close();
	}

	this->fileIsEmpty = false;

	ifs.putback(ch); // �Ѷ��������ַ��Ż�ȥ

	std::string data;
	int index = 0;

	while (ifs >> data)
	{
		//std::cout << data << std::endl;
		int pos = -1; // �鵽��,��λ�õı���
		int start = 0;
		std::vector<std::string>v; // ����ļ����ó�string���ַ���

		while (true)
		{
			pos = data.find(",", start);
			if (pos == -1) // û���ҵ�
			{
				break;
			}
			std::string temp = data.substr(start, pos - start);
			//std::cout << temp << std::endl;
			v.push_back(temp);
			start = pos + 1;
		}
		this->m_Record.insert(std::make_pair(index, v));
		index++;

	}
	ifs.close();

	//for (std::map<int, std::vector<std::string>>::iterator it = this->m_Record.begin(); it != this->m_Record.end(); it++ )
	//{
	//	//std::cout << it->first << "�ھ���ţ�" << it->second[0] << " ������" << it->second[1] << std::endl;


	//}


}


void SpeechManager::showRecord()
{
	if (this->fileIsEmpty)
	{
		std::cout << "�ļ������ڻ��ļ�Ϊ��!" << std::endl;
	}
	else
	{
		for (int i = 0; i < this->m_Record.size(); i++)
		{
			std::cout << "��" << i + 1 << "��" <<
				"�ھ���ţ�" << this->m_Record[i][0] << " �÷֣�" << this->m_Record[i][1] << " "
				"�Ǿ���ţ�" << this->m_Record[i][2] << " �÷֣�" << this->m_Record[i][3] << " "
				"������ţ�" << this->m_Record[i][4] << " �÷֣�" << this->m_Record[i][5] << std::endl;
		}
	}

	system("pause");
	system("cls");
}


void SpeechManager::clearRecord()
{
	std::cout << "ȷ�����?" << std::endl;
	std::cout << "1��ȷ��" << std::endl;
	std::cout << "2������" << std::endl;

	int select = 0;
	std::cin >> select;

	if (select == 1)
	{
		std::ofstream ofs("speech.csv", std::ios::trunc);
		ofs.close();

		this->initSpeech(); // ��ʼ������������
		this->creatSpeaker(); // ����12��ѡ��
		this->loadRecord(); // ���������¼

		std::cout << "��ճɹ���" << std::endl;
	}
	system("pause");
	system("cls");
}


