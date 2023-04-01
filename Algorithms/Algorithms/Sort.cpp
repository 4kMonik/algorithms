#include "Sort.h"

void algorithms::heap_sort(int * arr, size_t sizeOfArray)
{
	heap sortHeap(arr, sizeOfArray);
	for (int i = sizeOfArray - 1; i >= 0; i--)
		arr[i] = sortHeap.extract();
}
