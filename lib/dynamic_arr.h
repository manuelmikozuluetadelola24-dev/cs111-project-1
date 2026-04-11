
#ifndef __DYNAMIC_ARR_H_

#define __DYNAMIC_ARR_H_

#endif

// Contains the definition of the dynamic array
// I didn't feel like adding functions for manipulating
// the array.
// Adjust the cap and items directly when updating array size or adding contents
typedef struct DynamicUlongArr
{
	unsigned long int* arr;
	size_t items;
	size_t cap;
} DynamicUlongArr;
