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
/* ��ʼ��������                                                                     */
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
/* ������ǰ��                                                                     */
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
/* ����������                                                                     */
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
/* ����������                                                                     */
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
/* ������ȱ���                                                                     */
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
/* ������ȱ���                                                                     */
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
/* ���á�DFS����ȡ�����                                                                     */
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
/*   ����DFS��ȡÿ��·����                                                                   */
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
				// ��һ�ָĽ���ʩ����Ԫ�ؾ�Ϊ�������������ж�·�����Ѿ�����sum������£���ǰ�˳�
				nodes.push(std::make_pair(nodeSub->right, nodeSub->right->value + temp));

			if (nodeSub->left != nullptr)
				nodes.push(std::make_pair(nodeSub->left, nodeSub->left->value + temp));
		}
	}

}


/************************************************************************/
/*  ������ȡ���������·����                                                                  */
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
/* �ж��Ƿ��Ƕ���������                                                                     */
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
/* ����һ���飬�жϸ������Ƿ��Ƕ����������ĺ������  
/* ���Σ�����һ���飬�жϸ������Ƿ��Ƕ�����������ǰ����� 
/************************************************************************/
bool BT::isBST(int* a, int size)
{
	if (a == NULL || size <= 0)
		return false;
	int root = a[size - 1];
	int i = 0;
	// Ѱ������������
	while (i < size && a[i] < root) {
		i++;
	}

	int j = i;
	// Ѱ������������
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
/*  ����һ��BST��������ת��Ϊ˫������
/*  ����		5
			3		10       ----��   1<->3<->4<->5<->10
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

	// �ƶ�β���ڵ�
	*lastNode = currNode;

	if (currNode->right)
		convertNode(currNode->right, lastNode);
}



/************************************************************************/
/* ��ȡ�����ڵ�                                                                     */
/************************************************************************/
TreeNode* BT::getRoot()
{
	return root;
}

/************************************************************************/
/* ɾ����                                                                       */
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
/* ɾ����                                                                     */
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
/* ɾ�����ڵ�                                                                     */
/************************************************************************/
TreeNode* BT::deleteNode(TreeNode* root, int value)
{
	if (root == nullptr || root->value == -1)
		return nullptr;
	// ��Сֵλ��������
	if (root->value < value) {
		root->right = deleteNode(root->right, value);
		return root;
	}
	// ��Сֵλ��������
	if (root->value > value) {
		root->left = deleteNode(root->left, value);
		return root;
	}

	// ���нڵ�����Ϊ�գ������Һ���
	if (root->left == nullptr || root->left->value == -1)
	{
		root->right->left = root->left;
		return root->right;
	}
	// ���нڵ��Һ���Ϊ�գ���������
	if (root->right == nullptr || root->right->value == -1)
	{
		root->left->right = root->right;
		return root->left;
	}

	// ���нڵ����Һ��Ӿ���Ч������BST���ʣ������ַ���
	// 1��������������С�ڵ㣬�滻���нڵ�
	// 2) �������������ڵ㣬�滻���нڵ�
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
/* ɾ����С�ڵ�                                                                     */
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
/* �Ƿ���AVL��                                                                     */
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
/* �����ж�                                                                     */
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
/*  ������ȫ�������ڵ���                                                                    */
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
/*  ����һ�ö������������������е������ڵ㣬�ҳ�����͸��ڵ�
/*  ����
/*			10
/*		  5    20
/*		1   6
/*
/*	���ڽڵ�6��20������͸��ڵ�Ϊ10
/************************************************************************/
void BT::BSTCommNode(TreeNode* node, int value1, int value2)
{
	TreeNode* currNode = node;
	
	// ��ǰ�ڵ�С����С�ڵ㣬˵�������ڵ�λ�ڸýڵ�������
	while (currNode->value < value1)
	{
		currNode = currNode->right;
	}
	// ��ǰ�ڵ�������ڵ㣬˵�������ڵ�λ�ڸýڵ�������
	while (currNode->value > value2)
	{
		currNode = currNode->left;
	}
	// ��ǰ�ڵ�λ�����ڵ�֮��
	std::cout << currNode->value << std::endl;
}

/************************************************************************/
/* һ����ͨ����������ȡ�ﵽ�ýڵ��·��    
/* ����������ȱ���
/************************************************************************/
bool BT::getNodePath(TreeNode* node, int value, std::vector<int>& path)
{
	if (node == nullptr)
		return false;
	
	bool find = false;

	// �ҵ���Ŀ��ڵ�
	if (node->value == value)
		return true;
	
	// δ�ҵ��ڵ㣬���ýڵ�����ջ
	path.push_back(node->value);
	//for (auto c : path)
	//	std::cout << c << "    ";
	//std::cout << std::endl;

	if (!find && node->left) {
		// ������Ѱ��Ŀ��ڵ�
		find = getNodePath(node->left, value, path);
	}
		
	if (!find && node->right) {
		// ������Ѱ��Ŀ��ڵ�
		find = getNodePath(node->right, value, path);
	}
		

	if (!find) {
		// ����������δ�ҵ�
		// ���1����Ҷ�ӽ�㣬������������δ�ҵ���˵���ýڵ㲻��Ŀ��·����
		// ���2��Ҷ�ӽ�㣬�ҷ�Ŀ��ڵ㣬˵���ýڵ㲻��Ŀ��·����
		path.pop_back();
	}
	//std::cout << find << std::endl;
	//for (auto c : path)
	//	std::cout << c << "    ";
	//std::cout << std::endl;
	return find;
}

/************************************************************************/
/* һ����ͨ�����������������ӽڵ㣬�ҳ�����͹������ڵ�   
/*  ����
/*			10
/*		  5    20
/*		1   6
/*
/*	���ڽڵ�6��20������͸��ڵ�Ϊ10
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