#pragma once
#include <vector>
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
	int minPathSum(std::vector<std::vector<int>> a);
	int rob(int* a, int size);
	int uniquePaths(int m, int n);
	int uniquePaths(std::vector<std::vector<int> > a);
	int uniquePathsWithObstacles(std::vector<std::vector<int> > a);
};

