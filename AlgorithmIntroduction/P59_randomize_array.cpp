#include <iostream>
#include <cassert>
#include <algorithm>
#include <vector>
#include <functional>
#include <ctime>
#include <random>
using namespace std;

static int random(int lower, int uper)
{
	assert(lower <= uper);
	if (lower == uper)
	{
		return lower;
	}
	random_device rd;
	return lower + rd() % (uper - lower);
}
static void randomize_array_by_sort(int data[], const int size)
{
	if (nullptr == data || size <= 1)
	{
		return;
	}
	vector<pair<int, int>> prioritys;
	int uper = size*size*size;
	for (int i = 0; i < size;i++)
	{
		prioritys.push_back(pair<int, int>(random(0,uper), data[i]));
	}
	sort(prioritys.begin(), prioritys.end());

	for (int i = 0; i < size;i++)
	{
		data[i] = prioritys[i].second;
	}
}
static void randomize_array_inplaced(int data[], const int size)
{
	if (nullptr == data || size <= 1)
	{
		return;
	}
	for (int i = 0; i < size-1;i++)
	{
		swap(data[i], data[random(i+1, size - 1)]);
	}
}

void test_p59_randomize_array()
{
	int data[] = { 23, 53, 2, 1, -534, 2354, 0, 22, 94, 646 };
	const int size = sizeof(data) / sizeof(int);

	//randomize array by sort test
	cout << "before randomize by sort : ";
	for (auto v : data)
	{
		cout << v << " ";
	}
	cout << endl;

	randomize_array_by_sort(data, size);

	cout << "after randomize by sort : ";
	for (auto v : data)
	{
		cout << v << " ";
	}
	cout << endl;
	
	//randomize array inplaced test
	cout << "before randomize inplaced : ";
	for (auto v : data)
	{
		cout << v << " ";
	}
	cout << endl;

	randomize_array_inplaced(data, size);

	cout << "after randomize inplaced : ";
	for (auto v : data)
	{
		cout << v << " ";
	}
	cout << endl;
}