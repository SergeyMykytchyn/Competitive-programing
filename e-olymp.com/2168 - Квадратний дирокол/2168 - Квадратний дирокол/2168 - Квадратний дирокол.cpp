// 2168 - Квадратний дирокол.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>

using namespace std;

void punch(bool** a, int n, int m, int x, int y)
{
	a[x][y] = 1;
	if (x + 1 < n)
	{
		if (a[x + 1][y] != 1)
		{
			punch(a, n, m, x + 1, y);
		}
	}
	if (x - 1 >= 0)
	{
		if (a[x - 1][y] != 1)
		{
			punch(a, n, m, x - 1, y);
		}
	}
	if (y + 1 < m)
	{
		if (a[x][y + 1] != 1)
		{
			punch(a, n, m, x, y + 1);
		}
	}
	if (y - 1 >= 0)
	{
		if (a[x][y - 1] != 1)
		{
			punch(a, n, m, x, y - 1);
		}
	}

}

int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	int n, m, count = 0;
	fin >> n >> m;
	bool** a = new bool*[n];
	for (int i = 0; i < n; i++)
		a[i] = new bool[m];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			fin >> a[i][j];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			if (a[i][j] != 1)
			{
				punch(a, n, m, i, j);
				count++;
			}
	fout << count;
	fin.close();
	fout.close();
	for (int i = 0; i < n; i++)
		delete[] a[i];
	delete[] a;
	return 0;
}

