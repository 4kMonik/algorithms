#include "FindUnion.h"


algorithms::findUnion::findUnion(int n) : root(n), rank(n), setCount(n)
{
	for (int i = 0; i < n; i++)
	{
		root[i] = i;
		rank[i] = 1;
	}
}

algorithms::findUnion::findUnion(vector<vector<int>>& graph): root(graph.size()), rank(graph.size()), setCount(graph.size())
{
	for (int i = 0; i < graph.size(); i++)
	{
		root[i] = i;
		rank[i] = 1;
	}
	for (int i = 0; i < graph.size(); i++)
	{
		for (int j = 0; j < graph.size(); j++)
		{
			if (graph[i][j])
				unionSet(i, j);
		}

	}
}

int algorithms::findUnion::find(int elem)
{
	if (elem == root[elem])
		return elem;
	return root[elem] = find(root[elem]);
}

void algorithms::findUnion::unionSet(int elem1, int elem2)
{
	int root1 = find(elem1);
	int root2 = find(elem2);
	if (root1 != root2)
	{
		if (rank[root1] > rank[root2])
			root[root2] = root1;
		else if (rank[root1] < rank[root2])
			root[root1] = root2;
		else
		{
			root[root2] = root1;
			rank[root1]++;
		}
		setCount--;
	}
}

bool algorithms::findUnion::connected(int elem1, int elem2)
{
	return find(elem1) == find(elem2);
}

int algorithms::findUnion::countSets()
{
	return setCount;
}


