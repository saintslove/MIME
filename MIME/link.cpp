#include "link.h"
#include <stdio.h>


link::link()
{
}


link::~link()
{
}


/************************************************************************/
/*   检测链表是否成环                                                                   */
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
/*  查找链表环内元素个数                                                                    */
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
			// 说明两节点已经相遇，已经处于环内
			break;
		}
	}

	// 找到链表环元素数
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
/*   查找链表环的入口                                                                   */
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
/* 给定一个链表头节点，翻转该链表，并返回反转后链表头结点                                                                     */
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
/* 找到两个链表的第一个公共节点
/* 链表A：1—2—3—4—5
/* 链表B: 1—2—8—10—12—3—4—5
/* 第一个公共节点：3
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




// 
// // 删除有序链表中重复的节点
// windows::Node* windows::deleteDupNode(Node* pHead)
// {
// 	if (pHead == nullptr || pHead->next == nullptr)
// 		return pHead;
// 
// 	Node* slow = pHead;
// 	Node* fast = pHead->next;
// 
// 	//// 哨兵节点
// 	//Node* pSentry;
// 	//pSentry->value = -1;
// 	//pSentry->next = slow;
// 	Node* pPreNode = NULL;
// 	bool isDelete = false;
// 
// 	while ()
// 	{
// 		if (slow->value == fast->value) {
// 			fast++;
// 			isDelete = true;
// 		}
// 		else {
// 			if (isDelete) {
// 				pPreNode->next = fast;
// 			}
// 			else {
// 				pPreNode = slow;
// 			}
// 			isDelete = false;
// 			slow = fast;
// 			fast++;
// 		}
// 	}
// 
// }
