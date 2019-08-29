// 2700 - Множники1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>
using namespace std;

bool prime(int x)
{
	for (int i = 2; i * i <= x; i++)
		if (x % i == 0)
			return false;
	return true;
}

long long MaxDiv(long long x)
{
	if (prime(x))
		return 1;
	long long d = 1, count = 0;
	int div = 2, j = 1;
	while (1)
	{
		if (d == x)
			return count;
		if (d > x)
		{
			d /= (div * div);
			count -= 2;
			if(div == 2)
				while (!prime(div))
					div++;
			else 
				while (!prime(div))
					div += 2;
		}

		d *= div;
		count++;
	}
}

int main()
{
	long long t, n;
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	fin >> t;
	for (int i = 0; i < t; i++)
	{
		fin >> n;
		fout << MaxDiv(n) << endl;
	}
	fin.close();
	fout.close();
	return 0;
}

