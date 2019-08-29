// 4796 - Столица Криляндии.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <climits>

using namespace std;

int f(int x, int y, vector<pair<int, int>>& cit)
{
	int f = 0;
	for (int i = 0; i < cit.size(); i++)
		f += abs(x - cit[i].first) + abs(y - cit[i].second);
	return f / cit.size();
}

bool PlaceIsFree(int x, int y, vector<pair<int, int>>& cit)
{
	for (int i = 0; i < cit.size(); i++)
		if (cit[i].first == x && cit[i].second == y)
			return false;
	return true;
}

int main()
{
	ifstream fin("input.txt");
	int N;
	fin >> N;
	vector<pair<int, int>> cit(N);
	for (int i = 0; i < N; i++)
		fin >> cit[i].first >> cit[i].second;

	int x_min, x_max, y_min, y_max;
	x_min = y_min = 1001;
	x_max = y_max = - 1001;

	for (int i = 0; i < N; i++)
	{
		if (cit[i].first < x_min)
			x_min = cit[i].first;
		if (cit[i].first > x_max)
			x_max = cit[i].first;
		if (cit[i].second < y_min)
			y_min = cit[i].second;
		if (cit[i].second > y_max)
			y_max = cit[i].second;
	}

	x_min--;
	y_min--;
	x_max++;
	y_max++;

	int f_min = INT_MAX, x_c = 0, y_c = 0;
	int f_v;

	int t = f(3, 2, cit);

	for(int y = y_min; y <= y_max; y++)
		for (int x = x_min; x <= x_max; x++)
		{
			if (!PlaceIsFree(x, y, cit))
				continue;
			f_v = f(x, y, cit);
			if (f_v < f_min)
			{
				f_min = f_v;
				x_c = x;
				y_c = y;
			}
		}
	ofstream fout("output.txt");
	fout << x_c << " " << y_c;
	fin.close();
	fout.close();
	return 0;
}


