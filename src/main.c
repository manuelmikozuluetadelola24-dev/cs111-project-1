
#include <xoshiro256plusplus.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <dynamic_arr.h>
#include <input.h>

DynamicUlongArr *initArr(size_t size)
{
	DynamicUlongArr *new_arr = malloc(sizeof(DynamicUlongArr));
	new_arr->cap = size;
	new_arr->arr = malloc(sizeof(unsigned long int) * size);
	return new_arr;
}

int main()
{
	DynamicUlongArr *input_arr = initArr(100);
	
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

	for(size_t i = 0; i < input_arr->cap; i++)
	{
		printf("%lu\n", *(input_arr->arr+i));
	}

	return 0;
}
