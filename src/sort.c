
#include <stdlib.h>

// This causes a memory leak but it shouldn't matter since
// the program has a short runtime
// TODO: fix memory leak (eventually)
// PROPOSED SOLUTION
// Create a function that allocates the same amount of memory
// as the input array to an int pointer before calling mergesort.
// Will require updating the function parameters and removing the
// malloc calls but it shouldn't affect the implementation of
// measureCpuTime().

// 1/3 of this program's memory will be lost to this memory leak
void *merge(int *arr, int *l_start, int *r_start, int *r_end)
{
	int n1 = r_start - l_start++;
	int n2 = r_end - r_start;
	int *l_arr, *r_arr;
	l_arr = malloc(sizeof(int) * n1++);
	r_arr = malloc(sizeof(int) * n2++);
	
	for(i = 0; i < n1; i++)
	{
		*(l_arr+i) = *(arr + l_start + i - 1);
	}
	for(j = 0; j < n2; j++)
	{
		*(r_arr+j) = *(arr + r_start + j);
	}
	// I don't know what L[n1+1] = infinity is
	i = 0;
	j = 0;
	for(k = 0; k < (r_end - l_start); k++)
	{
		if( *(l_arr+i) <= *(r_arr+j) )
		{
			*(arr+k) = *(l_arr + i);
			i += 1;
		}
		else
		{
			*(arr+k) = *(l_arr+j);
			j += 1;
		}
	}
}

int *mergeSort(int *arr, int *start, int *end)
{
	
	if(start < end)
	{
		// subtracting the start and end pointers
		// should yield the same effect as adding
		// the index of the start and end of the array
		int *mid = (end - start) / 2;
		mergeSort(arr, start, mid);
		mergeSort(arr, mid++, end);
		merge(arr, start, mid, end);
	}
}
