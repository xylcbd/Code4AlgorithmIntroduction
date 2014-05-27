#include <iostream>
#include <cassert>
#include <algorithm>
#include <vector>
#include <iterator>
using namespace std;

static void merge(int data[], const int left, const int separate, const int right)
{
	const int leftSize = separate - left + 1;
	const int rightSize = right - separate;
	int* base = data + left;
	vector<int> leftArray(leftSize);
	vector<int> rightArray(rightSize);
	copy(base, base + leftSize, leftArray.begin());
	copy(base + leftSize, base + leftSize + rightSize, rightArray.begin());

	int leftPos = 0;
	int rightPos = 0;
	int pos = left;
	while (leftPos < leftSize && rightPos < rightSize && pos <= right)
	{
		if (leftArray[leftPos] < rightArray[rightPos])
		{
			data[pos] = leftArray[leftPos++];
		}
		else
		{
			data[pos] = rightArray[rightPos++];
		}
		pos++;
	}
	while (leftPos < leftSize)
	{
		data[pos++] = leftArray[leftPos++];
	}
	while (rightPos < rightSize)
	{
		data[pos++] = rightArray[rightPos++];
	}
	//copy(data, data + leftSize + rightSize, ostream_iterator<int>(cout, " ")); cout << endl;
}
static void merge_sort_imp(int data[], const int left, const int right)
{
	if (left < right)
	{
		const int separate = (right + left) / 2;
		merge_sort_imp(data, left, separate);
		merge_sort_imp(data, separate + 1, right);
		merge(data, left, separate, right);
	}
}
static void merge_sort(int data[], const int size)
{
	if (nullptr == data || size <= 1)
	{
		return;
	}
	merge_sort_imp(data, 0, size - 1);
}

void test_p17_merge_sort()
{
	int data[] = { 23, 53, 2, 1, -534, 2354, 0, 22, 94, 646 };
	const int size = sizeof(data) / sizeof(int);

	cout << "before merge sort : ";
	for (auto v : data)
	{
		cout << v << " ";
	}
	cout << endl;

	merge_sort(data, size);

	cout << "after merge sort : ";
	for (auto v : data)
	{
		cout << v << " ";
	}
	cout << endl;
}