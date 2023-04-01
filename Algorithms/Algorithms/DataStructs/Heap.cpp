#include "Heap.h"

int algorithms::heap::getParent(int i)
{
	return (i - 1) >> 1;
}

int algorithms::heap::getLeftChild(int i)
{
	return (i << 1) + 1;
}

int algorithms::heap::getRightChild(int i)
{
	return (i << 1)+ 2;
}

int algorithms::heap::childrenComp(int i)
{
	int L = getLeftChild(i);
	if (L + 1 == maxI) return L;
	int R = L + 1;
	if (arr[L] > arr[R] /*compFunc*/ ) return L;
	return R;
}



algorithms::heap::heap():maxI(0)
{
	arr = new int[200000]{};
}

algorithms::heap::heap(size_t arrSize)
{
	arr = new int[arrSize]{};
}

algorithms::heap::heap(int *a, size_t size_a):arr(a), maxI(size_a) // heapify
{
	for (int k = size_a / 2 - 1; k >= 0; k--)
	{
		int n = arr[k];
		int i = k;
		if (i >= maxI / 2)
			continue;
		int j = childrenComp(i);
		while (i <= maxI && j <= maxI && arr[i] < arr[j]/*compFunc*/)
		{
			arr[i] = arr[j];
			arr[j] = n;
			i = j;
			if (i >= maxI / 2)
				continue;
			j = childrenComp(i);
		}


	}
}

void algorithms::heap::insert(int n)
{
	int i = maxI++;
	arr[i] = n;
	int j = getParent(i);
	while (n > arr[j]/*compFunc*/)
	{		
		arr[i] = arr[j];
		arr[j] = n;
		i = j;
		j = getParent(i);
	}
}

int algorithms::heap::extract()
{
	int value = arr[0];
	int replaceVal = arr[--maxI];
	arr[0] = replaceVal;
	int i = 0;
	if (i >= maxI / 2)
		return value;
	int j = childrenComp(i);
	while (replaceVal < arr[j]/*compFunc*/)
	{
		arr[i] = arr[j];
		arr[j] = replaceVal;
		i = j;
		if (i >= maxI / 2)
			return value;
		j = childrenComp(i);
	}
	return value;
}

