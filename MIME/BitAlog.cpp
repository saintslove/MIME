#include "BitAlog.h"
#include <iostream>
#include <string>

BitAlog::BitAlog()
{
}


BitAlog::~BitAlog()
{
}

/************************************************************************/
/*  对于给定序列，找出缺失的元素
/* 【3,0,1】 缺失【2】                                                                    */
/************************************************************************/
void BitAlog::findN(int* a, int size)
{
	int result = 0;
	// 利用【异或】位运算 0^X = X ，x^x = 0
	for (int i = 0; i < size; i++) {
		result ^= (a[i] ^ i);
	}
	result ^= size;
	std::cout << result << std::endl;
}


/************************************************************************/
/* 给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现了三次。找出那个只出现了一次的元素。
/* 说明：你的算法应该具有线性时间复杂度。你可以不使用额外空间来实现吗？
/* 根据位运算                                                                    
/************************************************************************/
int BitAlog::findOnly(int* a, int freq, int size)
{
	int result = 0;
	int number = 0;
	for (int i = 0; i < sizeof(int); i++) {
		number = 0;
		for (int j = 0; j < size; j++) {
			//std::cout << a[j] << std::endl;
			number += (a[j] >> i) & 1;
		}
		result |= (number % freq) << i;
	}
	return result;
}

/************************************************************************/
/* 找出字符串中第一次出现的字符，如 "abacdeeff",返回b                                                                     */
/************************************************************************/
char BitAlog::findFirst(const char* a)
{
	int map[256] = { 0 };

	const char* pKey = a;
	while (*pKey != '\0')
	{
		map[*pKey++]++;
	}

	pKey = a;
	while (*pKey != '\0')
	{
		if (map[*pKey] == 1)
			return *pKey;

		pKey++;
	}
	return '\0';
}

/************************************************************************/
/* 找到一个数二进制中1的个数                                                                     */
/************************************************************************/
void BitAlog::findNumOfOne(int a)
{
	int count = 0;
	while (a)
	{
		count++;
		// 位运算小技巧: 对于任意一个数，将 n 和 n-1 进行 & 运算，可以将 n 中最低位的 1 变成 0 
		a &= (a - 1);
	}
}

/************************************************************************/
/*  a = 3,返回 1 + 2 + 3 = 6                                                                    */
/************************************************************************/
int BitAlog::getSum(int a)
{
	a > 0 && (a += getSum(a - 1));
	std::cout << a << std::endl;
	return a;
}

/************************************************************************/
/* 素数/质数，除了1和自身，不能被其他数整除                                                                     */
/************************************************************************/
void BitAlog::findPrim(int* a, int size)
{
	for (int i = 0; i < size; i++) {
		// 若为偶数，肯定不是素数
		if ((a[i] & 1) == 0) {
			continue;
		}
		bool isPrim = true;
		int k = (int)std::sqrt(a[i]);
		for (int j = 3; j <= k; j++) {
			if (a[i] % j == 0) {
				isPrim = false;
				break;
			}
		}
		if (isPrim) {
			char buff[256] = { 0 };
			sprintf_s(buff, 256, "num[%d] = %d", i, a[i]);
			std::cout << std::string(buff) << std::endl;
		}
	}
}