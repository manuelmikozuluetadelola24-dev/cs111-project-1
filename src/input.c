
#include <stdio.h>
#include <time.h>

// TODO: change to call seedXoshiro and next() from xoshiro instead
void inputRandom(unsigned long int* arr, unsigned long int *end)
{
	int size = end - arr;
	srand(time());
	for( int = 0; i < size; i++)
	{
		*(arr+i) = rand();
	}
}

// TODO: implement function
// PROPOSED IMPLEMENTATION:
// get input with fgets() and restrict input to digits 0-9
// convert resulting string to unsigned long using strtoul() from stdlib.h
void inputUser(int* arr);
{
	char* 
	puts("\ninput initial value of x:");
	fgets(
