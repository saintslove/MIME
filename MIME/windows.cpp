#include "windows.h"
#include <map>
#include <set>
#include <iostream>
#include <functional>
#include <cmath>
#include <algorithm>
#include <vector>

windows::windows()
{
}


windows::~windows()
{
}

/************************************************************************/
/* 给定一个数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。
/* 你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。返回滑动窗口中的最大值。                                                                     */
/************************************************************************/
void windows::getMaxWindows(int* a, int* b, int k, int size)
{
	int max = 0;
	int index = 0;
	for (int i = 0; i < k; i++) {
		max = max > a[i] ? max : a[i];
	}
	b[index] = max;
	for (int j = k; j < size; j++) {
		max = max > a[j] ? max : a[j];
		b[++index] = max;
	}
}


/************************************************************************/
/* 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度
/*
/* 示例 1:
/* 输入: "abcabcbb"
/* 输出 : 3
/* 解释 : 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
/*
/* 示例 2 :
/* 输入 : "bbbbb"
/* 输出 : 1
/* 解释 : 因为无重复字符的最长子串是 "b"，所以其长度为 1。                                                                     */
/************************************************************************/
int windows::lengthOfLongestSubstring(std::string s)
{
	int result = 0;
	std::map<char, int> mapc;
	for (int left = 0, right = 0; right < s.size(); right++)
	{
		if (mapc.count(s[right]) != 0) {
			left = right > left ? right : left;
		}
		result = right - left + 1 > result ? right - left + 1 : result;
		mapc[s[right]] = right;
	}
	return result;
}


/************************************************************************/
/*  输入n个整数，找出最小的的k个数
/*  输入：4、5、1、6、2、7、3、8
/*  输出：1、2、3、4                                                                    */
/************************************************************************/
void windows::lastK(int* a, int k, int size)
{
	if (k < 1 || k > size) {
		return;
	}

	std::multiset<int, std::greater<int> > sets;

	for (int i = 0; i < size; i++) {
		if (sets.size() < k) {
			sets.insert(a[i]);
			continue;
		}

		std::set<int>::iterator it = sets.begin();
		if (*it > a[i]) {
			sets.erase(it);
			sets.insert(a[i]);
		}
	}

	for (auto a : sets) {
		std::cout << a << std::endl;
	}
}



/************************************************************************/
/*  两个字符串A、B, 从A中剔除存在于B中的字符。
/*  比如A = “hello world”, B = “her”，
/*  那么剔除之后A变为 “llo wold”                                                                   */
/************************************************************************/
void windows::removeDup(char* a, char* b)
{
	int hashMap[256] = { 0 };
	// 初始化hashMap
	while (*b != '\0')
	{
		hashMap[*b++ - 'a']++;
	}
	//printf("%d%d%d", hashMap['h' - 'a'], hashMap['e' - 'a'], hashMap['w' - 'a']);

	char* slow = a;
	char* fast = a;
	while (*fast != '\0') {
		// 说明不存在共存字符
		if (hashMap[*fast - 'a'] == 0) {
			*slow = *fast;
			slow++;
		}
		fast++;
	}
	*slow = '\0';

	std::cout << std::string(a) << std::endl;
}


/************************************************************************/
/*  对于输入数字序列，找出所有的组合，排序输出                                                                     */
/************************************************************************/
void windows::findAllCom(int* a, int size)
{
	std::set<int, std::greater<int> > sets;
	for (int i = 0; i < size; i++) {
		if (a[i] == 0)
			continue;

		for (int j = 0; j < size; j++) {
			if (j == i)
				continue;

			for (int k = 0; k < size; k++) {
				if (k == i || k == j)
					continue;

				sets.insert(a[i] * 100 + a[j] * 10 + a[k]);
			}
		}
	}

	typedef std::set<int, std::greater<int> >::iterator iter;
	iter it = sets.begin();
	while (it != sets.end()) {
		std::cout << *it << std::endl;
		it++;
	}
}


/************************************************************************/
/* 在一组递增序列中，查找是否两个元素和等于给定元素值
/* 输入 【1,2,4,7,11,15】 存在2+7=9
/* 采用滑窗处理
/************************************************************************/

bool increase(int i, int j)
{
	return i < j;
}

bool decrease(int i, int j) {
	return i > j;
}

struct MyStruct
{
	bool operator()(int i, int j) {
		return i > j;
	}
}MyStruct;

void windows::findSum(int* a, int size, int value)
{
	//std::sort(a, a + size);
	//std::vector<int> vec(a,a + size);
	//std::sort(vec.begin(), vec.end());
	//std::sort(vec.begin(), vec.end(), decrease);
	//std::sort(vec.begin(), vec.end(), MyStruct);

	int pHead = 0;
	int pTail = size - 1;
	int sum = 0;
	while (pHead < pTail)
	{
		sum = a[pHead] + a[pTail];
		if (sum == value) {
			//std::cout << a[pHead] << "   " << a[pTail] << std::endl;
			pHead++;
			continue;
		}
		if (sum > value) {
			pTail--;
		}
		else {
			pHead++;
		}
	}
}

/************************************************************************/
/* 给定一个正数s，打印所有元素和等于s的连续正数序列
/* 输入 15 存在 1+2+3+4+5 = 4+5+6 = 7+8 = 15
/* 采用滑窗处理                                                     
/************************************************************************/
void print(int head, int tail) {
	while (head <= tail) {
		std::cout << head++ << "  ";
	}
	std::cout << std::endl;
}

void windows::findSumSub(int value)
{
	int pHead = 1;
	int pTail = 2;
	int sum = pHead + pTail;
	int mid = value / 2;
	while (pHead <= mid)
	{
		if (sum == value)
			print(pHead, pTail);
		
		while (sum > value && pHead <= mid)
		{
			sum -= pHead;
			pHead++;

			if (sum == value)
				print(pHead, pTail);
		}

		pTail++;
		sum += pTail;
	}
}