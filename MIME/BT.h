#pragma once
#include <deque>
#include <vector>

struct TreeNode
{
	int value;
	TreeNode* pre;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int val) {
		value = val;
		pre = nullptr;
		left = nullptr;
		right = nullptr;
	}
};

class BT
{
public:
	BT(int* tree, int size);
	~BT();

	void initTree(int* tree, int size);
	void printTreeFront(TreeNode* node);
	void printTreeMid(TreeNode* node);
	void printTreeLast(TreeNode* node);
	void BFS(TreeNode* node);
	void DFS(TreeNode* node);
	int TreeDeep(TreeNode* node);
	bool isBST(TreeNode* node, int min, int max);
	bool isBST(int* a, int size);
	bool isBlanceTree(TreeNode* node);
	bool isBlanceTree2(TreeNode* node, int *dep);
	bool isBlanceTree2(TreeNode* node);
	int countNode(TreeNode* node);
	TreeNode* deleteNode(TreeNode* root, int value);
	TreeNode* deleteMinNode(TreeNode* root);
	TreeNode* getRoot();
	void deleteTree(TreeNode* node);
	void deleteTree();
	void TreeDeepSum(TreeNode* node, int sum);
	void TreeDeepSum(TreeNode* node, int sum,int curSum, std::vector<int>& vec);
	void findPath(TreeNode* node, int sum);
	void BSTCommNode(TreeNode* node,int value1,int value2);
	bool getNodePath(TreeNode* node, int value,std::vector<int>& path);
	int getCommNode(TreeNode* node, int value1, int value2);
	void convertNode(TreeNode* node, TreeNode** lastNode);
private:
	TreeNode* root;
	std::deque<TreeNode*>* nodes;
};

