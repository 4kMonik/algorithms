#include <iostream>

#include "Sort.h"
#include "FindUnion.h"

using namespace std;
using namespace algorithms;

int main()
{
	cout << boolalpha;
	findUnion uf(10);
	// 1-2-5-6-7 3-8-9 4
	uf.unionSet(1, 2);
	uf.unionSet(2, 5);
	uf.unionSet(5, 6);
	uf.unionSet(6, 7);
	uf.unionSet(3, 8);
	uf.unionSet(8, 9);
	cout << uf.connected(1, 5) << endl;  // true
	cout << uf.connected(5, 7) << endl;  // true
	cout << uf.connected(4, 9) << endl;  // false
	// 1-2-5-6-7 3-8-9-4
	uf.unionSet(9, 4);
	cout << uf.connected(4, 9) << endl;  // true


	

	return 0;
}
