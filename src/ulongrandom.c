
#include <xoshiro256plusplus.h>

void seedUlongRand()
{
	seedXoshiro();
}

unsigned long int randUlong()
{
	unsigned long int new_rand = (unsigned long int)nextXoshiro();
	return new_rand;
}
