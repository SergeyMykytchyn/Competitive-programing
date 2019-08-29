// 1071 - Несоставляемое число.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#define MAX 10000

using namespace std;

int m[MAX];

int main()
{
	int n, i;
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	fin >> n;
	for (i = 0; i < n; i++)
		fin >> m[i];

	sort(m, m + n);
	long long s = 0;
	for (i = 0; i < n; i++)
	{
		if (m[i] > s + 1) break;
		s += m[i];
	}
	fout << s + 1 << "\n";
	return 0;
}

