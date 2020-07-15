#pragma once
#include<vector>
#include<initializer_list>
#include "Array.h"

int inverse(int num1, int p);

class backpack :
	public Array
{
public:
	backpack(int i)
	{
		array.resize(i);
	}
	backpack(std::initializer_list<int> input)
	{
		array.resize(input.size());
		std::initializer_list<int>::iterator it1 = input.begin();
		std::vector<int>::iterator it2 = array.begin();
		while (it1 != input.end() && it2 != array.end())
		{
			*it2 = *it1;
			it1++;
			it2++;
		}
	}
	backpack operator=(const backpack& other)
	{
		array.resize(other.array.size());
		array = other.array;
		return *this;
	}
	std::vector<int>::iterator getBeginIterator()
	{
		return array.begin();
	}
	std::vector<int>::iterator getEndIterator()
	{
		return array.end();
	}
	std::vector<int>::reverse_iterator getRBeginIterator()
	{
		return array.rbegin();
	}
	std::vector<int>::reverse_iterator getREndIterator()
	{
		return array.rend();
	}
	backpack hardBackpack(int P1, int P2);
	int encryption(std::vector<int> plaintext);
	backpack decryption(int ciphertext, int P1, int P2);
protected:
	std::vector<int> array;
};

backpack backpack::hardBackpack(int P1, int P2)
{
	backpack res(array.size());
	std::vector<int>::iterator it1, it2;
	it1 = res.getBeginIterator();
	it2 = this->getBeginIterator();
	while (it1 != res.getEndIterator() && it2 != this->getEndIterator())
	{
		*it1 = (*it2 * P1) % P2;
		it1++;
		it2++;
	}
	return res;
}

int backpack::encryption(std::vector<int> plaintext)
{
	std::vector<int>::iterator it1, it2;
	int res = 0;
	it1 = plaintext.begin();
	it2 = array.begin();
	while (it1 != plaintext.end() && it2 != array.end())
	{
		res += (*it1) * (*it2);
		it1++;
		it2++;
	}
	return res;
}

int inverse(int num1, int p)
{
	int remainder;
	std::vector<int> s(0);
	remainder = p % num1;
	int temp1 = num1;
	int temp_p = p;
	while (remainder != 0)
	{
		int temp2 = (temp_p - remainder) / temp1;
		s.push_back(temp2);
		temp_p = temp1;
		temp1 = remainder;
		remainder = temp_p % remainder;
	}
	
	std::vector<int> b(0);
	b.push_back(1);
	std::vector<int>::reverse_iterator it, it_b;
	for (it = s.rbegin(); it != s.rend(); it++)
	{
		if (it == s.rbegin())
			b.push_back(*it);
		else
		{
			it_b = b.rbegin();
			int temp = (*it) * (*it_b);

			int a = 0;
			temp += (*(it_b + 1));
			b.push_back(temp);
		}
	}
	it_b = b.rbegin();
	if (s.size() % 2 == 0)
		return *it_b;
	else
		return p - *it_b;
}

backpack backpack::decryption(int ciphertext,int P1,int P2)
{
	int S = inverse(P1, P2);
	S = (S * ciphertext) % P2;

	backpack res(array.size());
	std::vector<int>::reverse_iterator it1, it2;
	it1 = res.getRBeginIterator();
	it2 = this->getRBeginIterator();

	while (it1 != res.getREndIterator() && it2 != this->getREndIterator() && S != 0)
	{
		if (S >= * it2)
		{
			S -= *it2;
			*it1 = 1;
		}
		else
			*it1 = 0;
		it1++;
		it2++;
	}
	return res;
}
