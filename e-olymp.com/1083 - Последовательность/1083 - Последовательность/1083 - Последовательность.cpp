// 1083 - Последовательность.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#define MOD 10000

using namespace std;

int PowMod(int x, int n, int m)
{
	if (n == 0) return 1;

	if (n % 2 == 0) return PowMod((x * x) % m, n / 2, m);

	return (x * PowMod(x, n - 1, m)) % m;
}

int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	int a, n;
	fin >> a >> n;
	int x = PowMod(2, n - 1, MOD);

	int res = PowMod(a, x, MOD);

	fout << res << "\n";
	return 0;
}


