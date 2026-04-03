
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// this function uses a small library called srandq by
// Alessandro Cudazo who goes by alessandrocuda in
// github.

// repository link: https://github.com/alessandrocuda/randq
void inputRandom(unsigned long int* arr, unsigned long int *end)
{
	int size = end - arr;
	srand(time());
	for( int = 0; i < size; i++)
	{
		*(arr+i) = rand();
	}
}

void inputUser(int* arr);
{
	char* 
	puts("\ninput initial value of x:");
	fgets(
