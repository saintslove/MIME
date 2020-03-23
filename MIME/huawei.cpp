#include "huawei.h"
#include <iostream>
#include <vector>
#include <set>

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

