#pragma once
#include <iostream>

namespace algorithms
{
	class heap
	{
		int *arr;
		int getParent(int i);
		int getLeftChild(int i);
		int getRightChild(int i);
		int childrenComp(int);
		int maxI;
	public:
		heap();
		heap(size_t arrSize);
		heap(int *a, size_t size_a); // heapify
		void insert(int);
		int extract();
	};
}