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


// ������������¥�ݡ���Ҫ n ������ܵ���¥����ÿ��������� 1 �� 2 ��̨�ס�
// ���ж����ֲ�ͬ�ķ�����������¥���أ�
// ״̬���� d(n) = d(n-1) + d(n-2)
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

// ����һ���������� nums ���ҵ�һ���������͵����������飨���������ٰ���һ��Ԫ�أ������������͡�
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

// ����һ���������� nums ���ҵ�һ��������С�͵����������飨���������ٰ���һ��Ԫ�أ������������͡�
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

// ����һ��������������飬�ҵ���������������еĳ��ȡ�
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


// ��120�⣺����һ�������Σ��ҳ��Զ����µ���С·���͡�


// ÿһ��ֻ���ƶ�����һ�������ڵĽ���ϡ�
// ���磬���������Σ�
// [
//	 [2],
//	 [3, 4],
//	 [6, 5, 7],
//	 [4, 1, 8, 3]
// ]
// �Զ����µ���С·����Ϊ 11������2 + 3 + 5 + 1 = 11����

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


//��64�⣺����һ�������Ǹ������� m x n �������ҳ�һ�������Ͻǵ����½ǵ�·����ʹ��·���ϵ������ܺ�Ϊ��С��
//
//˵����ÿ��ֻ�����»��������ƶ�һ����
//ʾ�� :
//����:
//[
//	[1, 3, 1],
//	[1, 5, 1],
//	[4, 2, 1]
//]
//��� : 7
//	���� : ��Ϊ·�� 1��3��1��1��1 ���ܺ���С��

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


//����һ��רҵ��С͵���ƻ�͵���ؽֵķ��ݡ�ÿ�䷿�ڶ�����һ�����ֽ�Ӱ����͵�Ե�Ψһ��Լ���ؾ������ڵķ���װ
//���໥��ͨ�ķ���ϵͳ������������ڵķ�����ͬһ���ϱ�С͵���룬ϵͳ���Զ�������
//
//����һ������ÿ�����ݴ�Ž��ķǸ��������飬�������ڲ���������װ�õ�����£��ܹ�͵�Ե�����߽�
//
//ʾ�� 1:
//����: [1, 2, 3, 1]
//	��� : 4
//	���� : ͵�� 1 �ŷ���(��� = 1) ��Ȼ��͵�� 3 �ŷ���(��� = 3)��
//	͵�Ե�����߽�� = 1 + 3 = 4 ��

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

//��ͬ·����һ��������λ��һ�� m x n ��������Ͻǣ���ʼ������ͼ�б��Ϊ��Start����
//������ÿ��ֻ�����»��������ƶ�һ������������ͼ�ﵽ��������½ǣ�����ͼ�б��Ϊ��Finish����
//
//���磬��ͼ��һ��7 x 3 �������ж��ٿ��ܵ�·����
//
//˵����m �� n ��ֵ�������� 100��
//
//ʾ�� 1:
//����: m = 3, n = 2
//	��� : 3
//	���� :
//	�����Ͻǿ�ʼ���ܹ��� 3 ��·�����Ե������½ǡ�
//	1. ����->����->����
//	2. ����->����->����
//	3. ����->����->����


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

//��ͬ·����һ��������λ��һ�� m x n ��������Ͻǣ���ʼ������ͼ�б��Ϊ��Start����
//������ÿ��ֻ�����»��������ƶ�һ������������ͼ�ﵽ��������½ǣ�����ͼ�б��Ϊ��Finish����
//���ڿ������������ϰ����ô�����Ͻǵ����½ǽ����ж�������ͬ��·����
//
//�����е��ϰ���Ϳ�λ�÷ֱ��� 1 �� 0 ����ʾ��
//˵����m �� n ��ֵ�������� 100��
//ʾ�� 1:
//
//����:
//[
//	[0, 0, 0],
//	[0, 1, 0],
//	[0, 0, 0]
//]
//��� : 2
//	���� :
//	3x3 ��������м���һ���ϰ��
//	�����Ͻǵ����½�һ���� 2 ����ͬ��·����
//	1. ����->����->����->����
//	2. ����->����->����->����

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