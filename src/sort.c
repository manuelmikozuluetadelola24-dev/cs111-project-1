
#include <stdlib.h>
#include <dynamic_arr.h>

// Use this to check if an array is properly sorted in ascending order.
int validateSort(DynamicUlongArr *arr_copy)
{
	enum sort_valid { FALSE = 0, TRUE = 1 };
	int is_sorted = TRUE;

	for(size_t i = 0; i < arr_copy->cap-1; i++)
	{
		if(arr_copy->arr[i] > arr_copy->arr[i+1])
		{
			is_sorted = false;
		}
	}

	return is_sorted;
}

// DONE
void selectionSort(DynamicUlongArr *arr_copy)
{
	for(size_t i = 0; i < arr_copy->cap-1; i++)
	{
		size_t min = i;
	
		for( size_t j = i+1; j < arr_copy->cap; j++)
		{
			if(arr_copy->arr[j] < arr_copy->arr[min])
			{
				min = j;
			}
		}
		unsigned long int temp = arr_copy->arr[i];
		arr_copy->arr[i] = arr_copy->arr[min];
		arr_copy->arr[min] = temp;
	}
}
