#include <iostream>

#include "Sort.h"
#include "FindUnion.h"

using namespace std;
using namespace algorithms;

int main()
{
	findUnion uni(9);
	uni.unionSet(0, 1);
	uni.unionSet(1, 2);
	uni.unionSet(1, 3);
	uni.unionSet(4, 5);
	uni.unionSet(4, 6);
	uni.unionSet(1, 5);
	cout << uni.connected(3, 6);


	

	return 0;
}
