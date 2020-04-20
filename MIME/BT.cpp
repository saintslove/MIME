#include "BT.h"
#include <iostream>
#include <stack>
#include <utility>
#include <algorithm>
#include <vector>

BT::BT(int* tree, int size)
{
	initTree(tree, size);
}


BT::~BT()
{
	deleteTree();
}

/************************************************************************/
/* 初始化二叉树                                                                     */
/************************************************************************/
void BT::initTree(int* tree, int size)
{
	nodes = new std::deque<TreeNode*>();
	for (int i = 0; i < size; i++) {
		nodes->push_back(new TreeNode(tree[i]));
	}

	for (int i = 0; i <= size / 2 - 1; i++) {
		TreeNode* node = (*nodes)[i];
		if (2 * i + 1 < size) {
			node->left = (*nodes)[2 * i + 1];
			node->left->pre = node;
		}
		if (2 * i + 2 < size) {
			node->right = (*nodes)[2 * i + 2];
			node->right->pre = node;
		}

	}

	root = nodes->front();
}

/************************************************************************/
/* 二叉树前序                                                                     */
/************************************************************************/
void BT::printTreeFront(TreeNode* node)
{
	if (node != nullptr) {
		std::cout << node->value << std::endl;
	}
	if (node->left) {
		printTreeFront(node->left);
	}
	if (node->right) {
		printTreeFront(node->right);
	}

}

/************************************************************************/
/* 二叉树中序                                                                     */
/************************************************************************/
void BT::printTreeMid(TreeNode* node)
{
	if (node == nullptr)
		return;

	if (node->left)
		printTreeMid(node->left);
	std::cout << node->value << std::endl;
	if (node->right)
		printTreeMid(node->right);
}

/************************************************************************/
/* 二叉树后序                                                                     */
/************************************************************************/
void BT::printTreeLast(TreeNode* node)
{
	if (node == nullptr)
		return;
	if (node->left)
		printTreeLast(node->left);
	if (node->right)
		printTreeLast(node->right);
	std::cout << node->value << std::endl;
}

/************************************************************************/
/* 广度优先遍历                                                                     */
/************************************************************************/
void BT::BFS(TreeNode* node)
{
	if (node == nullptr)
		return;
	std::deque<TreeNode*> que = std::deque<TreeNode*>();
	que.push_back(node);
	while (que.size() > 0)
	{
		TreeNode* node = que.front();
		que.pop_front();
		std::cout << node->value << std::endl;
		if (node->left)
			que.push_back(node->left);
		if (node->right)
			que.push_back(node->right);
	}

}

/************************************************************************/
/* 深度优先遍历                                                                     */
/************************************************************************/
void BT::DFS(TreeNode* node)
{
	std::stack<TreeNode*> que = std::stack<TreeNode*>();
	if (node == nullptr)
		return;
	que.push(node);
	while (que.size() > 0)
	{
		TreeNode* node = que.top();
		que.pop();
		std::cout << node->value << std::endl;
		if (node->right)
			que.push(node->right);
		if (node->left)
			que.push(node->left);
	}
}

/************************************************************************/
/* 利用【DFS】获取树深度                                                                     */
/************************************************************************/
int BT::TreeDeep(TreeNode* node)
{
	int dep = 0;
	typedef std::pair<TreeNode*, int> NODE;
	std::stack<NODE> nodes = std::stack<NODE>();
	if (node == nullptr)
		return dep;
	nodes.push(std::make_pair<>(node, 1));
	while (nodes.size() > 0)
	{
		NODE node = nodes.top();
		nodes.pop();
		TreeNode* nodeSub = node.first;
		int temp = node.second;
		dep = dep < temp ? temp : dep;
		if (nodeSub->right && nodeSub->right->value != -1)
			nodes.push(std::make_pair<>(nodeSub->right, temp + 1));
		if (nodeSub->left && nodeSub->left->value != -1)
			nodes.push(std::make_pair<>(nodeSub->left, temp + 1));
	}
	return dep;
}

/************************************************************************/
/*   利用DFS获取每条路径和                                                                   */
/************************************************************************/
void BT::TreeDeepSum(TreeNode* node, int sum)
{
	typedef std::pair<TreeNode*, int> NODE;
	std::stack<NODE> nodes = std::stack<NODE>();
	if (node == nullptr)
		return;
	nodes.push(std::make_pair(node, node->value));

	while (!nodes.empty()) {
		NODE node = nodes.top();
		nodes.pop();

		TreeNode* nodeSub = node.first;
		int temp = node.second;
		/*vecs.push_back(nodeSub->value);*/
		//std::cout << nodeSub->value << std::endl;

		if (nodeSub->left == nullptr && nodeSub->right == nullptr) {
			if (temp == sum) {
				while (nodeSub)
				{
					std::cout << nodeSub->value << std::endl;
					nodeSub = nodeSub->pre;
				}
				break;
			}
		}
		else {
			if (nodeSub->right != nullptr)
				// 有一种改进措施，若元素均为正数，可以在判断路径和已经大于sum的情况下，提前退出
				nodes.push(std::make_pair(nodeSub->right, nodeSub->right->value + temp));

			if (nodeSub->left != nullptr)
				nodes.push(std::make_pair(nodeSub->left, nodeSub->left->value + temp));
		}
	}

}


/************************************************************************/
/*  迭代获取符合需求的路径和                                                                  */
/************************************************************************/
void BT::findPath(TreeNode* node, int sum)
{
	if (node == nullptr)
		return;
	int curSum = 0;
	std::vector<int> path;
	TreeDeepSum(node,sum,curSum,path);
}

void BT::TreeDeepSum(TreeNode* node, int sum, int curSum, std::vector<int>& vec)
{
	if (node == nullptr)
		return;

	curSum += node->value;
	vec.push_back(node->value);
	if (node->left == nullptr && node->right == nullptr && curSum == sum) {
		for (auto c : vec) {
			std::cout << c << "  ";
		}
		std::cout << std::endl;
	}

	if (node->left)
		TreeDeepSum(node->left, sum, curSum, vec);
	if(node->right)
		TreeDeepSum(node->right, sum, curSum, vec);

	vec.pop_back();
}


/************************************************************************/
/* 判断是否是二叉搜索树                                                                     */
/************************************************************************/
bool BT::isBST(TreeNode* node, int min, int max)
{
	if (node == nullptr || node->value == -1)
		return true;
	if (node->value < min || node->value > max)
		return false;
	return isBST(node->left, min, node->value) && isBST(node->right, node->value, max);
}

/************************************************************************/
/* 输入一数组，判断该数组是否是二叉搜索树的后序遍历  
/* 变形：输入一数组，判断该数组是否是二叉搜索树的前序遍历 
/************************************************************************/
bool BT::isBST(int* a, int size)
{
	if (a == NULL || size <= 0)
		return false;
	int root = a[size - 1];
	int i = 0;
	// 寻找左子树区间
	while (i < size && a[i] < root) {
		i++;
	}

	int j = i;
	// 寻找右子树区间
	while (j < size && a[j] > root) {
		j++;
	}
	if (j != size - 1) {
		return false;
	}

	bool left = isBST(a, i);
	bool right = isBST(a + i, size - i + 1);
	return left && right;
}

/************************************************************************/
/*  给定一棵BST树，将其转换为双向链表
/*  例：		5
			3		10       ----》   1<->3<->4<->5<->10
        1      4
/************************************************************************/
void BT::convertNode(TreeNode* node, TreeNode** lastNode)
{
	if (node == NULL)
		return;

	TreeNode* currNode = node;
	if (currNode->left)
		convertNode(currNode->left, lastNode);

	currNode->left = *lastNode;
	if (*lastNode)
		(*lastNode)->right = currNode;

	// 移动尾部节点
	*lastNode = currNode;

	if (currNode->right)
		convertNode(currNode->right, lastNode);
}



/************************************************************************/
/* 获取树跟节点                                                                     */
/************************************************************************/
TreeNode* BT::getRoot()
{
	return root;
}

/************************************************************************/
/* 删除树                                                                       */
/************************************************************************/
void BT::deleteTree(TreeNode* root)
{
	if (root == nullptr)
		return;
	if (root->left)
		deleteTree(root->left);
	if (root->right)
		deleteTree(root->right);
	delete root;
}

/************************************************************************/
/* 删除树                                                                     */
/************************************************************************/
void BT::deleteTree()
{
	typedef std::deque<TreeNode*>::iterator iterator;
	iterator node = nodes->begin();
	while (node != nodes->end())
	{
		delete *node;
		node++;
	}
	delete nodes;
}

/************************************************************************/
/* 删除树节点                                                                     */
/************************************************************************/
TreeNode* BT::deleteNode(TreeNode* root, int value)
{
	if (root == nullptr || root->value == -1)
		return nullptr;
	// 最小值位于右子树
	if (root->value < value) {
		root->right = deleteNode(root->right, value);
		return root;
	}
	// 最小值位于左子树
	if (root->value > value) {
		root->left = deleteNode(root->left, value);
		return root;
	}

	// 命中节点左孩子为空，返回右孩子
	if (root->left == nullptr || root->left->value == -1)
	{
		root->right->left = root->left;
		return root->right;
	}
	// 命中节点右孩子为空，返回左孩子
	if (root->right == nullptr || root->right->value == -1)
	{
		root->left->right = root->right;
		return root->left;
	}

	// 命中节点左右孩子均有效，根据BST性质，有两种方案
	// 1）找右子树中最小节点，替换命中节点
	// 2) 找左子树中最大节点，替换命中节点
	TreeNode* node = root->right;
	while (node->left != nullptr && node->left->value != -1)
	{
		node = node->left;
	}
	root->value = node->value;
	root->right = deleteMinNode(root->right);
	return root;
}

/************************************************************************/
/* 删除最小节点                                                                     */
/************************************************************************/
TreeNode* BT::deleteMinNode(TreeNode* root)
{
	if (root->left == nullptr || root->left->value == -1) {
		TreeNode* node = root->right;
		root->right = nullptr;
		return node;
	}
	root->left = deleteMinNode(root->left);
	return root;
}


/************************************************************************/
/* 是否是AVL树                                                                     */
/************************************************************************/
bool BT::isBlanceTree(TreeNode* node)
{
	if (node == nullptr)
		return true;
	if (std::abs(TreeDeep(node->left) - TreeDeep(node->right)) > 1)
		return false;
	if (!isBlanceTree(node->left))
		return false;
	return isBlanceTree(node->right);
}

/************************************************************************/
/* 逆向判断                                                                     */
/************************************************************************/

bool BT::isBlanceTree2(TreeNode* node, int *dep)
{
	if (node == nullptr) {
		*dep = 0;
		return true;
	}

	int left = 0;
	int right = 0;
	if (isBlanceTree2(node->left, &left) && isBlanceTree2(node->right, &right)) {
		*dep = left > right ? left + 1 : right + 1;
		return true;
	}
	return false;
}

bool BT::isBlanceTree2(TreeNode* node)
{
	int dep = 0;
	return isBlanceTree2(node, &dep);
}

/************************************************************************/
/*  计算完全二叉树节点数                                                                    */
/************************************************************************/
int BT::countNode(TreeNode* node)
{
	if (node == nullptr) {
		return 0;
	}
	int depLeft = TreeDeep(node->left);
	int depRight = TreeDeep(node->right);
	if (depLeft == depRight) {
		return countNode(node->right) + 1 << depLeft;
	}
	else
	{
		return countNode(node->left) + 1 << depRight;
	}
}

/************************************************************************/
/*  对于一棵二叉搜索树，输入树中的两个节点，找出其最低父节点
/*  例：
/*			10
/*		  5    20
/*		1   6
/*
/*	对于节点6、20，其最低父节点为10
/************************************************************************/
void BT::BSTCommNode(TreeNode* node, int value1, int value2)
{
	TreeNode* currNode = node;
	
	// 当前节点小于最小节点，说明两个节点位于该节点右子树
	while (currNode->value < value1)
	{
		currNode = currNode->right;
	}
	// 当前节点大于最大节点，说明两个节点位于该节点左子树
	while (currNode->value > value2)
	{
		currNode = currNode->left;
	}
	// 当前节点位于两节点之间
	std::cout << currNode->value << std::endl;
}

/************************************************************************/
/* 一颗普通二叉树，获取达到该节点的路径    
/* 采用深度优先遍历
/************************************************************************/
bool BT::getNodePath(TreeNode* node, int value, std::vector<int>& path)
{
	if (node == nullptr)
		return false;
	
	bool find = false;

	// 找到了目标节点
	if (node->value == value)
		return true;
	
	// 未找到节点，将该节点放入堆栈
	path.push_back(node->value);
	//for (auto c : path)
	//	std::cout << c << "    ";
	//std::cout << std::endl;

	if (!find && node->left) {
		// 左子树寻找目标节点
		find = getNodePath(node->left, value, path);
	}
		
	if (!find && node->right) {
		// 右子树寻找目标节点
		find = getNodePath(node->right, value, path);
	}
		

	if (!find) {
		// 左右子树均未找到
		// 情况1：非叶子结点，且左右子树均未找到，说明该节点不在目标路径上
		// 情况2：叶子结点，且非目标节点，说明该节点不在目标路径上
		path.pop_back();
	}
	//std::cout << find << std::endl;
	//for (auto c : path)
	//	std::cout << c << "    ";
	//std::cout << std::endl;
	return find;
}

/************************************************************************/
/* 一棵普通二叉树，给定两个子节点，找出其最低公共父节点   
/*  例：
/*			10
/*		  5    20
/*		1   6
/*
/*	对于节点6、20，其最低父节点为10
/************************************************************************/
int BT::getCommNode(TreeNode* node, int value1, int value2)
{
	std::vector<int> path1, path2;
	bool find1 = getNodePath(node, value1, path1);
	bool find2 = getNodePath(node, value2, path2);
	int ret = 1 << 32 - 1;
	if (find2 && find1) {
		int index1 = 0;
		int index2 = 0;
		while (index1 < path1.size() && index2 < path2.size() && path1[index1] == path2[index2]) {
			index1++;
			index2++;
		}
		ret = path1[--index1];
	}
	return ret;
}