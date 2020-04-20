#pragma once

#include <string>
using namespace std;

class huawei
{
public:
	huawei();
	~huawei();

	string reverse(string sentence);
	void cpuProcess();
	void removeLatest(const char* sentence);
	void sortStr();
	int getCommonStrLength(char * pFirstStr, char * pSecondStr);
	bool IsAllCharExist(char* pShortString, char* pLongString);
	void removdDump(int input);
	void findPrim(int input);
	int FirstNotRepeatingChar(string str);
};

