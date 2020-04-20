#include "huawei.h"
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

huawei::huawei()
{
}


huawei::~huawei()
{
}


/************************************************************************/
/* 翻转字符串
/* i am a boy  -> boy a am i
/************************************************************************/
string huawei::reverse(string sentence)
{
	std::vector<string> vec;
	string rst = "";
	size_t pos1 = sentence.find(" ");
	size_t pos2 = 0;
	while (pos1 != sentence.npos)
	{
		vec.push_back(sentence.substr(pos2, pos1 - pos2));
		pos2 = pos1 + 1;
		pos1 = sentence.find(" ", pos2);
	}
	if (pos2 < sentence.length())
		vec.push_back(sentence.substr(pos2));

	for (std::vector<string>::size_type i = 0, j = vec.size() - 1; i < j; i++, j--) {
		std::swap(vec[i], vec[j]);
	}
	rst += vec[0];
	for (int i = 1; i < vec.size(); i++) {

		rst += " " + vec[i];
	}

	std::cout << rst << std::endl;
	return sentence;
}


/************************************************************************/
/* n个任务，m个执行机器，使用最短耗时调度算法 求最小时间    */
/* 输入 3台处理器，6个任务，
/* 耗时分别为 5,7,2,10,3,1
/* 总耗时：13
/************************************************************************/
void huawei::cpuProcess()
{
	int m, n;
	cin >> m >> n;
	int t;
	int k = n;
	std::multiset<int, std::less<int> > sets;
	while (k--) {
		cin >> t;
		sets.insert(t);
	}
	std::vector<int> vecs(sets.begin(), sets.end());

	int sum = 0;
	if (m >= n) {
		sum = vecs[vecs.size() - 1];
	}
	else {
		int j = vecs.size() - 1;
		while ((j - m) > 0)
		{
			sum = vecs[j] + vecs[j - m];
			j -= m;
		}

	}
	std::cout << sum << std::endl;
}

/************************************************************************/
/* 删除字符串中出现次数最少的字符后的字符串。
/* 输入：abcdd      输出：dd
/************************************************************************/
void huawei::removeLatest(const char* sentence)
{
	int hashMap[256] = { 0 };
	int count = 0;
	const char* a = sentence;
	int min = 1 << 10 - 1;
	while (*a != '\0') {
		count++;
		hashMap[*a - 'a']++;
		min = std::min(min,hashMap[*a - 'a']);
		a++;
	}
	a = sentence;
	string str("");
	while (*a != '\0') {
		if (hashMap[*a - 'a'] != min) {
			str.push_back(*a);
		}
		a++;
	}
	std::cout << str << std::endl;
}

/************************************************************************/
/*  给定n个字符串，请对n个字符串按照字典序排列。                                                                     */
/************************************************************************/
void huawei::sortStr()
{
	int n = 0;
	cin >> n;
	string str;
	//std::set<string> sets;
	std::multiset<string> sets;
	while (n--)
	{
		cin >> str;
		sets.insert(str);
	}

	for (auto c : sets) {
	std:cout << c << std::endl;
	}

}

/************************************************************************/
/* 获取最长字符串长度                                                                     */
/************************************************************************/
int huawei::getCommonStrLength(char * pFirstStr, char * pSecondStr)
{
	int lenx = strlen(pFirstStr);
	int leny = strlen(pSecondStr);
	int max = 0;
	std::vector<std::vector<int>> vec(leny + 1, std::vector<int>(lenx + 1, 0));
	for (int i = 1; i <= leny; i++) {
		for (int j = 1; j <= lenx; j++) {
			//std::cout << pFirstStr[i - 1] << "  " << pSecondStr[j - 1] << std::endl;
			vec[i][j] = pFirstStr[j-1] == pSecondStr[i-1] ? vec[i - 1][j - 1] + 1 : 0;
			max = max > vec[i][j] ? max : vec[i][j];
			//std::cout << max << std::endl;
			//std::cout << vec[i][j] << "  ";
		}
		//std::cout << std::endl;
	}

	std::cout << max << std::endl;
	return max;
}

/************************************************************************/
/* 判断短字符串中的所有字符是否在长字符串中全部出现
/* 输入两个字符串。第一个为短字符，第二个为长字符。
/* 输入： bc abc
/* 输出：true
/************************************************************************/
bool huawei::IsAllCharExist(char* pShortString, char* pLongString)
{
	int chars[256] = {0};
	const char* a = pLongString;
	while (*a++ != '\0') {
		chars[*a - 'A']++;
	}
	a = pShortString;
	bool isAll = 1;
	while (*a != '\0') {
		if (chars[*a - 'A'] == 0) {
			isAll = 0;
			break;
		}
		a++;
	}
	if (isAll) {
		std::cout << "true" << std::endl;
	}
	else
	{
		std::cout << "false" << std::endl;

	}
	

	return isAll;
}


/************************************************************************/
/* 按照从右向左的阅读顺序，返回一个不含重复数字的新的整数
/* 9876673 -> 37689
/************************************************************************/
void huawei::removdDump(int input)
{
	int vec[10] = { 0 };
	//std::vector<int> newNum;
	int newNum = 0;
	while (input) {
		int num = input % 10;
		if (vec[num] == 0) {
			vec[num]++;
			newNum = newNum * 10 + num;
			//newNum.push_back(num);
		}
		input /= 10;
	}
	std::cout << newNum << std::endl;
}

/************************************************************************/
/* 功能:输入一个正整数，按照从小到大的顺序输出它的所有质因子（如180的质因子为2 2 3 3 5 ）                                                                     */
/************************************************************************/
void huawei::findPrim(int input)
{
	std::set<int> sets;
	std::vector<int> vec;
	int base = (int)sqrt(input);
	for (int i = 2; i <= base; i++) {
		if (input % i == 0) {
			vec.push_back(i);
			vec.push_back(input / i);
			//std::cout << i << "   " << input / i << std::endl;
		}
	}
	for (int i = 0; i < vec.size(); i++) {
		if (vec[i] == 2) {
			sets.insert(vec[i]);
			continue;
		}
		if(vec[i] % 2 == 0)
			continue;
		int base = (int)sqrt(vec[i]);
		bool isPrim = true;
		for (int j = 3; j <= base; j++) {
			if (vec[i] % j == 0) {
				isPrim = false;
				break;
			}
		}
		if(isPrim)
			sets.insert(vec[i]);
	}

	for (auto c : sets) {
		std::cout << c << std::endl;
	}
}


int huawei::FirstNotRepeatingChar(string str)
{
	int index = -1;
	int chars[256] = { 0 };
	for (int i = 0; i < str.size(); i++) {
		chars[str[i] - 'A']++;
	}
	for (int i = 0; i < str.size(); i++) {
		if (chars[str[i] - 'A'] == 1) {
			index = i;
			break;
		}
	}
	std::cout << index << std::endl;
	return index;
}