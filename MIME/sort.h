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

	//Ñ¡ÔñÅÅÐò
	void select_sort(int* a, int size);

	//²åÈëÅÅÐò
	void insert_sort(int* a, int size);


	//Ï£¶ûÅÅÐò
	void shell_insert(int *a, int d, int size);

	void shell_sort(int * a, int size);

	//¿ìÅÅ
	int partition(int* a, int low, int higth);

	void quick_sort(int *a, int low, int hight);

	//¶ÑÆ½ºâ
	void adjust_max_heap(int* a, int size);

	void adjust_min_heap(int* a, int size);

	//´ó¶¥¶Ñ¶ÑÅÅ
	void heap_max_sort(int* a, int size);

	//Ð¡¶¥¶Ñ¶ÑÅÅ
	void heap_min_sort(int* a, int size);


	//¹é²¢ÅÅÐò
	void merge(int *a, int left, int mid, int right);

	void merge_sort(int *a, int left, int right);

	//¼ÆÊýÅÅÐò
	void count_sort(int* a, int size);

	//»ùÊýÅÅÐò
	int maxBit(int *a, int size);
	void radix_sort(int *a, int size);
};

