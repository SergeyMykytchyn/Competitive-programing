// 1517 - Просте додавання.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>

using namespace std;

long long g(long long p)
{
	long long t = p % 10;
	if (!p) return 0;
	return t * (1 + t) / 2 + p / 10 * 45 + g(p / 10);
}

long long s(long long p, long long q)
{
	return g(q) - g(p - 1);
}

int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	long long p, q;
	cout << s(0, INT_MAX);
	/*while (1)
	{
		fin >> p >> q;
		if (p == -1)
			break;
		fout << s(p, q) << "\n";
	}*/
	fin.close();
	fout.close();
	return 0;
}

