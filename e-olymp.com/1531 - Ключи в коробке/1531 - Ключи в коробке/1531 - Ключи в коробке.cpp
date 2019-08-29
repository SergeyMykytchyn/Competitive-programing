// 1531 - Ключи в коробке.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <string.h>
#define M 21

using namespace std;

long long s[M][M];


long long gcd(long long a, long long b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

void CountS()
{
	int i, k;
	memset(s, 0, sizeof(s));
	s[0][0] = 1;
	for (i = 1; i < M; i++)
		for (k = 1; k < M; k++)
			s[i][k] = s[i - 1][k - 1] + (i - 1) * s[i - 1][k];
}

void getAllKeys(int n, int m, long long& a, long long& b)
{
	int k;

	a = 0;
	for (k = 1; k <= m; k++)
		a += s[n][k];

	b = 1;
	for (k = 1; k <= n; k++)
		b *= k;

	long long d = gcd(a, b);
	a /= d;
	b /= d;
}

int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	int n, m;
	long long a, b;
	CountS();
	while (fin >> n >> m)
	{
		getAllKeys(n, m, a, b);
		fout << a << "/" << b << "\n";
	}
	fin.close();
	fout.close();
	return 0;
}
