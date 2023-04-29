#include "FindUnion.h"


algorithms::findUnion::findUnion(int n) : root(n), rank(n)
{
	for (int i = 0; i < n; i++)
	{
		root[i] = i;
		rank[i] = 1;
	}
}

int algorithms::findUnion::find(int elem)
{
	while (elem != root[elem])
		elem = root[elem];
	return elem;
}

void algorithms::findUnion::unionSet(int elem1, int elem2)
{
	int root1 = find(elem1);
	int root2 = find(elem2);
	if (root1 != root2)
		root[root2] = root1;
}

bool algorithms::findUnion::connected(int elem1, int elem2)
{
	return find(elem1) == find(elem2);
}


