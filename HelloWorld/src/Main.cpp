#include <iostream>
#include <algorithm>

void Log(const char* massage);
int Multiply(int , int);
void Log(const char*);
void Increment(int*);
void Increment2(int&);

class Player
{
public:
	int x, y; // �� public ����ǹ��������ˣ��������ⱻ����
	int speed;

	void Move(int xa, int ya) // method ����
	{
		x += xa * speed;
		y += ya * speed;
	}
};

class Loginfo
{
public:
	const int LogLevelError = 0;
	const int LogLevelWarning = 1;
	const int LogLevelInfo = 2;
private:
	int m_LogLevel = LogLevelInfo; // m_ ��ʾ˽�е� member ����
public:
	void SetLevel(int level)
	{
		m_LogLevel = level;
	}
	void Error(const char* message)
	{
		if (m_LogLevel >= LogLevelError)
			std::cout << "[ERROR]" << message << std::endl;
	}
	void Warn(const char* message)
	{
		if (m_LogLevel >= LogLevelWarning)
			std::cout << "[WARNING]" << message << std::endl;
	}
	void Info(const char* message)
	{
		if (m_LogLevel >= LogLevelInfo)
			std::cout << "[INFO]" << message << std::endl;
	}

};

int main()
{
	// Variable test
	Log("Variable test");
	std::cout << "Hello World!"  << std::endl;
	int variable = -46; // -2b  ---  +2b
	unsigned int variable2 = -11; // -4b  ---  +4b ������λҲ�洢�ַ�
	char character = 65;
	std::cout << Multiply(4, 8) << std::endl;
	std::cout << variable << std::endl;
	std::cout << variable2 << std::endl;
	std::cout << character << std::endl;
	std::cout << sizeof(variable) << std::endl;
	int x = 6;
	bool ComparisionResult = x == 5;

	// Condition test
	Log("Condition test");
	if (ComparisionResult)
	{
		std::cout << "x queals 5" << std::endl;
	}
	else
		std::cout << "x does not queal 5" << std::endl;

	// Loop test
	Log("Loop test");
	int i = 0;
	while (i < 2)
	{
		std::cout << "loop" << std::endl;
		i++;
	}

	// Flow test
	Log("Flow test");
	for (int i = 0; i <= 3; i++)
	{
		if (i == 1)
		{
			std::cout << " i == 1" << std::endl;
			continue; // Flow test
		}
		if (i == 2)
		{
			std::cout << " i == 2" << std::endl;
			break; // Flow test
		}
	}

	// Pointer test
	Log("Pointer test");
	int var = 8;
	int* ptr = &var;
	std::cout << ptr << std::endl;
	*ptr = 10;
	std::cout << var << std::endl;

	char* buffer = new char[8]; // charռ1�ֽ�,��8�ֽ�
	memset(buffer, 1, 8); // ȫ��0
	std::cout << sizeof(buffer) << std::endl; // pointer is juse an integer, 4 byte
	std::cout << sizeof(*buffer) << std::endl; // pointed to the beginning of the memory block
	// double pointer
	char** pptr = &buffer;
	delete[] buffer;

	// Reference test
	Log("Reference test"); // ����ֻ�Ǹ��﷨�ǣ�û��ʲô������������ָ�������˵�
	int a = 5;
	int& ref = a; // ��ʱ��&�Ͳ���ȡַ�ˣ�int&��һ��ģ���ʱ ref ���� a �ı�����alias���ˣ�һ���Ķ�����ע�⣬����һ��ȷ���㲻�ܸ������ö���
	ref = 2;
	std::cout << a << std::endl;
	Increment(&a);
	std::cout << a << std::endl;
	Increment2(a); // ref ������ a �ĵ�ַ�����Լ�ʹ����Ϊ����ֵ���ݵ�����ʱ����Ϊ���ô��ݣ���Ҳ���Ը����������ֵ����ʵ�Σ�
				   // ����ָ����ʵ��һ���ģ�����д������˳����������ຯ������һ��ʹ�����ã�������ָ��
	std::cout << a << std::endl;

	// Class test
	Log("Class test");
	Player player;
	player.x = 2;
	player.y = 1;
	player.Move(1, -1);

	Loginfo loginfo;
	loginfo.SetLevel(loginfo.LogLevelWarning);
	loginfo.Warn("Hello");
	loginfo.Error("Hello");
	loginfo.Info("Hello");


	std::cin.get();
}


#if 0




typedef struct Row
{
	int a;
	int b;
} Row;
/*!
* Task 1.
* *
Find out all the rows that sastify below conditions:
* *
((b >= 10 && b < 50) &&
* (a == 1000 || a == 2000 || a == 3000))
* *
Print them to the terminal, one row per line, for example:
* *
1000,20
* 1000,23
* 2000,16
* *
@param nrows The total number of rows.
* @param rows The rows, for example rows[0] is the first row.
*/
void task1(const Row* rows, int nrows)
{
	/*
	* TODO: implement this function.
	*/

}

 struct result //�Ž��
{
	int c;
	int d;
};



 result Find(const Row* rows, int nrows, int num) //���±�
{
	
	
	result res = { -1,-1 };
	if (rows[0].a == num && (rows[0].b >= 10 && rows[0].b < 50)) { res.c = 0; }

	for (int i = 1; i < nrows; i++)
	{
		if (rows[i].b < 10 && rows[i].b >= 50)
			continue;
		if (rows[i - 1].a != num && rows[i].a == num)
			res.c = i;
		else if (rows[i - 1].a == num && rows[i].a != num)
			res.d = i - 1;
	}
	if (res.d == -1)
		res.d = nrows - 1;

	return res;

}

 void print(const Row* rows, result res) //��ӡ
 {
	 for (int i = res.c; i <= res.d; i++)
		 std::cout << rows[i].a << "," << rows[i].b << std::endl;
 }

int main() {
	const Row* rows;
	; int nrows;

#if 0
	for (int i = 0; i < nrows; i++)
	{
		if ((rows[i].a == 1000 || rows[i].a == 2000 || rows[i].a == 3000) && (rows[i].b >= 10 && rows[i].b < 50))
		std::cout << rows[i].a << "," << rows[i].b << std::endl;
	}


	result res = Find(rows, nrows, 1000);
	print(rows, res);
	res = Find(rows, nrows, 2000);
	print(rows, res);
	res = Find(rows, nrows, 3000);
	print(rows, res);
#endif

#if 0
	int ind[nrows];
	for (int i = 0; i < nrows; i++)
	{
		int k = 0;
		int max = rows[k].b;
		for (int j = 0; j < nrows; j++)
		{
			if ((rows[j].b > max) && ( std::find(ind, ind + nrows, j) == ind + nrows))
			{
				k = j;
				max = rows[j].b;
				ind[i] = j;
			}

		}
		 
		std::cout << rows[k].a << "," << rows[k].b << std::endl;
		
	}
#endif


}

#endif

