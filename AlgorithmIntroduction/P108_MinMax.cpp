#include <iostream>
#include <iterator>
#include <algorithm>
#include <cmath>
#include <cstdint>
#include <cassert>
using namespace std;

typedef struct MINMAXVALUE
{
	int minValue;
	int maxValue;
}MINMAXVALUE;

static MINMAXVALUE min_max(int dataArray[], const int arraySize)
{
	assert(arraySize > 0);

	MINMAXVALUE result = { 0 };
	int start = 0;
	if (arraySize % 2)
	{
		result.minValue = dataArray[0];
		result.maxValue = dataArray[0];
		start = 1;
	}
	else
	{
		int minPos = dataArray[0] > dataArray[1] ? 1 : 0;
		int maxPos = 1 - minPos;
		result.minValue = dataArray[minPos];
		result.maxValue = dataArray[maxPos];
		start = 2;
	}
	for (int i = start; i < arraySize;i+=2)
	{
		int minPos = dataArray[i] > dataArray[i+1] ? (i+1) : i;
		int maxPos = 2 * i + 1 - minPos;
		if (result.minValue > dataArray[minPos])
		{
			result.minValue = dataArray[minPos];
		}
		if (result.maxValue < dataArray[maxPos])
		{
			result.maxValue = dataArray[maxPos];
		}
	}
	return result;
}

void test_p108_min_max()
{
	int dataArray[] = { 23, 45, 1, 34, 5, 0, 4, 23, 4 };
	const int arraySize = sizeof(dataArray) / sizeof(int);

	cout << "find minmax value from array: ";
	copy(dataArray, dataArray + arraySize, ostream_iterator<int>(cout, " ")); cout << endl;
	MINMAXVALUE result = min_max(dataArray, arraySize);
	cout << "min is : " << result.minValue << endl;
	cout << "max is : " << result.maxValue << endl;
}