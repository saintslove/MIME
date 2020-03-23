#pragma once
#include <vector>
#include <string>

class DP
{
public:
	DP();
	~DP();

	void climbStairs(int n);
	void maxSubArr(int* a, int size);
	void minSubArr(int* a, int size);
	void lengthOfLIS(int* a, int size);
	int minimumTotal(std::vector<std::vector<int>> a);
	int maxSumPath(std::vector<std::vector<int> > a);
	int minPathSum(std::vector<std::vector<int>> a);
	int rob(int* a, int size);
	int uniquePaths(int m, int n);
	int uniquePaths(std::vector<std::vector<int> > a);
	int uniquePathsWithObstacles(std::vector<std::vector<int> > a);
	void LCS(std::string str1, std::string str2);
	void LCSubString(std::string str1, std::string str2);
};

