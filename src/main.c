
#include <xoshiro256plusplus.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <dynamic_arr.h>
#include <input.h>
#include <sort.h>

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
void outputToFile(DynamicUlongArr *input_arr, DynamicUlongArr *arr_copy)
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
	fprintf(output, "SORTING ALGORITHM USED: MERGE SORT"); //manual check, change dep on sort algo
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
	DynamicUlongArr *arr_copy = copyArr(input_arr);

	mergeSort(arr_copy);
	outputToFile(input_arr, arr_copy);

	free (input_arr->arr);
	free(input_arr);
	free (arr_copy->arr);
	free(arr_copy);
	return 0;
}
