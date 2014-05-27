#include <iostream>
#include <iterator>
#include <algorithm>
#include <cmath>
using namespace std;

//123 0 => 3
//123 1 => 2
//123 2 => 1
//123 3 => -1
inline int getColNum(const int x, const int col)
{
	int powVal = static_cast<int>(pow(10, col));
	int remainder = x - (powVal * 10) * (x / (powVal * 10));
	return remainder / powVal;
}
//1234 => 4
//2 => 1
//234 => 3
inline int getCols(const int x)
{
	int cols = 0;
	int iter = x;
	while (iter)
	{
		cols++;
		iter /= 10;
	}
	return cols;
}
static void radix_sort(int dataArray[], const int arraySize)
{
	const int radix = 10;
	int* baseArrays[radix] = { nullptr };
	for (int i = 0; i < radix; i++)
	{
		baseArrays[i] = new int[arraySize+1]; //first col is count
		fill(baseArrays[i], baseArrays[i] + arraySize + 1, 0); //init
	}

	int maxVal = dataArray[0];
	for (int i = 1; i < arraySize; i++)
	{
		if (maxVal < dataArray[i])
		{
			maxVal = dataArray[i];
		}
	}
	int maxCol = getCols(maxVal);
	for (int col = 0; col < maxCol;col++)
	{
		//
		for (int i = 0; i < arraySize;i++)
		{
			const int radix_base = getColNum(dataArray[i], col);
			const int count = baseArrays[radix_base][0];
			baseArrays[radix_base][count + 1] = dataArray[i];
			baseArrays[radix_base][0]++;
		}

		//collect
		int index = 0;
		for (int i = 0; i < radix;i++)
		{
			const int count = baseArrays[i][0];
			for (int j = 0; j < count;j++)
			{
				dataArray[index++] = baseArrays[i][j+1];
			}
			baseArrays[i][0] = 0; //reset
		}
	}


	for (int i = 0; i < radix; i++)
	{
		delete[] baseArrays[i];
	}
}

void test_p101_radix_sort()
{
	int dataArray[] = { 23, 45, 1, 34, 5, 0, 4, 23, 4 };
	const int arraySize = sizeof(dataArray) / sizeof(int);

	cout << "before radix sort : ";
	copy(dataArray, dataArray + arraySize, ostream_iterator<int>(cout, " ")); cout << endl;
	radix_sort(dataArray, arraySize);
	cout << "after radix sort : ";
	copy(dataArray, dataArray + arraySize, ostream_iterator<int>(cout, " ")); cout << endl;
}