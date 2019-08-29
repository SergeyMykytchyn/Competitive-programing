// 1520 - Непарні дільники.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>

using namespace std;

long long g(long long n)
{
	long long k = (n + 1) / 2;
	if (n == 0)
		return 0;
	return k * k + g(n / 2);
}

int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	long long n;
	while (fin >> n)
		fout << g(n) << "\n";
	fin.close();
	fout.close();
	return 0;
}

