#include "windows.h"
#include <map>
#include <set>
#include <iostream>
#include <functional>
#include <cmath>

windows::windows()
{
}


windows::~windows()
{
}

/************************************************************************/
/* ����һ������ nums����һ����СΪ k �Ļ������ڴ������������ƶ�����������Ҳࡣ
/* ��ֻ���Կ����ڻ��������ڵ� k �����֡���������ÿ��ֻ�����ƶ�һλ�����ػ��������е����ֵ��                                                                     */
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
/* ����һ���ַ����������ҳ����в������ظ��ַ��� ��Ӵ� �ĳ���
/*
/* ʾ�� 1:
/* ����: "abcabcbb"
/* ��� : 3
/* ���� : ��Ϊ���ظ��ַ�����Ӵ��� "abc"�������䳤��Ϊ 3��
/*
/* ʾ�� 2 :
/* ���� : "bbbbb"
/* ��� : 1
/* ���� : ��Ϊ���ظ��ַ�����Ӵ��� "b"�������䳤��Ϊ 1��                                                                     */
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
/*  ����n���������ҳ���С�ĵ�k����
/*  ���룺4��5��1��6��2��7��3��8
/*  �����1��2��3��4                                                                    */
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
/*  �����ַ���A��B, ��A���޳�������B�е��ַ���
/*  ����A = ��hello world��, B = ��her����
/*  ��ô�޳�֮��A��Ϊ ��llo wold��                                                                   */
/************************************************************************/
void windows::removeDup(char* a, char* b)
{
	int hashMap[256] = { 0 };
	// ��ʼ��hashMap
	while (*b != '\0')
	{
		hashMap[*b++ - 'a']++;
	}
	//printf("%d%d%d", hashMap['h' - 'a'], hashMap['e' - 'a'], hashMap['w' - 'a']);

	char* slow = a;
	char* fast = a;
	while (*fast != '\0') {
		// ˵�������ڹ����ַ�
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
/*  ���������������У��ҳ����е���ϣ��������                                                                     */
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


