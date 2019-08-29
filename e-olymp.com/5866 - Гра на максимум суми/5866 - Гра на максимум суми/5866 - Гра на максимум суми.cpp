// 5866 - Гра на максимум суми.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

const int N = 2013;

int a[N][N] = { 0 };


int recur(vector<pair<int, int>>& v, int i, int begin, int end)
{
	if (a[v[begin].first][v[end].first] != 0)
		return a[v[begin].first][v[end].first];

	if (end - begin == 1)
	{
			return max(v[begin].second, v[end].second);
	}

	int l1 = v[begin].second;
	int len1 = recur(v, i+1, begin + 1, end);
	a[v[begin + 1].first][v[end].first] = len1;
	if (i % 2 == 0)
		len1 += l1;

	int l2 = v[end].second;
	int len2 = recur(v, i+1, begin, end - 1);
	a[v[begin].first][v[end - 1].first] = len2;
	if (i % 2 == 0)
		len2 += l2;

	if (len1 > len2)
		return len1;
	else return len2;
}

int main()
{
	int N;
	ifstream fin("input.txt");
	fin >> N;
	vector<pair<int, int>> v(N);
	for (int i = 0; i < N; i++)
	{
		v[i].first = i;
		fin >> v[i].second;
	}
	int sum = 0;
	
	fin.close();
	ofstream fout("output.txt");
	fout << recur(v, 0, 0, v.size() - 1);
	fout.close();
	return 0;
}

