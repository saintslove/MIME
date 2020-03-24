#pragma once
class link
{
public:
	link();
	~link();

private:
	typedef struct Node
	{
		int value;
		Node* next;
	};

public:
	bool isLoop(Node* node);
	Node* findLoopEnter(Node* node);
	int findLoopNum(Node* node);
	Node* reverseList(Node* pHead);
	Node* deleteDupNode(Node* pHead);
	Node* findFirstComNode(Node* node,Node* node2);
};

