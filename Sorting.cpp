#include "Sorting.h"
#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

void swap(int *small, int *big)
{
	int temp = *small;
	*small = *big;
	*big = temp;
}

void SelectionSort(int arr[], int n)
{
	int min_ind;
	for (int i = 0; i < n - 1; i++)
	{
		min_ind = i;
		for (int j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[min_ind])
			{
				min_ind = j;
			}
		}

		swap(&arr[min_ind], &arr[i]);

	}
}

void BubbleSort(int arr[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(&arr[j], &arr[j + 1]);
			}
		}
	}
}

void InsertionSort(int arr[], int n)
{
	int Key, j;
	for (int i = 0; i < n; i++)
	{
		Key = arr[i];
		j = i - 1;

		while (j >= 0 && arr[j] > Key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = Key;

	}
}

void Merge(int arr[], int FirstS, int FirstE, int SecondE)
{
	int n1 = FirstE - FirstS + 1;
	int n2 = SecondE - FirstE;

	vector<int> First(n1), Second(n2);

	for (int i = 0; i < n1; i++)
	{
		First[i] = arr[FirstS + i];
	}

	for (int j = 0; j < n2; j++)
	{
		Second[j] = arr[FirstE + 1 + j];
	}

	int i = 0, j = 0, k = FirstS;

	while (i < n1 && j < n2)
	{
		if (First[i] <= Second[j])
		{
			arr[k] = First[i];
			i++;
		}
		else
		{
			arr[k] = Second[j];
			j++;
		}
		k++;
	}

	while (i < n1)
	{
		arr[k] = First[i];
		i++;
		k++;
	}


	while (j < n2)
	{
		arr[k] = Second[j];
		j++;
		k++;
	}
}

void MergeSort(int arr[], int l, int r)
{
	if (l >= r)
	{
		return;
	}
	int m = l + (r - l) / 2;
	MergeSort(arr, l, m);
	MergeSort(arr, m + 1, r);
	Merge(arr, l, m, r);
}

void Heap(int arr[], int size, int root)
{
	int largest = root; 
	int left = 2 * root + 1; 
	int right = 2 * root + 2; 

							  
	if (left < size && arr[left] > arr[largest])
	{
		largest = left;
	}

	
	if (right < size && arr[right] > arr[largest])
	{
		largest = right;
	}

	if (largest != root)
	{
		swap(arr[root], arr[largest]);

		Heap(arr, size, largest);
	}
}

void HeapSort(int arr[], int size)
{
	for (int i = size / 2 - 1; i >= 0; i--)
	{
		Heap(arr, size, i);
	}

	for (int i = size - 1; i > 0; i--)
	{
		swap(arr[0], arr[i]);

		Heap(arr, i, 0);
	}
}

void PrintArray(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << endl;
	}
}
