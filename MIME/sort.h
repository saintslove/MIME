#pragma once

#include "stdafx.h"
#include <memory>
#include <iostream>
#include <vector>

#define PRINT \
for (int i = 0; i < size; i++) { \
std::cout << a[i] << "  "; \
} \
std::cout << std::endl; \

class Sort
{
public:
	Sort();
	~Sort();

	//ѡ������
	void select_sort(int* a, int size);

	//��������
	void insert_sort(int* a, int size);


	//ϣ������
	void shell_insert(int *a, int d, int size);

	void shell_sort(int * a, int size);

	//����
	int partition(int* a, int low, int higth);

	void quick_sort(int *a, int low, int hight);

	//��ƽ��
	void adjust_max_heap(int* a, int size);

	void adjust_min_heap(int* a, int size);

	//�󶥶Ѷ���
	void heap_max_sort(int* a, int size);

	//С���Ѷ���
	void heap_min_sort(int* a, int size);


	//�鲢����
	void merge(int *a, int left, int mid, int right);

	void merge_sort(int *a, int left, int right);

	//��������
	void count_sort(int* a, int size);

	//��������
	int maxBit(int *a, int size);
	void radix_sort(int *a, int size);
};

