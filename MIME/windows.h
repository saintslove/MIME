#pragma once

#include <string>

class windows
{
public:
	typedef struct Node
	{
		int value;
		Node* next;
	};

public:
	windows();
	~windows();

	void getMaxWindows(int* a, int* b, int k, int size);
	int lengthOfLongestSubstring(std::string s);
	void lastK(int* a, int k, int size);
	void removeDup(char* a, char* b);
	void findAllCom(int* a, int size);
	void findSum(int* a,int size,int value);
	void findSumSub(int value);
};

