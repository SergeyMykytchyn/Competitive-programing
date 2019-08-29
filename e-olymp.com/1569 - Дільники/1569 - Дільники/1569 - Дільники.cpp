// 1569 - Дільники.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

long long g(int n)
{
	int n_sqrt = floor(sqrt(n));
	long long sum = 0;
	for (int i = 1; i <= n_sqrt; i++)
		sum += n / i;
	n_sqrt = n / (n_sqrt + 1);
	for (int i = 1; i <= n_sqrt; i++)
		sum += i * (n / i - n / (i + 1));
	return sum;
}

int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	int a, b;
	while (1)
	{
		fin >> a >> b;
		if (a == 0)
			break;
		fout << g(b) - g(a - 1) << "\n";
	}
	fin.close();
	fout.close();
	return 0;
}

