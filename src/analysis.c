
#include <time.h>

// p and r are only used for recursive sorting functions

// implementation is bound to change
double measureCpuTime(void sort(int *arr, int *p, int *r), int *input_arr, int *x, int *y)
{
	clock_t start, end;
	double cpu_time_used;
	
	start = clock();
	sort(input_arr, x, y);
	end = clock();
	cpu_time_used = ((double)(end-start)) / CLOCKS_PER_SEC;
	return cpu_time_used;
}
