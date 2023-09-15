#include<iostream>
#include "speechManager.h"


SpeechManager::SpeechManager()
{
	this->initSpeech(); // 初始化容器和属性
	this->creatSpeaker(); // 创建12名选手
	this->loadRecord(); // 加载往届记录
}

SpeechManager::~SpeechManager()
{

}

void SpeechManager::show_Menu()
{
	std::cout << "*************************************" << std::endl;
	std::cout << "**********欢迎参加演讲比赛***********" << std::endl;
	std::cout << "********** 1.开始演讲比赛 ***********" << std::endl;
	std::cout << "********** 2.查看往届记录 ***********" << std::endl;
	std::cout << "********** 3.清空比赛记录 ***********" << std::endl;
	std::cout << "********** 0.退出比赛程序 ***********" << std::endl;
	std::cout << "*************************************" << std::endl;

}

void SpeechManager::exitSystem()
{
	std::cout << "欢迎下次使用" << std::endl;
	system("pause");
	exit(0);
}

void SpeechManager::initSpeech()
{
	// 容器置空
	this->v1.clear();
	this->v2.clear();
	this->vVictory.clear();
	this->m_Speaker.clear();

	// 初始化比赛轮数
	this->m_Index = 1;

	// 初始化记录容器
	this->m_Record.clear();

}


void SpeechManager::creatSpeaker()
{
	std::string nameSeed = "ABCDEFGHIJKL";
	for (int i = 0; i < nameSeed.size(); i++)
	{
		std::string name = "选手";
		name += nameSeed[i];

		// 创建选手
		Speaker sp;
		sp.m_Name = name;

		for (int j = 0; j < 2; j++)
		{
			sp.m_Score[j] = 0;
		}

		// 创建选手编号 并放入到v1容器中
		this->v1.push_back(i + 10001);

		// 选手编号及其对应选手，放入到map容器中
		this->m_Speaker.insert(std::make_pair(i + 10001, sp));

	}


}


void SpeechManager::startSpeech()
{
	// 第一轮开始比赛

	// 1、抽签
	this->speechDraw();

	// 2、比赛
	this->speechContest();

	// 3、显示晋级结果
	this->showScore();

	// 第二轮开始比赛
	this->m_Index++;
	// 1、抽签
	this->speechDraw();

	// 2、比赛
	this->speechContest();

	// 3、显示晋级结果
	this->showScore();

	// 4、保存分数到文件中
	this->saveRecord();

	// 重置比赛，获取记录
	this->initSpeech(); // 初始化容器和属性
	this->creatSpeaker(); // 创建12名选手
	this->loadRecord(); // 加载往届记录

	std::cout << "本届比赛完毕！" << std::endl;
	system("pause");
	system("cls");


}


void SpeechManager::speechDraw()
{
	std::cout << "第《" << this->m_Index << "》轮比赛选手正在抽签" << std::endl;
	std::cout << "--------------------------" << std::endl;
	std::cout << "抽签后演讲顺序如下：" << std::endl;

	if (this->m_Index == 1)
	{
		// 第一轮比赛
		std::random_shuffle(v1.begin(), v1.end());
		for (std::vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
		{
			std::cout << *it << " ";
		}
		std::cout << std::endl;
	}
	else
	{
		// 第二轮比赛
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
	std::cout << "------------ 第" << this->m_Index << "轮比赛正式开始 -----------" << std::endl;

	std::multimap<double, int, std::greater<double>> groupScore; // 临时容器，存放小组成绩
	int num = 0; // 记录人员个数 6人一组
	std::vector<int>v_Src; // 比赛选手容器
	if (this->m_Index == 1)
	{
		v_Src = this->v1;
	}
	else
	{
		v_Src = this->v2;
	}

	// 遍历所有选手进行比赛
	for (std::vector<int>::iterator it = v_Src.begin(); it != v_Src.end(); it++)
	{
		num++;
		// 10个评委打分
		std::deque<double>d;
		for (int i = 0; i < 10; i++)
		{
			double score = (rand() % 401 + 600) / 10.f; // 随机600~1000 再除以10
			//std::cout << score << " ";
			d.push_back(score);
		}
		//std::cout << std::endl;
		std::sort(d.begin(), d.end(), std::greater<double>()); // 排序
		d.pop_back(); // 去掉最低分
		d.pop_front(); // 去掉最高分

		double sum = std::accumulate(d.begin(), d.end(), 0.0f); // 总分
		double avg = sum / (double)d.size(); // 平均分

		//std::cout << "编号：" << *it << " 姓名：" << this->m_Speaker[*it].m_Name << " 获取的平均分为：" << avg << std::endl << std::endl;

		this->m_Speaker[*it].m_Score[this->m_Index - 1] = avg; // 将平均分放到map容器里

		groupScore.insert(std::make_pair(avg, *it)); // 将打分数据放入到临时小组容器中，key是得分，value是具体选手编号
		// 每6人取出前三名
		if (num % 6 == 0)
		{
			std::cout << "第" << num / 6 << "小组比赛名次：" << std::endl;
			for (std::multimap<double, int, std::greater<double>>::iterator it = groupScore.begin(); it!=groupScore.end(); it++)
			{
				std::cout << "编号：" << it->second << " 姓名：" << this->m_Speaker[it->second].m_Name << 
					"成绩：" << this->m_Speaker[it->second].m_Score[m_Index - 1] << std::endl;

			}
			// 取走前三名
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

			groupScore.clear(); // 小组容器清空
			std::cout << std::endl;
		}
	}

	std::cout << "----------第" << this->m_Index << "轮比赛完毕！-----------" << std::endl;
	system("pause");


}


void SpeechManager::showScore()
{
	std::cout << "--------- 第" << this->m_Index << "轮晋级选手信息如下----------" << std::endl;
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
		std::cout << "选手编号：" << *it << " 姓名：" << m_Speaker[*it].m_Name << " 得分：" << this->m_Speaker[*it].m_Score[this->m_Index - 1] << std::endl;
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
	
	// 将每个选手的数据 写到文件中
	for (std::vector<int>::iterator it = this->vVictory.begin(); it != vVictory.end(); it++)
	{
		ofs << *it << "," << this->m_Speaker[*it].m_Score[1] << ",";
	}
	ofs << std::endl;
	ofs.close();
	
	std::cout << "记录已经保存" << std::endl;
	this->fileIsEmpty = false;
}

void SpeechManager::loadRecord()
{
	std::ifstream ifs("speech.csv", std::ios::in);

	if (!ifs.is_open())
	{
		this->fileIsEmpty = true;
		//std::cout << "文件不存在！" << std::endl;
		ifs.close();
		return;
	}

	char ch;
	ifs >> ch;
	if (ifs.eof()) // 读一个字符，看看是不是文件尾，是则为空
	{
		//std::cout << "文件为空！" << std::endl;
		this->fileIsEmpty = true;
		ifs.close();
	}

	this->fileIsEmpty = false;

	ifs.putback(ch); // 把读出来的字符放回去

	std::string data;
	int index = 0;

	while (ifs >> data)
	{
		//std::cout << data << std::endl;
		int pos = -1; // 查到“,”位置的变量
		int start = 0;
		std::vector<std::string>v; // 存放文件中拿出string的字符串

		while (true)
		{
			pos = data.find(",", start);
			if (pos == -1) // 没有找到
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
	//	//std::cout << it->first << "冠军编号：" << it->second[0] << " 分数：" << it->second[1] << std::endl;


	//}


}


void SpeechManager::showRecord()
{
	if (this->fileIsEmpty)
	{
		std::cout << "文件不存在或文件为空!" << std::endl;
	}
	else
	{
		for (int i = 0; i < this->m_Record.size(); i++)
		{
			std::cout << "第" << i + 1 << "届" <<
				"冠军编号：" << this->m_Record[i][0] << " 得分：" << this->m_Record[i][1] << " "
				"亚军编号：" << this->m_Record[i][2] << " 得分：" << this->m_Record[i][3] << " "
				"季军编号：" << this->m_Record[i][4] << " 得分：" << this->m_Record[i][5] << std::endl;
		}
	}

	system("pause");
	system("cls");
}


void SpeechManager::clearRecord()
{
	std::cout << "确认清空?" << std::endl;
	std::cout << "1、确认" << std::endl;
	std::cout << "2、返回" << std::endl;

	int select = 0;
	std::cin >> select;

	if (select == 1)
	{
		std::ofstream ofs("speech.csv", std::ios::trunc);
		ofs.close();

		this->initSpeech(); // 初始化容器和属性
		this->creatSpeaker(); // 创建12名选手
		this->loadRecord(); // 加载往届记录

		std::cout << "清空成功！" << std::endl;
	}
	system("pause");
	system("cls");
}


