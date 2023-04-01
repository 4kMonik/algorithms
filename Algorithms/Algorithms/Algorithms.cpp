#include <iostream>

#include "Sort.h"

using namespace std;
using namespace algorithms;

int main()
{
	int N = 10;
	int* A = new int[N]{7, 4, 1, 8, 2, 3, 9, 0, 5, 6};
	heap_sort(A, N);
	for (int i = 0; i < N; i++)
		cout << A[i] << " ";

	return 0;
}
