// 2524 - Рядки Фібоначчі.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#define MAX 44

using namespace std;

int fib[MAX] = { 1, 1 };

char solve(int n, int k)
{
	if (n == 0) return 'a';
	if (n == 1) return 'b';
	if (k <= fib[n - 2]) 
		return solve(n - 2, k);
	return solve(n - 1, k - fib[n - 2]);
}

int main()
{
	for (int i = 2; i < MAX; i++)
		fib[i] = fib[i - 1] + fib[i - 2];
	cout << fib[40];
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	int tests, n, k;
	fin >> tests;
	while (tests--)
	{
		fin >> n >> k;
		fout << solve(n, k) << "\n";
	}
	fin.close();
	fout.close();
	return 0;
}

