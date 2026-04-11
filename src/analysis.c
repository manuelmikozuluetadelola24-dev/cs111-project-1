
#include <time.h>
#include <dynamic_arr.h>

// Takes a function pointer of a sorting function, gets a value from clock
// before running the function, then calling clock again to get the cpu time
// after sorting
double measureCpuTime(void sort(DynamicUlongArr *copy_arr), DynamicUlongArr *arr_to_sort)
{
	clock_t start, end;
	double cpu_time_used;
	
	start = clock();
	sort(arr_to_sort);
	end = clock();
	cpu_time_used = ((double)(end-start)) / CLOCKS_PER_SEC;
	return cpu_time_used;
}
