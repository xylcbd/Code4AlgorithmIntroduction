#include <iostream>
#include <cassert>
#include <algorithm>
using namespace std;

static void insert_sort(int data[], const int size)
{
	if (nullptr == data || size <= 1)
	{
		return;
	}
	for (int i = 1; i < size;i++)
	{
		int key = data[i];
		int insertPos = i - 1;
		while (insertPos >= 0 && data[insertPos] > key)
		{
			data[insertPos + 1] = data[insertPos];
			insertPos--;
		}
		data[insertPos + 1] = key;
	}
}

void test_p10_insert_sort()
{
	int data[] = { 23, 53, 2, 1, -534, 2354, 0, 22, 94, 646 };
	const int size = sizeof(data) / sizeof(int);

	cout<<"before insert sort : ";
	for (auto v : data)
	{
		cout << v << " ";
	}
	cout << endl;

	insert_sort(data, size);

	cout<< "after insert sort : ";
	for (auto v : data)
	{
		cout << v << " ";
	}
	cout << endl;
}