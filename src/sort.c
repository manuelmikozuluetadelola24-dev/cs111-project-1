
#include <stdlib.h>
#include <dynamic_arr.h>

// Use this to check if an array is properly sorted in ascending order.
// note: will not work for heap sort
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

// heapSort FUNCTION
void maxHeapify(DynamicUlongArr *arr_copy, size_t root, size_t length)
{
	size_t l_node = root * 2;
	size_t r_node = (root * 2) + 1;

	size_t max;
	if( l_node <= length && arr_copy->arr[l_node-1] > arr_copy->arr[root-1])
	{
		max = l_node;
	}
	else
	{
		max = root;
	}
	
	if( r_node <= length && arr_copy->arr[r_node-1] > arr_copy->arr[max-1])
	{
		max = r_node;
	}

	if( max != root )
	{
		unsigned long int temp = arr_copy->arr[root-1];
		arr_copy->arr[root-1] = arr_copy->arr[max-1];
		arr_copy->arr[max-1] = temp;
		maxHeapify(arr_copy, max, length);
	}
}

// heapSort FUNCTION
void buildMaxHeap(DynamicUlongArr *arr_copy)
{
	size_t n = arr_copy->items;
	for( size_t i = (n/2); i > 0 ; i-- )
	{
		maxHeapify(arr_copy, i, n);
	}
}

// DONE
void heapSort(DynamicUlongArr *arr_copy)
{
	buildMaxHeap(arr_copy);
	for( size_t i = (arr_copy->items); i > 1 ; i --)
	{
		unsigned long int temp = arr_copy->arr[0];
		arr_copy->arr[0] = arr_copy->arr[i-1];
		arr_copy->arr[i-1] = temp;
		maxHeapify(arr_copy, 1, i -1);
	}
}
