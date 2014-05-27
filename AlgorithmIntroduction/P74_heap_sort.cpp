#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <cstdint>
using namespace std;

inline int parent(int i)
{
	return (int)floor((i - 1) / 2);
}
inline int leftChild(int i)
{
	return (2 * i + 1);
}
inline int rightChild(int i)
{
	return (2 * i + 2);
}
static void adjustHeap(int dataArray[], const int arraySize,const int i)
{
	int left = leftChild(i);
	int right = rightChild(i);
	int largest = 0;
	int temp = 0;
	if (left < arraySize && dataArray[left] > dataArray[i])
	{
		largest = left;
	}
	else{
		largest = i;
	}
	if (right < arraySize && dataArray[right] > dataArray[largest])
	{
		largest = right;
	}

	if (largest != i)
	{
		swap(dataArray[i], dataArray[largest]);
		adjustHeap(dataArray, arraySize, largest);
	}
}
static void buildHeap(int dataArray[], const int arraySize)
{
	if(arraySize<=1)
	{
		return;
	}
	const int firstAdjust = arraySize / 2 - 1;
	for (int i = firstAdjust; i >= 0;i--)
	{
		adjustHeap(dataArray, arraySize, i);
	}
}
static void heapSort(int dataArray[], const int arraySize)
{
	for (int i = arraySize - 1; i >= 0;i--)
	{
		swap(dataArray[0], dataArray[i]);
		adjustHeap(dataArray, i, 0);
	}
}
static int heapExtraMax(int dataArray[], int& arraySize)
{
	assert(arraySize >= 1);
	int maxNum = dataArray[0];
	dataArray[0] = dataArray[arraySize - 1];
	int newArraySize = arraySize - 1;
	adjustHeap(dataArray, newArraySize, 0);
	arraySize = newArraySize;
	return maxNum;
}
static void heapIncreaseKey(int dataArray[], const int arraySize, const int i,const int key)
{
	dataArray[i] = key;
	int j = i;
	//bigger
	while (j > 0 && dataArray[parent(j)] < dataArray[j])
	{
		swap(dataArray[j], dataArray[parent(j)]);
		j = parent(j);
	}
}
static int* heapInsertKey(int dataArray[], const int arraySize, const int key)
{
	int* tmpArray = new int[arraySize + 1];
	copy(dataArray, dataArray + arraySize, tmpArray);

	int tmpArraySize = arraySize + 1;
	tmpArray[tmpArraySize - 1] = INT32_MIN;

	heapIncreaseKey(tmpArray, arraySize, tmpArraySize - 1, key);

	return tmpArray;
}
static void displayHeap(const int dataArray[], const int arraySize)
{
	for (int i = 0; i < arraySize;i++)
	{
		cout << dataArray[i] << " ";
	}
	cout << endl;
}
void test_p74_heap_sort()
{
	int dataArray[] = { 23, 53, 2, 1, -534 };
	int arraySize = sizeof(dataArray) / sizeof(int);

	cout << "before build heap" << endl;
	displayHeap(dataArray, arraySize);

	buildHeap(dataArray, arraySize);
	cout << "after build heap" << endl;
	displayHeap(dataArray, arraySize);

	int maxNum = heapExtraMax(dataArray, arraySize);
	cout << "after heap extra max" << endl;
	displayHeap(dataArray, arraySize);

	heapIncreaseKey(dataArray, arraySize, 0, 120);
	cout << "after heap increase key" << endl;
	displayHeap(dataArray, arraySize);

	int* newArray = heapInsertKey(dataArray, arraySize, 11);
	int newArraySize = arraySize + 1;
	cout << "after heap insert key" << endl;
	displayHeap(newArray, newArraySize);
	
	heapSort(dataArray, arraySize);
	cout << "after heap sort" << endl;
	displayHeap(dataArray, arraySize);
}