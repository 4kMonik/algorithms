#pragma once
#include <utility>
#include <iostream>

using namespace std;

namespace algorithms
{
	class deque
	{
		const int blockSize = 10;
		int **blocksArr;
		int arrSize;
		int deque_size;
		pair<int, int> _front;
		pair<int, int> _back;
		void expandblocksArr();
		void boundryCheck(pair<int, int>&);
	public:
		deque();
		void push_front(int);
		void push_back(int);
		int pop_front();
		int pop_back();
		int front();
		int back();
		int size();
		void clear();
		int getArrSize() { return arrSize; };
	};

}