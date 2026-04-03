
#ifndef __DYNAMIC_ARR_H_

#define __DYNAMIC_ARR_H_

#endif

typedef struct DynamicUlongArr
{
	unsigned long int* arr;
	size_t items;
	size_t cap;
} DynamicUlongArr

void initDynamicArr(DynamicUlongArr* dynamic_arr, size_t init_size);

void shrink(DynamicUlongArr* dynamic_arr);

void expand(DynamicUlongArr* dynamic_arr);

void updateSize(DynamicUlongArr* dynamic_arr);
