
#include <xoshiro256plusplus.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <dynamic_arr.h>
#include <input.h>
#include <sort.h>
#include <analysis.h>

// NOTE: DO NOT USE initArr ON AN ARRAY CREATED BY copyArr
// 	 AND VICE VERSA IT WILL CREATE A MEMORY LEAK!!
// use initArr for initializing the input array
DynamicUlongArr *initArr(size_t size)
{
	DynamicUlongArr *new_arr = malloc(sizeof(DynamicUlongArr));
	new_arr->cap = size;
	new_arr->items = 0;
	new_arr->arr = malloc(sizeof(unsigned long int) * size);
	return new_arr;
}

// Use copyArr when making a copy of input array
DynamicUlongArr *copyArr(DynamicUlongArr *input_arr)
{
	DynamicUlongArr *arr_copy = malloc(sizeof(DynamicUlongArr));
	arr_copy->cap = input_arr->cap;
	arr_copy->items = input_arr->items;
	arr_copy->arr = malloc(sizeof(unsigned long int) * input_arr->cap);
	for(size_t i = 0; i < input_arr->items; i++)
	{
		arr_copy->arr[i] = input_arr->arr[i];
	}
	return arr_copy;
}

// NOTE: NOT FINISHED
// TODO: PRINT RUNTIME OF EACH SORTING ALGORITHM TO FILE
void outputToFile(DynamicUlongArr *input_arr, DynamicUlongArr *arr_copy, double *runtimes)
{
	FILE *output = fopen("output.txt", "w");

	fprintf(output, "\n ***INPUT ARRAY*** \n\n");
	for( size_t i = 0 ; i < input_arr->items ; i++)
	{
		fprintf(output, "%lu\n", input_arr->arr[i]);
	}
	
	fprintf(output, "\n ***SORTED ARRAY*** \n\n");
	for( size_t i = 0 ; i < input_arr->items ; i++)
	{
		fprintf(output, "%lu\n", arr_copy->arr[i]);
	}

	fprintf(output, "\n\nSORTED IN ASCENDING ORDER: %d\n\n", validateSort(arr_copy));
	//fprintf(output, "TIME: %f seconds\n", measureCpuTime(quickSort, arr_copy->arr, NULL, NULL));
	fprintf(output, "\nRUNTIME OF EACH SORTING ALGORITHM\n\n");
	fprintf(output, "\nSelection Sort:%5f\n", runtimes[0]);
	fprintf(output, "Bubble Sort:%5f\n", runtimes[1]);
	fprintf(output, "Insertion Sort:%5f\n", runtimes[2]);
	fprintf(output, "Merge Sort:%5f\n", runtimes[3]);
	fprintf(output, "Quick Sort:%5f\n", runtimes[4]);
	fprintf(output, "Heap Sort:%5f\n", runtimes[5]);
	fclose(output);
}

int main()
{
	DynamicUlongArr *input_arr = initArr(1000);
	
	puts("Select an option");
	puts("(1) generate array of random values");
	puts("(2) select a value and populate array with sequentially increasing value");
	char* selection = malloc(sizeof(char)*3);
	fgets(selection, 3, stdin);
	enum valid_select {FALSE = 0, TRUE = 1};
	int is_valid = FALSE;
	do
	{
		
		if(*selection == '1')
		{
			inputRandom(input_arr);
			is_valid = TRUE;
		}
		else if(*selection == '2')
		{
			inputUser(input_arr);
			is_valid = TRUE;
		}
		else
		{
			puts("invalid option");
			puts("input valid option");
			is_valid = FALSE;
			fgets(selection, 3, stdin);
		}

	} while(!is_valid);
	free(selection);

	// Code past this comment may be subject to change
	DynamicUlongArr *arr_copy_1 = copyArr(input_arr);
	DynamicUlongArr *arr_copy_2 = copyArr(input_arr);
	DynamicUlongArr *arr_copy_3 = copyArr(input_arr);
	DynamicUlongArr *arr_copy_4 = copyArr(input_arr);
	DynamicUlongArr *arr_copy_5 = copyArr(input_arr);
	DynamicUlongArr *arr_copy_6 = copyArr(input_arr);

	double sort_runtimes[6];
	sort_runtimes[0] = measureCpuTime(&selectionSort, arr_copy_1);
	sort_runtimes[1] = measureCpuTime(&bubbleSort, arr_copy_2);
	sort_runtimes[2] = measureCpuTime(&insertionSort, arr_copy_3);
	sort_runtimes[3] = measureCpuTime(&mergeSort, arr_copy_4);
	sort_runtimes[4] = measureCpuTime(&quickSort, arr_copy_5);
	sort_runtimes[5] = measureCpuTime(&heapSort, arr_copy_6);

	outputToFile(input_arr, arr_copy_6, sort_runtimes);

	free (input_arr->arr);
	free(input_arr);
	free (arr_copy_1->arr);
	free(arr_copy_1);
	free(arr_copy_2->arr);
	free(arr_copy_2);
	free(arr_copy_3->arr);
	free(arr_copy_3);
	free(arr_copy_4->arr);
	free(arr_copy_4);
	free(arr_copy_5->arr);
	free(arr_copy_5);
	free(arr_copy_6->arr);
	free(arr_copy_6);
	return 0;
}
