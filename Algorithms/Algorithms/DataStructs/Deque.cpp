#include "Deque.h"

algorithms::deque::deque() : arrSize(10), deque_size(0)
{
	blocksArr = new int*[arrSize] {};
	for (int i = 0; i < 10; i++)
	{
		blocksArr[i] = new int[blockSize] {};
	}
	_front = make_pair(4, 5);
	_back = _front;
}

void algorithms::deque::push_front(int n)
{
	if (deque_size == 0)
	{
		blocksArr[_front.first][_front.second] = n;
		deque_size++;
		return;
	}
	_front.second--;
	boundryCheck(_front);

	blocksArr[_front.first][_front.second] = n;
	deque_size++;
}

void algorithms::deque::push_back(int n)
{
	if (deque_size == 0)
	{
		blocksArr[_back.first][_back.second] = n;
		deque_size++;
		return;
	}
	_back.second++;
	boundryCheck(_back);

	blocksArr[_back.first][_back.second] = n;
	deque_size++;
}

int algorithms::deque::pop_front()
{
	if (deque_size == 0)
	{
		return -1;
	}
	int value = blocksArr[_front.first][_front.second];
	_front.second++;
	deque_size--;
	boundryCheck(_front);
	cout << value << endl;
	return value;
}

int algorithms::deque::pop_back()
{
	if (deque_size == 0)
	{
		return -1;
	}
	int value = blocksArr[_back.first][_back.second];
	_back.second--;
	deque_size--;
	boundryCheck(_back);
	cout << value << endl;
	return value;
}

int algorithms::deque::front()
{
	if (deque_size == 0)
	{
		return -1;
	}
	int value = blocksArr[_front.first][_front.second];
	cout << value << endl;
	return value;
}


int algorithms::deque::back()
{
	if (deque_size == 0)
	{
		return -1;
	}
	int value = blocksArr[_back.first][_back.second];
	cout << value << endl;
	return value;
}

int algorithms::deque::size()
{
	cout << deque_size << endl;
	return deque_size;
}

void algorithms::deque::clear()
{
	deque_size = 0;
	_front = make_pair(arrSize / 2 - 1, blockSize / 2 - 1);
	_back = _front;
}

void algorithms::deque::boundryCheck(pair<int, int>& border)
{
	if (border.second < 0)
	{
		border.first--;
		border.second = blockSize - 1;
	}
	if (border.first < 0)
		expandblocksArr();
	if (border.second >= blockSize)
	{
		border.first++;
		border.second = 0;
	}
	if (border.first >= arrSize)
		expandblocksArr();
}

void algorithms::deque::expandblocksArr()
{
	int oldArrSize = arrSize;
	arrSize *= 2;
	int **newBlocksArr = new int*[arrSize] {};
	for (int i = 0; i < (arrSize - oldArrSize) / 2; i++)
		newBlocksArr[i] = new int[blockSize] {};
	for (int i = (arrSize - oldArrSize) / 2; i < (arrSize + oldArrSize) / 2; i++)
	{
		newBlocksArr[i] = blocksArr[i - (arrSize - oldArrSize) / 2];
	}
	for (int i = (arrSize + oldArrSize) / 2; i < arrSize; i++)
		newBlocksArr[i] = new int[blockSize] {};
	_front.first += (arrSize - oldArrSize) / 2;
	_back.first += (arrSize - oldArrSize) / 2;

	blocksArr = newBlocksArr;
}