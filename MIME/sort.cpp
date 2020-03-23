#include "sort.h"



Sort::Sort()
{
}


Sort::~Sort()
{
}


/************************************************************************/
/*   —°‘Ò≈≈–Ú                                                                   */
/************************************************************************/
void Sort::select_sort(int* a, int size)
{
	for (int i = 0; i < size - 1; i++) {
		int index = i;
		for (int j = i + 1; j <= size - 1; j++) {
			if (a[j] < a[index])
				index = j;
		}
		int temp = a[i];
		a[i] = a[index];
		a[index] = temp;
	}
}


/************************************************************************/
/*    ≤Â»Î≈≈–Ú                                                                  */
/************************************************************************/
void Sort::insert_sort(int* a, int size) {
	for (int i = 1; i < size; i++) {
		int key = a[i];
		int j = i - 1;
		while (j >= 0 && a[j] < key)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = key;
	}
}



/************************************************************************/
/*  œ£∂˚≈≈–Ú
/*  ¿‡À∆≤Â»Î≈≈–Ú                                                                   */
/************************************************************************/
void Sort::shell_insert(int *a, int d, int size)
{
	for (int i = d; i < size; i++) {
		int key = a[i];
		int j = i - d;
		while (j >= 0 && a[j] > key) {
			a[j + d] = a[j];
			j -= d;
		}
		a[j + d] = key;
	}
}

void Sort::shell_sort(int * a, int size)
{
	int d = size / 2;
	while (d > 0)
	{
		shell_insert(a, d, size);
		d /= 2;
	}
}




/************************************************************************/
/*   øÏ≈≈                                                                   */
/************************************************************************/
int Sort::partition(int* a, int low, int higth)
{
	int temp = a[low];
	while (low < higth)
	{
		while (low < higth && a[higth] >= temp)
			higth--;
		a[low] = a[higth];
		while (low < higth && a[low] <= temp)
			low++;
		a[higth] = a[low];
	}
	a[low] = temp;
	return low;
}

void Sort::quick_sort(int *a, int low, int hight)
{
	if (low > hight)
		return;
	int pivot = partition(a, low, hight);
	printf("pivot = %d\n", pivot);
	quick_sort(a, low, pivot - 1);
	quick_sort(a, pivot + 1, hight);
}




/************************************************************************/
/*  ¥Û∂•∂—∆Ω∫‚                                                                    */
/************************************************************************/
void Sort::adjust_max_heap(int* a, int size)
{
	for (int i = size / 2 - 1; i >= 0; i--) {
		//int largest = i;
		while (true)
		{
			int left = 2 * i + 1;
			int right = 2 * i + 2;
			int largest = left;
			if (right < size) {
				largest = a[left] > a[right] ? left : right;
			}
			if (largest < size) {
				largest = a[largest] > a[i] ? largest : i;
			}
			if (largest < size && largest != i) {
				int temp = a[i];
				a[i] = a[largest];
				a[largest] = temp;
				i = largest;
				//PRINT
				continue;
			}
			else {
				//PRINT
				break;
			}
			/*if (left < size && a[left] > a[i]) {
			largest = left;
			}
			else {
			largest = i;
			}
			if (right < size && a[right] > a[largest]) {
			largest = right;
			}
			if (largest != i) {
			int temp = a[i];
			a[i] = a[largest];
			a[largest] = temp;
			i = largest;
			PRINT
			continue;
			}
			else {
			PRINT
			break;
			}*/
		}

	}
}

/************************************************************************/
/* ¥Û∂•∂—∂—≈≈                                                                     */
/************************************************************************/
void Sort::heap_max_sort(int* a, int size)
{
	adjust_max_heap(a, size);
	int index = size - 1;
	while (index > 0) {
		int temp = a[index];
		a[index] = a[0];
		a[0] = temp;
		index -= 1;
		adjust_max_heap(a, index + 1);
	}
}




/************************************************************************/
/*    –°∂•∂—∆Ω∫‚                                                                 */
/************************************************************************/
void Sort::adjust_min_heap(int* a, int size)
{
	for (int i = size / 2 - 1; i >= 0; i--) {
		while (true)
		{
			int left = 2 * i + 1;
			int right = 2 * i + 2;
			int little = left;
			if (right < size) {
				little = a[left] < a[right] ? left : right;
			}
			if (little < size) {
				little = a[little] < a[i] ? little : i;
			}
			if (little < size && little != i) {
				int temp = a[i];
				a[i] = a[little];
				a[little] = temp;
				i = little;
				//PRINT
				continue;
			}
			else {
				//PRINT
				break;
			}
		}
	}
}


/************************************************************************/
/*   –°∂•∂—∂—≈≈                                                                   */
/************************************************************************/
void Sort::heap_min_sort(int* a, int size)
{
	adjust_min_heap(a, size);
	int index = size - 1;
	while (index > 0)
	{
		int temp = a[index];
		a[index] = a[0];
		a[0] = temp;
		index -= 1;
		adjust_min_heap(a, index + 1);
	}
}




/************************************************************************/
/*  πÈ≤¢≈≈–Ú                                                                    */
/************************************************************************/
void Sort::merge(int *a, int left, int mid, int right)
{
	std::vector<int> temp(right - left + 1);
	int index1 = left;
	int index2 = mid + 1;
	int copyIndex = 0;
	while (index1 <= mid && index2 <= right)
	{
		a[index1] < a[index2] ? temp[copyIndex++] = a[index1++] : temp[copyIndex++] = a[index2++];
	}
	while (index1 <= mid) {
		temp[copyIndex++] = a[index1++];
	}
	while (index2 <= right) {
		temp[copyIndex++] = a[index2++];
	}
	for (int i = left; i <= right; i++) {
		a[i] = temp[i - left];
	}
}

void Sort::merge_sort(int *a, int left, int right)
{
	if (left >= right) {
		return;
	}
	int mid = left + (right - left) / 2;
	merge_sort(a, left, mid);
	merge_sort(a, mid + 1, right);
	merge(a, left, mid, right);
}



/************************************************************************/
/*  º∆ ˝≈≈–Ú                                                                    */
/************************************************************************/
void Sort::count_sort(int* a, int size)
{
	int max = a[0];
	int min = a[0];
	for (int i = 1; i < size; i++) {
		max = a[i] > max ? a[i] : max;
		min = a[i] < min ? a[i] : min;
	}
	std::vector<int> count(max - min + 1);
	for (int i = 0; i < size; i++) {
		count[a[i] - min]++;
	}
	int index = 0;
	for (int i = 0; i <= (max - min); i++) {
		for (int j = 0; j < count[i]; j++) {
			a[index++] = i + min;
		}
	}
}




/************************************************************************/
/*   ª˘ ˝≈≈–Ú                                                                   */
/************************************************************************/
int Sort::maxBit(int *a, int size)
{
	int len = 0;
	for (int i = 0; i < size; i++) {
		int count = 0;
		int v = a[i];
		while (v > 0) {
			count++;
			v /= 10;
		}
		len = len > count ? len : count;
	}
	return len;
}

void Sort::radix_sort(int *a, int size)
{
	std::vector<std::vector<int>> buckets(10);
	int bit = maxBit(a, size);
	int r = 1;
	for (int i = 0; i < bit; i++) {
		for (int j = 0; j < size; j++) {
			buckets[(a[j] / r) % 10].push_back(a[j]);
		}
		int index = 0;
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < buckets[i].size(); j++) {
				a[index++] = buckets[i][j];
			}
			buckets[i].clear();
		}
		r *= 10;
	}
}