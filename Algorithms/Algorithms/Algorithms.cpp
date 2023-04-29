#include <iostream>

#include "Sort.h"
#include "FindUnion.h"

using namespace std;
using namespace algorithms;

int main()
{
	cout << boolalpha;
	vector<vector<int>> isConnected = {{1,0,0}, {0,1,0}, {0,0,1}};
	findUnion uf(isConnected);
	cout << uf.countSets() << endl;

	

	return 0;
}
