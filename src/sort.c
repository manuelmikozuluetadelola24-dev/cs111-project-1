
#include <stdlib.h>
#include <dynamic_arr.h>

// Use this to check if an array is properly sorted in ascending order.
int validateSort(DynamicUlongArr *arr_copy)
{
	enum sort_valid { FALSE = 0, TRUE = 1 };
	int is_sorted = TRUE;

	for(size_t i = 0; i < arr_copy->items-1; i++)
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
	for(size_t i = 0; i < arr_copy->items-1; i++)
	{
		size_t min = i;
	
		for( size_t j = i+1; j < arr_copy->items; j++)
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

// DONE
void bubbleSort(DynamicUlongArr *arr_copy)
{
	size_t n = arr_copy->items;
	for(size_t i = 0; i < n-1; i++)
	{
		for(size_t j = 0; j < (n-i)-1; j++)
		{
			if(arr_copy->arr[j] > arr_copy->arr[j+1])
			{
				unsigned long int temp = arr_copy->arr[j];
				arr_copy->arr[j] = arr_copy->arr[j+1];
				arr_copy->arr[j+1] = temp;
			}
		}
	}
}

// DONE
void insertionSort(DynamicUlongArr *arr_copy)
{
	for(size_t i = 1; i < arr_copy->cap; i++)
	{
		unsigned long int key = arr_copy->arr[i];
		size_t j = i-1;
		while( j >= 0 && arr_copy->arr[j] > key)
		{
			arr_copy->arr[j+1] = arr_copy->arr[j];
			j--;
		}
		arr_copy->arr[j+1] = key;
	}
}
