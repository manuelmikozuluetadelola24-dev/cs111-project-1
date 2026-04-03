
#include <xoshiro256plusplus.h>
#include <stdio.h>
#include <limits.h>
#include <time.h>

// TODO: remove limits.h and random value tests

int main()
{
	seedXoshiro(time(NULL));
	unsigned long int random_ulong = 0;
	unsigned long int max = 0, min = ULONG_MAX;
	for(int i = 0; i < 256; i++)
	{
		random_ulong = nextXoshiro();
		if(random_ulong > max)
		{
			max = random_ulong;
		}
			
		if(random_ulong < min)
		{
			min = random_ulong;
		}
	}
	
	printf("max: %lu\n", max);
	printf("min: %lu\n", min);

	return 0;
}
