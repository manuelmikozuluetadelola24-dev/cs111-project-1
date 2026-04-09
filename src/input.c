
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <dynamic_arr.h>
#include <xoshiro256plusplus.h>

// Populates array with randomly generated 64 bit values from nextXoshiro()
// and increment items field in the array.
void inputRandom(DynamicUlongArr *input_arr)
{
	seedXoshiro(time(NULL));
	for( size_t i = 0; i < input_arr->cap; i++)
	{
		input_arr->arr[i] = (unsigned long) nextXoshiro();
		input_arr->items++;
	}
}

// Clean whitespaces and newline
void cleanInput(char* input_buffer)
{
	for(int i = 0; input_buffer[i] != '\0' ; i++)
	{
		if(input_buffer[i] == ' ' || input_buffer[i] == '\n')
		{
			for(int j = i; input_buffer[j] != '\0'; j++)
			{
				input_buffer[j] = input_buffer[j+1];
			}
		}
	}
}

// gets input with fgets() and restrict input to digits 0-9
// convert resulting string to unsigned long using strtoul()
void inputUser(DynamicUlongArr *input_arr)
{
	const int buffer_length = 24;
	char* input_buffer = malloc(sizeof(char) * buffer_length);
	
	// 1 is true and 0 is false
	enum valid { FALSE = 0, TRUE = 1 };
	int input_valid = FALSE;
	unsigned long sequence_start = 0;
	do
	{
		puts("input initial value of x: ");
		fgets(input_buffer, buffer_length-1, stdin);

		cleanInput(input_buffer);

		char* invalid_char;
		
		// strtoul converts every valid digit in a string to unsigned
		// long ignoring whitespace, cleanInput may be redundant.
		sequence_start = strtoul(input_buffer, &invalid_char, 10);
		
		if(*(invalid_char) == '\0')
		{
			input_valid = TRUE;
		}
		else
		{
			puts("invalid value, only input digits 0-9");
			input_valid = FALSE;
		}
	}
	while(!input_valid);
	

	for( size_t i = 0; i < input_arr->cap; i++ )
	{
		input_arr->arr[i] = sequence_start+i;
		input_arr->items++;
	}
	
	free(input_buffer);
}
