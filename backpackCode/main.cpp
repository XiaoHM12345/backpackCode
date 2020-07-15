#include<iostream>
#include<vector>
#include"backpack.h"

void test1()
{
	backpack b1({ 3,11,24,50,115 }), b2(5);
	b2 = b1.hardBackpack(113, 250);
}

void test2()
{
	int a = inverse(113,250);

}

void test3()
{
	std::vector<int> s({ 0,1,1,0, 1 });
	backpack b1({ 3,11,24,50,115 }), hardb(5), b2(5);
	hardb = b1.hardBackpack(113, 250);
	int text1 = hardb.encryption(s);
	b2 = b1.decryption(text1, 113, 250);

}

int main()
{
	//test1();
	test3();
	return 0;
}