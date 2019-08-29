// 1532 - Рукопожатие.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#define M 25

using namespace std;

long long s[M];


void Solve()
{
	s[0] = 1;
	s[1] = 2;
	long long temp;
	int i, j, n;
	for (i = 6; i <= 50; i += 2)
	{
		n = (i - 2) / 2;
		if (n % 2 != 0)
		{
			temp = 0;
			for (j = 1; j <= n / 2; j++)
				temp += s[j - 1] * s[i / 2 - j - 2];
			temp += s[i / 2 - 2];
			temp *= 2;
			s[i / 2 - 1] = temp;
		}
		else {
			temp = 0;
			for(j = 1; j < n / 2; j++)
				temp += s[j - 1] * s[i / 2 - j - 2];
			temp += s[i / 2 - 2];
			temp *= 2;
			temp += s[(i - 2) / 4 - 1] * s[(i - 2) / 4 - 1];
			s[i / 2 - 1] = temp;
		}
	}
}

int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	Solve();
	int n;
	while (fin >> n)
		fout << s[n / 2 - 1] << "\n";
	fin.close();
	fout.close();
	return 0;
}

