//============================================================================
// Name        : rand7.cpp
// Author      : Clarence
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdlib.h>
#include <map>
#include <ctime>
using namespace std;


int rand5()
{
	return rand() % 5 + 1;
}


int rand7()
{
	// method 1
	return rand() % 7 + 1;
}



int exp(int x, int y)
{
	if(y <= 0)
		return 1;
	return x * exp(x, y - 1);
}

int foo(int x)
{
	if(x == 0)
		return rand5()-1;
	return (rand5()-1) * exp(5,x) + foo(x - 1);
}

int main() {

	srand(time(NULL));

	// test this out

	map<int, int> histogram;
	map<int, int>::iterator it;

	int max = 100000;

	for(int i = 1; i <= max; i++)
	{
		int x = rand7();
		x = foo(7) % 7 + 1;
		it = histogram.find(x);
		if(it != histogram.end()) {
			it->second++;
		}
		else
			histogram.insert( std::pair<int, int>(x, 1));
	}

	float avg = max / 7;
	int divisor = max / 500;
	int a = 0;
	float b = 0;
	int c = 0;
	string str;


	for( it = histogram.begin(); it != histogram.end(); it++)
	{
//		cout << it->first << " : " <<  -( avg - (float) it->second) / avg << endl;
//		cout << it->first << " : " <<  (int)(( it->second / avg ) * 100 )<< endl;
		a = it->second;
		b = -( avg - (float) it->second) / avg;
		c = (int)(( it->second / avg ) * 100 );
//		cout << it->first << " : " <<  it->second << endl;
		str.clear();
		for(int i = 0; i <= a/ divisor; i++)
		{
			str.append("|");
		}
		cout << it->first << " : " << str << endl;

	}


	return 0;
}
