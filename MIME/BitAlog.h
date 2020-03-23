#pragma once
class BitAlog
{
public:
	BitAlog();
	~BitAlog();

	void findN(int* a, int size);
	int findOnly(int* a, int freq, int size);
	char findFirst(const char* a);
	void findNumOfOne(int a);
	int getSum(int a);
	void findPrim(int* a, int size);
};

