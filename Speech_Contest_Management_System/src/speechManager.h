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

	std::vector<int>v1; // ����ѡ�� ���� 12��
	std::vector<int>v2; // ��һ�ֽ������� 6��
	std::vector<int>vVictory; // ʤ��ǰ�������� 3��
	std::map<int, Speaker> m_Speaker; // ��ű�ż���Ӧ�ľ���ѡ������
	std::map<int, std::vector<std::string>> m_Record; // ��������¼������
	int m_Index; // ��¼��������
	bool fileIsEmpty;

};
