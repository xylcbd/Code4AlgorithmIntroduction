#include <iostream>
#include <iterator>
#include <algorithm>
#include <cmath>
#include <cstdint>
using namespace std;

static void bucket_sort(int dataArray[], const int arraySize)
{
	//get step
	int lowwer = INT32_MAX;
	int upper = INT32_MIN;
	int step = 0;
	for (int i = 0; i < arraySize;i++)
	{
		if (dataArray[i] < lowwer)
		{
			lowwer = dataArray[i];
		}else if (dataArray[i] > upper)
		{
			upper = dataArray[i];
		}
	}
	step = (upper - lowwer) / 10 +1;

	//allocated resource
	const int radix = 10;
	int* baseArrays[radix] = { nullptr };
	for (int i = 0; i < radix; i++)
	{
		baseArrays[i] = new int[arraySize + 1]; //first col is count
		fill(baseArrays[i], baseArrays[i] + arraySize + 1, 0); //init
	}

	//collect
	auto getLayer = [=](const int x)->int{
		return (x - lowwer) / step;
	};
	for (int i = 0; i < arraySize; i++)
	{
		const int layer = getLayer(dataArray[i]);
		const int count = baseArrays[layer][0];
		baseArrays[layer][count + 1] = dataArray[i];
		baseArrays[layer][0]++;
	}

	//sort
	for (int i = 0; i < radix;i++)
	{
		int count = baseArrays[i][0];
		int* base = baseArrays[i] + 1;
		sort(base, base + count);
	}

	//merge
	int index = 0;
	for (int i = 0; i < radix; i++)
	{
		int count = baseArrays[i][0];
		int* base = baseArrays[i] + 1;
		for (int j = 1; j <= count;j++)
		{
			dataArray[index++] = baseArrays[i][j];
		}
	}

	//release resource
	for (int i = 0; i < radix; i++)
	{
		delete[] baseArrays[i];
	}
}

void test_p102_bucket_sort()
{
	int dataArray[] = { 23, 45, 1, 34, 5, 0, 4, 23, 4 };
	const int arraySize = sizeof(dataArray) / sizeof(int);

	cout << "before bucket sort : ";
	copy(dataArray, dataArray + arraySize, ostream_iterator<int>(cout, " ")); cout << endl;
	bucket_sort(dataArray, arraySize);
	cout << "after bucket sort : ";
	copy(dataArray, dataArray + arraySize, ostream_iterator<int>(cout, " ")); cout << endl;
}