#include <iostream>
#include <cstdlib>
#include <ctime>
#include<chrono>
#include <cstdio>
#include "Sorting.h"

using namespace std;
using namespace std::chrono;

int main()
{
	int SortArr[100];
	int n = sizeof(SortArr) / sizeof(SortArr[0]);
	srand(time(0));

	for (int i = 0; i < n; i++)
	{
		SortArr[i] = rand();
	}

	//Selection Sort
	auto startTime1 = high_resolution_clock::now();
	SelectionSort(SortArr, n);
	auto stopTime1 = high_resolution_clock::now();
	auto duration1 = duration_cast<microseconds>(stopTime1 - startTime1);

	cout << "Selection Sort : " << endl << endl;
	PrintArray(SortArr, n);
	cout << "Sorting Time in Microseconds : ";
	cout << duration1.count() << endl << endl;

	//Bubble Sort
	auto startTime2 = high_resolution_clock::now();
	BubbleSort(SortArr, n);
	auto stopTime2 = high_resolution_clock::now();
	auto duration2 = duration_cast<microseconds>(stopTime2 - startTime2);

	cout << "Bubble Sort : " << endl << endl;
	PrintArray(SortArr, n);
	cout << "Sorting Time in Microseconds : ";
	cout << duration2.count() << endl << endl;

	//Insertion Sort
	auto startTime3 = high_resolution_clock::now();
	InsertionSort(SortArr, n);
	auto stopTime3 = high_resolution_clock::now();
	auto duration3 = duration_cast<microseconds>(stopTime3 - startTime3);

	cout << "Insertion Sort : " << endl << endl;
	PrintArray(SortArr, n);
	cout << "Sorting Time in Microseconds : ";
	cout << duration3.count() << endl << endl;

	//Merge Sort
	auto startTime4 = high_resolution_clock::now();
	MergeSort(SortArr, 0, n - 1);
	auto stopTime4 = high_resolution_clock::now();
	auto duration4 = duration_cast<microseconds>(stopTime4 - startTime4);

	cout << "Merge Sort : " << endl << endl;
	PrintArray(SortArr, n);
	cout << "Sorting Time in Microseconds : ";
	cout << duration4.count() << endl << endl;

	//Heap Sort
	auto startTime5 = high_resolution_clock::now();
	HeapSort(SortArr, n);
	auto stopTime5 = high_resolution_clock::now();
	auto duration5 = duration_cast<microseconds>(stopTime5 - startTime5);

	cout << "Heap Sort : " << endl << endl;
	PrintArray(SortArr, n);
	cout << "Sorting Time in Microseconds : ";
	cout << duration5.count() << endl << endl;

	cout << "Press ENTER to continue...";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	return 0;
}
