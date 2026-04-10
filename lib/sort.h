
#ifndef __SORT_H_

#define __SORT_H_

#endif

int validateSort(DynamicUlongArr *arr_copy);

void selectionSort(DynamicUlongArr *arr_copy);

void bubbleSort(DynamicUlongArr *arr_copy);

void insertionSort(DynamicUlongArr *arr_copy);

void maxHeapify(DynamicUlongArr *arr_copy, size_t root, size_t length);

void buildMaxHeap(DynamicUlongArr *arr_copy);

void heapSort(DynamicUlongArr *arr_copy);
