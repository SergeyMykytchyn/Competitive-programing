// 1147 - НОД Экстрим.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <string.h>
#define MAX 200001

long long d[MAX];
int fi[MAX], i, j;

using namespace std;

void FillEulier()
{
	memset(fi, 0, sizeof(fi));
	fi[1] = 1;
	for(i = 2; i < MAX; i++)
		if(!fi[i])
			for (j = i; j < MAX; j+= i)
			{
				if (!fi[j])
					fi[j] = j;
				fi[j] -= fi[j] / i;
			}
}

void f()
{
	for(i = 2; i * i <= MAX; i++)
		for (j = i * i; j < MAX; j += i)
		{
			if (j > i * i)
				d[j] += fi[j / i] * i + fi[i] * (j / i);
			if (j == i * i)
				d[j] += fi[i] * i;
		}
}

int main()
{
	FillEulier();
	for (i = 1; i < MAX; i++)
		d[i] = fi[i];
	f();
	for (i = 3; i < MAX; i++)
		d[i] += d[i - 1];

	ifstream fin("input.txt");
	ofstream fout("output.txt");

	while (1)
	{
		fin >> i;
		if (!i)
			return 0;
		fout << d[i] << "\n";
	}
	fin.close();
	fout.close();
	return 0;
}


