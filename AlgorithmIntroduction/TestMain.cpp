#include <iostream>
using namespace std;

typedef struct _TESTCASE_
{
	void(*const fnTest)();
	const char* description;
}TESTCASE;

//P10_insert_sort
extern void test_p10_insert_sort();
//P17_merge_sort
extern void test_p17_merge_sort();
//P23_bubble_sort
extern void test_p23_bubble_sort();
//P59_randomize_array
extern void test_p59_randomize_array();
//P74_heap_sort
extern void test_p74_heap_sort();
//P85_quick_sort
extern void test_p85_quick_sort();
//P99_counting_sort
extern void test_p99_counting_sort();
//P101_radix_sort
extern void test_p101_radix_sort();
//P102_bucket_sort
extern void test_p102_bucket_sort();
//P108_min_max
extern void test_p108_min_max();

const TESTCASE testCases[] =
{
	{ test_p10_insert_sort, "P10_insert_sort" },
	{ test_p17_merge_sort, "P17_merge_sort" },
	{ test_p23_bubble_sort, "P23_bubble_sort" },
	{ test_p59_randomize_array, "P59_randomize_array" },
	{ test_p74_heap_sort, "P74_heap_sort" },
	{ test_p85_quick_sort, "P85_quick_sort"},
	{ test_p99_counting_sort, "P99_counting_sort" },
	{ test_p101_radix_sort, "P101_radix_sort" },
	{ test_p102_bucket_sort, "P102_bucket_sort"},
	{ test_p108_min_max, "P108_min_max" }
};

int main(int argc, char* argv[])
{
	for (auto v : testCases)
	{
		cout << "------------------------------" << endl;
		cout << "=> test case start ..." << endl;
		cout << "=> "<<v.description << endl;
		v.fnTest();
		cout << "=> test case done ..." << endl;
		cout << "------------------------------" << endl<<endl;
	}
	return 0;
}