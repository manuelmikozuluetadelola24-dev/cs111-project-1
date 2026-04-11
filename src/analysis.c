
#include <time.h>
#include <dynamic_arr.h>

// implementation is bound to change
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
