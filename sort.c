/*
 ============================================================================
 Name        : sort.c
 Author      : zh
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void  swap(int a[], int i, int j)
{
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

void cocktailsort(int a[], int n)
{
	int left = 0;
	int right = n - 1;
	while (left < right)
	{
		for (int i = left; i < right; i++)
		{
			if (a[i] > a[i+1])
			{
				swap(a, i, i+1);
			}
		}
		right--;
		for (int i = right; i > left; i--)
		{
			if (a[i - 1] > a[i])
			{
				swap(a, i - 1, i);
			}
		}
		left++;
	}
}


void SelectSort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (a[j] < a[min])  // 找出未排序序列中的最小值
			{
				min = j;
			}
		}
		if (min != i)
		{
			swap(a, min, i);   // 放到已排序序列的末尾，该操作很有可能把稳定性打乱，所以选择排序是不稳定的排序算法

		}
	}
}

void insertsort(int a[], int n)
{
	for (int i = 1; i< n; i++)
	{
		int get = a[i];    // 右手抓到一张扑克牌
		int j = i - 1;     // 拿在左手上的牌总是排序好的
		while(j >= 0 && a[j] > get)   // 将抓到的牌与手牌从右向左进行比较
		{
			a[j + 1] = a[j];    // 如果该手牌比抓到的牌大，就将其右移
			j--;
		}
		a[j + 1] = get;  // 直到该手牌比抓到的牌小(或二者相等)，将抓到的牌插入到该手牌右边(相等元素的相对次序未变，所以插入排序是稳定的)
	}
}


void InsertSortDicchomoty(int a[], int n)
{
	for (int i = 0;  i < n; i++)
	{
		int get = a[i];
		int left = 0;
		int right = i - 1;
		while (left < right)
		{
			int mid = (left + right) / 2;
			if (a[mid] > get)
				right = mid - 1;
			else
				left = mid + 1;
		}
		for (int j = i - 1; j >= left; j--)
		{
			a[j + 1] = a[j];
		}
		a[left] = get;
	}
}

void shellsort(int a[], int n)
{
	int h = 0;
	while (h <= n)
	{
		h = 3 * h + 1;
	}
	while (h >= 1)
	{
		for (int i = h; i < n; i++)
		{
			int j = i - h;
			int get = a[i];
			while(j >= 0 && a[j] > get)
			{
				a[j + h] = a[j];
				j = j - h;
			}
			a[j + h] = get;
		}
		h = (h - 1) / 3;
	}
}

int partition(int a[], int left, int right)
{
	int pivot = a[right];
	int tail = left - 1;
	for (int i = left; i < right; i++)
	{
		if (a[i] < pivot)
		{
			swap(a, ++tail, i);
		}
	}
	swap(a, tail + 1, right);

	return tail + 1;
}

void QuickSort(int a[], int left, int right)
{
	if (left >= right)
		return;
	int pivot_index = partition(a, left, right);
	QuickSort(a, left, pivot_index - 1);
	QuickSort(a, pivot_index + 1, right);
}


int main(void) {
	int a[] = { 6, 5, 3, 1, 8, 7, 2, 4 };   // 从小到大定向冒泡排序
	int n = sizeof(a) / sizeof(int);
//	cocktailsort(a, n);
//	printf("鸡尾酒排序结果： ");
//	SelectSort(a, n);
//	printf("选择排序结果：");
//	insertsort(a,n);
//	printf("插入排序结果：");
	QuickSort(a, 0, n - 1);
	printf("快速排序结果：");


	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");

	return EXIT_SUCCESS;
}
