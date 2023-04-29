#pragma once

#include <vector>

using namespace std;

namespace algorithms
{
	class findUnion
	{
		vector<int> root;
		vector<int> rank;
		int setCount;
	public:
		findUnion(int n);
		findUnion(vector<vector<int>> &graph);
		int find(int elem);
		void unionSet(int elem1, int elem2);
		bool connected(int elem1, int elem2);
		int countSets();
	};
}