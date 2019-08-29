// 605 - Красивая таблица результатов.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main()
{
	int n, m, count = 0;
	ifstream fin("input.txt");
	fin >> n >> m;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		fin >> v[i];
	for (int i = 0; i < n; i++)
	{
		while (m % (v[i] + 1) == 0)
		{
			count++;
			v[i]++;
		}
	}
	ofstream fout("output.txt");
	fout << count;
	fin.close();
	fout.close();
	return 0;
}


