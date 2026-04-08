
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <dynamic_arr.h>
#include <xoshiro256plusplus.h>

// TODO: change to call seedXoshiro and next() from xoshiro instead
void inputRandom(DynamicUlongArr *input_arr)
{
	seedXoshiro(time(NULL));
	for( size_t i = 0; i < input_arr->cap; i++)
	{
		*(input_arr->arr+i) = (unsigned long) nextXoshiro();
	}
}

// Clean whitespaces and newline
void cleanInput(char* input_buffer)
{
	for(int i = 0; *(input_buffer+i) != '\0' ; i++)
	{
		if(*(input_buffer+i) == ' ' || *(input_buffer+i) == '\n')
		{
			for(int j = i; *(input_buffer+j) != '\0'; j++)
			{
				*(input_buffer+j) = *(input_buffer+j+1);
			}
		}
	}
}
// TODO: implement function
// PROPOSED IMPLEMENTATION:
// get input with fgets() and restrict input to digits 0-9
// convert resulting string to unsigned long using strtoul() from stdlib.h
void inputUser(DynamicUlongArr *input_arr)
{
	const int buffer_length = 24;
	char* input_buffer = malloc(sizeof(char) * buffer_length);
	
	// 1 is true and 0 is false
	enum valid { FALSE = 0, TRUE = 1 };
	int input_valid = FALSE;
	do
	{
		puts("\ninput initial value of x: ");
		fgets(input_buffer, buffer_length-1, stdin);

		cleanInput(input_buffer);

		for(int i = 0; *(input_buffer+i) != '\0' ; i++)
		{
			if(*(input_buffer+i) < '0' || *(input_buffer+i) > '9')
			{
				input_valid = FALSE;
			}
			else
			{
				input_valid = TRUE;
			}
		}
		
	}
	while(!input_valid);

	unsigned long sequence_start = strtoul(input_buffer, &input_buffer, 10);

	for( size_t i = 0; i < input_arr->cap; i++ )
	{
		*(input_arr->arr+i) = sequence_start+i;
		input_arr->items++;
	}
	
	free(input_buffer);
}
