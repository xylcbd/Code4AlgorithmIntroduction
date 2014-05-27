#include <iostream>
#include <iterator>
#include <algorithm>
using namespace std;

static int partition(int dataArray[], const int left, const int right)
{
	const int flagValue = dataArray[right];
	int i = left - 1;

	for (int j = left; j < right;j++)
	{
		if (dataArray[j] <= flagValue)
		{
			i++;
			swap(dataArray[i], dataArray[j]);
		}
	}
	swap(dataArray[i + 1], dataArray[right]);
	return i+1;
}
static int partition2(int dataArray[], const int left, const int right)
{
	const int flagValue = dataArray[left];
	int i = left;
	int j = right;

	while (i < j)
	{
		//right
		while (i < j && dataArray[j] >= flagValue)
		{
			j--;
		}
		swap(dataArray[i], dataArray[j]);
		//left
		while (i < j && dataArray[i] <= flagValue)
		{
			i++;
		}
		swap(dataArray[i], dataArray[j]);
	}
	return i;
}
static void quick_sort_imp(int dataArray[], const int left, const int right)
{
	if (left < right)
	{
		int partitionPos = partition2(dataArray, left, right);
		quick_sort_imp(dataArray, left, partitionPos-1);
		quick_sort_imp(dataArray, partitionPos + 1, right);
	}
}
static void quick_sort(int dataArray[], const int arraySize)
{
	quick_sort_imp(dataArray, 0, arraySize - 1);
}

void test_p85_quick_sort()
{
	int dataArray[] = { 23, 45, 1, -34, 5, 0, 435 };
	const int arraySize = sizeof(dataArray) / sizeof(int);

	cout << "before quick sort : ";
	copy(dataArray, dataArray + arraySize, ostream_iterator<int>(cout, " ")); cout << endl;
	quick_sort(dataArray, arraySize);
	cout << "after quick sort : ";
	copy(dataArray, dataArray + arraySize, ostream_iterator<int>(cout, " ")); cout << endl;
}