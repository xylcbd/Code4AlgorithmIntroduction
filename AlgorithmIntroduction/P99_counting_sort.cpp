#include <iostream>
#include <iterator>
#include <algorithm>
using namespace std;

static void counting_sort(int dataArray[], const int arraySize,const int upper)
{
	const int countSize = upper + 1;
	int* countArray = new int[countSize];
	int* tmpArray = new int[arraySize];
	//step 1
	fill(countArray, countArray + countSize, 0);
	//step 2
	for (int i = 0; i < arraySize;i++)
	{
		int data = dataArray[i];
		countArray[data]++;
	}
	//step 3
	for (int i = 1; i < countSize;i++)
	{
		countArray[i] += countArray[i - 1];
	}
	//step 4
	for (int i = 0; i < arraySize;i++)
	{
		int data = dataArray[i];
		int pos = countArray[data]-1;
		tmpArray[pos] = data;
		countArray[data] -= 1;
	}

	copy(tmpArray, tmpArray + arraySize, dataArray);
	delete[] tmpArray;
}

void test_p99_counting_sort()
{
	int dataArray[] = { 23, 45, 1, 34, 5, 0, 4 ,23,4};
	const int arraySize = sizeof(dataArray) / sizeof(int);

	cout << "before counting sort : ";
	copy(dataArray, dataArray + arraySize, ostream_iterator<int>(cout, " ")); cout << endl;
	counting_sort(dataArray, arraySize,100); //0 ~ 100
	cout << "after counting sort : ";
	copy(dataArray, dataArray + arraySize, ostream_iterator<int>(cout, " ")); cout << endl;
}