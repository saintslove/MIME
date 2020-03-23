#include "BitAlog.h"
#include <iostream>


BitAlog::BitAlog()
{
}


BitAlog::~BitAlog()
{
}


// ���ڸ������У��ҳ�ȱʧ��Ԫ��
// ��3,0,1�� ȱʧ��2��
void BitAlog::findN(int* a, int size)
{
	int result = 0;
	// ���á����λ���� 0^X = X ��x^x = 0
	for (int i = 0; i < size; i++) {
		result ^= (a[i] ^ i);
	}
	result ^= size;
	std::cout << result << std::endl;
}

//����һ���ǿ��������飬����ĳ��Ԫ��ֻ����һ�����⣬����ÿ��Ԫ�ؾ����������Ρ��ҳ��Ǹ�ֻ������һ�ε�Ԫ�ء�
//˵��������㷨Ӧ�þ�������ʱ�临�Ӷȡ�����Բ�ʹ�ö���ռ���ʵ����
//����λ����
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

// �ҳ��ַ����е�һ�γ��ֵ��ַ����� "abacdeeff",����b
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


// �ҵ�һ������������1�ĸ���
void BitAlog::findNumOfOne(int a)
{
	int count = 0;
	while (a)
	{
		count++;
		// λ����С����: ��������һ�������� n �� n-1 ���� & ���㣬���Խ� n �����λ�� 1 ��� 0 
		a &= (a - 1);
	}
}

// a = 3,���� 1 + 2 + 3 = 6
int BitAlog::getSum(int a)
{
	a > 0 && (a += getSum(a - 1));
	std::cout << a << std::endl;
	return a;
}

// ����/����������1�����������ܱ�����������
void BitAlog::findPrim(int* a, int size)
{
	for (int i = 0; i < size; i++) {
		// ��Ϊż�����϶���������
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