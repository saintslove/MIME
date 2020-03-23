#include "DP.h"
#include <vector>
#include <iostream>
#include <algorithm>

DP::DP()
{
}


DP::~DP()
{
}


// 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。每次你可以爬 1 或 2 个台阶。
// 你有多少种不同的方法可以爬到楼顶呢？
// 状态方程 d(n) = d(n-1) + d(n-2)
void DP::climbStairs(int n)
{
	std::vector<int> vec(n + 1, 0);
	vec[1] = 1;
	vec[2] = 2;
	for (int i = 3; i <= n; i++) {
		vec[i] = vec[i - 1] + vec[i - 2];
	}
	std::cout << vec[n] << std::endl;
}

// 给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
void DP::maxSubArr(int* a, int size)
{
	int max = 0;
	for (int i = 1; i < size; i++) {
		//printf("a[%d] = %d  a[%d] = %d\n", i - 1, a[i-1],i,a[i]);
		a[i] = std::max(a[i] + a[i - 1], a[i]);
		//printf("a[%d] = %d  a[%d] = %d\n", i - 1, a[i-1],i,a[i]);
		max = std::max(a[i], max);
		//printf("a[%d] = %d  max = %d\n", i, a[i],max);
	}
	std::cout << max << std::endl;
}

// 给定一个整数数组 nums ，找到一个具有最小和的连续子数组（子数组最少包含一个元素），返回其最大和。
void DP::minSubArr(int* a, int size)
{
	int min = 0;
	int index = 0;
	for (int i = 1; i < size; i++) {
		a[i] = std::min(a[i], a[i] + a[i - 1]);
		min = std::min(min, a[i]);

	}
	std::cout << min << std::endl;
}

// 给定一个无序的整数数组，找到其中最长上升子序列的长度。
void DP::lengthOfLIS(int* a, int size)
{
	std::vector<int> vec(size, 1);
	int max = 1;
	for (int i = 1; i < size; i++) {
		for (int j = 0; j < i; j++) {
			if (a[j] <= a[i]) {
				vec[i] = std::max(vec[i], vec[j] + 1);
			}
		}
		max = std::max(max, vec[i]);
	}
	std::cout << max << std::endl;
}


// 第120题：给定一个三角形，找出自顶向下的最小路径和。


// 每一步只能移动到下一行中相邻的结点上。
// 例如，给定三角形：
// [
//	 [2],
//	 [3, 4],
//	 [6, 5, 7],
//	 [4, 1, 8, 3]
// ]
// 自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。

int DP::minimumTotal(std::vector<std::vector<int>> a)
{
	if (a.size() == 0)
		return 0;
	for (int i = 1; i < a.size(); i++) {
		for (int j = 0; j < a[i].size(); j++) {
			if (j == 0)
				a[i][j] = a[i - 1][j] + a[i][j];
			else if (j == a[i].size() - 1)
				a[i][j] = a[i][j - 1] + a[i][j];
			else
				a[i][j] = std::max(a[i - 1][j - 1], a[i - 1][j]) + a[i][j];
		}
	}
	int max = 0;
	for (int i = 0; i < a[a.size() - 1].size(); i++) {
		max = std::max(max, a[a.size() - 1][i]);
	}
	return max;
}


//第64题：给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
//
//说明：每次只能向下或者向右移动一步。
//示例 :
//输入:
//[
//	[1, 3, 1],
//	[1, 5, 1],
//	[4, 2, 1]
//]
//输出 : 7
//	解释 : 因为路径 1→3→1→1→1 的总和最小。

int DP::minPathSum(std::vector<std::vector<int>> a)
{
	if (a.size() == 0)
		return 0;
	int v = a.size();
	int colum = a[0].size();

	for (int i = 0; i < v; i++) {
		for (int j = 0; j < colum; j++) {
			if (i == 0 && j != 0) {
				a[i][j] = a[i][j - 1] + a[i][j];
			}
			else if (j == 0 && i != 0) {
				a[i][j] = a[i - 1][j] + a[i][j];
			}
			else
			{
				a[i][j] = std::min(a[i - 1][j], a[i][j - 1]) + a[i][j];
			}
		}
	}
	return a[v - 1][colum - 1];
}


//你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装
//有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
//
//给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够偷窃到的最高金额。
//
//示例 1:
//输入: [1, 2, 3, 1]
//	输出 : 4
//	解释 : 偷窃 1 号房屋(金额 = 1) ，然后偷窃 3 号房屋(金额 = 3)。
//	偷窃到的最高金额 = 1 + 3 = 4 。

int DP::rob(int* a, int size)
{
	if (size == 0)
		return 0;
	if (size == 1)
		return a[0];
	if (size == 2)
		return std::max(a[0], a[1]);

	a[0] = a[0];
	a[1] = std::max(a[1], a[0]);
	for (int i = 2; i < size; i++) {
		a[i] = std::max(a[i] + a[i - 2], a[i - 1]);
	}
	return a[size - 1];
}

//不同路径：一个机器人位于一个 m x n 网格的左上角，起始点在下图中标记为“Start”。
//机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角，在下图中标记为“Finish”。
//
//例如，上图是一个7 x 3 的网格。有多少可能的路径？
//
//说明：m 和 n 的值均不超过 100。
//
//示例 1:
//输入: m = 3, n = 2
//	输出 : 3
//	解释 :
//	从左上角开始，总共有 3 条路径可以到达右下角。
//	1. 向右->向右->向下
//	2. 向右->向下->向右
//	3. 向下->向右->向右


int DP::uniquePaths(std::vector<std::vector<int> > a)
{
	if (a.size() == 0)
		return 0;
	if (a.size() == 1)
		return 1;
	if (a[0].size() == 1)
		return 1;
	int v = a.size();
	int colum = a[0].size();
	for (int i = 0; i < colum; i++)
		a[0][i] = 1;
	for (int i = 0; i < v; i++)
		a[i][0] = 1;
	for (int i = 1; i < v; i++) {
		for (int j = 1; j < colum; j++) {
			a[i][j] = a[i][j - 1] + a[i - 1][j];
		}
	}
	return a[v][colum];
}



int DP::uniquePaths(int m, int n)
{
	std::vector<int> vec(n, 1);
	for (int i = 1; i < m; i++) {
		for (int j = 1; j < n; j++) {
			vec[j] += vec[j - 1];
		}
	}
	return vec[n - 1];
}

//不同路径：一个机器人位于一个 m x n 网格的左上角，起始点在下图中标记为“Start”。
//机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角，在下图中标记为“Finish”。
//现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？
//
//网格中的障碍物和空位置分别用 1 和 0 来表示。
//说明：m 和 n 的值均不超过 100。
//示例 1:
//
//输入:
//[
//	[0, 0, 0],
//	[0, 1, 0],
//	[0, 0, 0]
//]
//输出 : 2
//	解释 :
//	3x3 网格的正中间有一个障碍物。
//	从左上角到右下角一共有 2 条不同的路径：
//	1. 向右->向右->向下->向下
//	2. 向下->向下->向右->向右

int DP::uniquePathsWithObstacles(std::vector<std::vector<int> > a)
{
	if (a.size() == 0)
		return 0;
	int v = a.size();
	int colum = a[0].size();

	if (a[0][0] == 1)
		a[0][0] = 0;
	for (int i = 1; i < colum; i++) {
		a[0][i] = a[0][i] == 1 ? 0 : a[0][i - 1];
	}
	for (int i = 1; i < v; i++) {
		a[i][0] = a[i][0] == 1 ? 0 : a[i - 1][0];
	}

	for (int i = 1; i < v; i++) {
		for (int j = 1; j < colum; j++) {
			a[i][j] = a[i][j] == 1 ? 0 : a[i][j - 1] + a[i - 1][j];
		}
	}
	return a[v - 1][colum - 1];
}