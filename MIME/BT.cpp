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
/* 二叉树后续                                                                     */
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

	if (root->left == nullptr || root->left->value == -1)
	{
		root->right->left = root->left;
		return root->right;
	}

	if (root->right == nullptr || root->right->value == -1)
	{
		root->left->right = root->right;
		return root->left;
	}

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