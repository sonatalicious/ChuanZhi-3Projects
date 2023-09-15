#pragma once
#include<vector>
#include<map>
#include"speaker.h"
#include"algorithm"
#include<deque>
#include<string>
#include<functional>
#include<fstream>
#include<numeric>

class SpeechManager
{

public:
	SpeechManager();
	~SpeechManager();

	void show_Menu();
	void exitSystem();
	void initSpeech();
	void creatSpeaker();
	void startSpeech();
	void speechDraw();
	void speechContest();
	void showScore();
	void saveRecord();
	void loadRecord();
	void showRecord();
	void clearRecord();

	std::vector<int>v1; // 比赛选手 容器 12人
	std::vector<int>v2; // 第一轮晋级容器 6人
	std::vector<int>vVictory; // 胜利前三名容器 3人
	std::map<int, Speaker> m_Speaker; // 存放编号及对应的具体选手容器
	std::map<int, std::vector<std::string>> m_Record; // 存放往届记录的容器
	int m_Index; // 记录比赛轮数
	bool fileIsEmpty;

};
