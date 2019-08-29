// 1534 - Делимость.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>

using namespace std;

int n;

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int f(int N, int* a)
{
	int i, j, bits, temp, res = 0;
	long long lcm;
	for (i = 1; i < (1 << n); i++)
	{
		bits = 0;
		lcm = 1;
		for(j = 0; j < n; j++)
			if (i & (1 << j))
			{
				bits++;
				temp = gcd(lcm, a[j]);
				lcm = lcm / temp * a[j];
				if (lcm > N)
					break;
			}
		if (bits % 2)
			res += N / lcm;
		else
			res -= N / lcm;
	}
	return res;
}

int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	int l, r, i, res;
	int a[18];
	while (fin >> l >> r)
	{
		fin >> n;
		for (i = 0; i < n; i++)
			fin >> a[i];
		res = f(r, a) - f(l - 1, a);
		fout << res << "\n";
	}
	fin.close();
	fout.close();
	return 0;
}
