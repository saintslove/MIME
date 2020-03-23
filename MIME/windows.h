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
	bool isLoop(Node* node);
	Node* findLoopEnter(Node* node);
	int findLoopNum(Node* node);
	/*Node* deleteDupNode(Node* pHead);*/
	int findOnly(int* a, int freq, int size);
	char findFirst(const char* a);

	void removeDup(char* a, char* b);
	void findPrim(int* a, int size);
	void findNumOfOne(int a);
	int getSum(int a);
	void findN(int* a, int size);
	Node* reverseList(Node* pHead);
	void findAllCom(int* a, int size);
};

