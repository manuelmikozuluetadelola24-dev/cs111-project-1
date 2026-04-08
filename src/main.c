
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
	char selection = getchar();
	switch(selection)
	{
		case '1': 
			inputRandom(input_arr);
			break;
		case '2':
			inputUser(input_arr);
			break;
		default:
			puts("invalid option");
			break;
	}

	for(size_t i = 0; i < input_arr->cap; i++)
	{
		printf("%lu\n", *(input_arr->arr+i));
	}

	return 0;
}
