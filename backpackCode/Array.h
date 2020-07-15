#pragma once
#include <vector>

class Array
{
public:
	virtual std::vector<int>::iterator getBeginIterator() = 0;
	virtual std::vector<int>::iterator getEndIterator() = 0;
	virtual std::vector<int>::reverse_iterator getRBeginIterator() = 0;
	virtual std::vector<int>::reverse_iterator getREndIterator() = 0;
};

