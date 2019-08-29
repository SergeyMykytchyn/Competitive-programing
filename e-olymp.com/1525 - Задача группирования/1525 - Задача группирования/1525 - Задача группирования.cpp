// 1525 - Задача группирования.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

vector<long long> set;

long long S(int n, int k, int m)
{
	if (k == 1)
	{
		long long s = 0;
		for (int i = 0; i < n; i++)
			s += set[i];
		s %= m;
		return s;
	}
	if (n == k)
	{
		long long mul = 1;
		for (int i = 0; i < n; i++)
		{
			mul *= set[i];
			mul %= m;
		}
		return mul;
	}
	long long res = (S(n - 1, k, m) + (S(n - 1, k - 1, m) * set[n - 1]) % m) % m;
	return res;
}

int main()
{
	ifstream fin("input1.txt");
	ofstream fout("output1.txt");
	int n, m;
	while (1)
	{
		fin >> n >> m;
		if (n == 0)
			break;
		set.clear();
		set.resize(n);
		for (int i = 0; i < n; i++)
		{
			fin >> set[i];
		}
		int maxS = -1, s;
		for (int k = 1; k <= n; k++)
		{
			s = S(n, k, m);
			if (s > maxS)
				maxS = s;
		}
		fout << maxS << "\n";
	}
	fin.close();
	fout.close();
	return 0;
}
