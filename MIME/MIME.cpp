// cPlus.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "sort.h"
#include "BT.h"
#include "windows.h"
#include <set>
#include "huawei.h"
#include <functional>
#include <set>
#include <algorithm>
#include "DP.h"

int main()
{
	//int num[] = { 3,78,4,91,3,61,4,64,0,4,567,56,23,2,2,43,79,2,68,34 };
	//int num[] = { 3,78,4,91,3,61,-1,-1,-1,-1,-1,-1,7 };
	//int num[] = { 15,10,20,-1,13,17,30,-1,-1,-1,-1,-1,-1,25,-1 };
	//int num[] = { 1,3,-1,-3,5,3,6,7 };
	//int num[] = { 3,10,4,8,12,6,1,1,0,4,2 };
	//int num[] = { 3,2,3,4,4,3,4 };
	int num[] = { 10,9,2,5,3,7,101,18 };
	int size = sizeof(num) / sizeof(int);
	Sort sort;
	//ѡ������
	//sort.select_sort(num, size);
	//��������
	//sort.insert_sort(num, size);
	//ϣ������
	//sort.shell_sort(num, size);
	//��������
	//sort.quick_sort(num, 0, size - 1);
	//�󶥶�����
	//sort.heap_max_sort(num, size);
	//С��������
	//sort.heap_min_sort(num, size);
	//�鲢����
	//sort.merge_sort(num, 0, size - 1);
	//��������
	//sort.count_sort(num, size);
	//��������
	//sort.radix_sort(num, size);
	/*for (int i = 0; i < size; i++) {
	std::cout << num[i] << "  ";
	}
	std::cout << std::endl;*/


	//BT bt(num, size);
	//bt.initTree(num, size);
	//bt.printTreeFront(bt.getRoot());
	//bt.printTreeMid(bt.getRoot());
	//bt.printTreeLast(bt.getRoot());
	//bt.BFS(bt.getRoot());
	//bt.DFS(bt.getRoot());
	//std::cout << bt.TreeDeep(bt.getRoot()) << std::endl;
	//std::cout << bt.isBST(bt.getRoot(),-99999999,99999999) << std::endl;
	//bt.BFS(bt.getRoot());
	//std::cout << std::endl;
	//bt.deleteNode(bt.getRoot(), 15);
	//bt.BFS(bt.getRoot());
	//bt.deleteTree();
	//bt.TreeDeepSum(bt.getRoot(),21);

	//windows ws;
	/*int b[20] = {0};
	ws.getMaxWindows(num, b, 3, size);
	for (int i = 0; i < 20; i++) {
	std::cout << b[i] << std::endl;
	}*/

	//int ret = ws.lengthOfLongestSubstring("pwwkew");
	// 	int ret = ws.findOnly(num, 3, size);
	// 	std::cout << ret << std::endl;
	/*ws.lastK(num, 5, size);*/

	// 	char a[] = "hello world";
	// 	char b[] = "hew";
	// 	ws.removeDup(a,b);

	// 	int m[101] = { 0 };
	// 	for (int i = 100; i <= 200; i++) {
	// 		m[i - 100] = i;
	// 	}
	// 	ws.findPrim(m, 101);

	//ws.getSum(3);
	//ws.findN(num, size);
	//ws.findAllCom(num, size);



	//huawei hw;
	//hw.reverse("I am a boy");

	//DP dp;
	//dp.climbStairs(6);
	//dp.maxSubArr(num, size);
	//dp.minSubArr(num, size);
	//dp.lengthOfLIS(num, size);

	system("pause");
	return 0;

}
