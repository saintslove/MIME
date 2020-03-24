#include "link.h"
#include <stdio.h>


link::link()
{
}


link::~link()
{
}


/************************************************************************/
/*   ��������Ƿ�ɻ�                                                                   */
/************************************************************************/
bool link::isLoop(Node* node)
{
	if (node == nullptr)
		return false;

	Node* slow = node;
	Node* fast = node->next;
	while (fast && fast->next && slow)
	{
		if (fast == slow)
			return true;
		slow = slow->next;
		fast = fast->next->next;
	}
	return false;
}


/************************************************************************/
/*  ����������Ԫ�ظ���                                                                    */
/************************************************************************/
int link::findLoopNum(Node* node)
{
	if (node == nullptr)
		return -1;

	Node* slow = node;
	Node* fast = node->next;

	while (slow && fast && fast->next) {
		if (slow != fast) {
			slow = slow->next;
			fast = fast->next->next;
		}
		else
		{
			// ˵�����ڵ��Ѿ��������Ѿ����ڻ���
			break;
		}
	}

	// �ҵ�����Ԫ����
	int nodeNum = -1;
	if (fast && slow && fast == slow) {
		nodeNum = 1;
		while (slow->next != fast) {
			slow = slow->next;
			nodeNum++;
		}
	}
	return nodeNum;
}



/************************************************************************/
/*   �������������                                                                   */
/************************************************************************/
link::Node* link::findLoopEnter(Node* node)
{
	int num = findLoopNum(node);
	Node* node1 = node;
	Node* node2 = node;
	while (num--) {
		node2 = node2->next;
	}
	while (node1 != node2) {
		node1 = node1->next;
		node2 = node2->next;
	}
	return node1;

}

/************************************************************************/
/* ����һ������ͷ�ڵ㣬��ת�����������ط�ת������ͷ���                                                                     */
/************************************************************************/
link::Node* link::reverseList(Node* pHead)
{
	Node* pReverseHead = NULL;
	Node* pPre = NULL;
	Node* pNext = NULL;
	while (pHead)
	{
		pNext = pHead->next;
		if (pNext == NULL)
			pReverseHead = pHead;

		pHead->next = pPre;
		pPre = pHead;
		pHead = pNext;
	}
	return pReverseHead;
}

/************************************************************************/
/* �ҵ���������ĵ�һ�������ڵ�
/* ����A��1��2��3��4��5
/* ����B: 1��2��8��10��12��3��4��5
/* ��һ�������ڵ㣺3
/************************************************************************/
link::Node* link::findFirstComNode(Node* node, Node* node2)
{
	Node* n1 = reverseList(node);
	Node* n2 = reverseList(node2);
	Node* n3 = NULL;
	while (n1->value == n2->value)
	{
		n3 = n1;
		n1 = n1->next;
		n2 = n2->next;
	}
	return n3;
}




 
/************************************************************************/
/* ɾ�����������е��ظ�Ԫ��

/*	 Example 1:
/*	 Input: 1->1->2
/*	 Output: 1->2

/*	 Example 2:
/*	 Input: 1->1->1->2->3->3
/*	 Output: 1->2->3                                                                     */
/************************************************************************/
 link::Node* link::deleteDupNode(Node* pHead)
 {
	 Node* p = pHead;

	 if (p == nullptr)
		 return pHead;
	
	 while (p && p->next)
	 {
		 if (p->value == p->next->value) {
			 p->next = p->next->next;
		 }
		 else {
			 p = p->next;
		 }
	 }
	 return pHead;
 }
