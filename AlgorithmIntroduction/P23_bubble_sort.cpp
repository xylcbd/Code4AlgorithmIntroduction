#include <iostream>
#include <cassert>
#include <algorithm>
using namespace std;

static void bubble_sort(int data[], const int size)
{
	if (nullptr == data || size <= 1)
	{
		return;
	}
	for (int i = 0; i < size; i++)
	{
		for (int j = size - 1; j > i;j--)
		{
			if (data[j-1] > data[j])
			{
				swap(data[j - 1], data[j]);
			}
		}
	}
}

void test_p23_bubble_sort()
{
	int data[] = { 23, 53, 2, 1, -534, 2354, 0, 22, 94, 646 };
	const int size = sizeof(data) / sizeof(int);

	cout << "before bubble sort : ";
	for (auto v : data)
	{
		cout << v << " ";
	}
	cout << endl;

	bubble_sort(data, size);

	cout << "after bubble sort : ";
	for (auto v : data)
	{
		cout << v << " ";
	}
	cout << endl;
}