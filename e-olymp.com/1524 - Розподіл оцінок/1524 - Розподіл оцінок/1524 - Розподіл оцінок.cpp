// 1524 - Розподіл оцінок.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>

using namespace std;

int f(int n, int t, int p)
{
	if (n == 2)
		return t - 2 * p + 1;
	return f(n - 1, t - p, p) * n;
}

int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	int n, t, p, tests;
	fin >> tests;
	for (int i = 0; i < tests; i++)
	{
		fin >> n >> t >> p;
		fout << f(n, t, p) << "\n";
	}
	fin.close();
	fout.close();
	return 0;
}

