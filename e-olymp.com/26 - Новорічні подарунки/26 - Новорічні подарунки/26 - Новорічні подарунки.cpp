// 26 - Новорічні подарунки.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

int cmp(pair<int, int> a, pair<int, int> b)
{

	int mm = min(min(a.first, a.second), min(b.first, b.second));
	if ((mm == a.first) || (mm == b.second)) 
		return 0;
	return 1;

}

void Sort(vector<pair<int, int>>& v)
{
	int i, j;
	for (i = 0; i < v.size(); i++)
		for (j = i + 1; j < v.size(); j++)
			if (cmp(v[i], v[j])) swap(v[i], v[j]);
}

int main()
{
	int n;
	ifstream fin("input.txt");
	fin >> n;
	vector<pair<int, int>> v(n);
	int t;
	for (int i = 0; i < n; i++)
	{
		fin >> t;
		v[i] = make_pair(t, 0);
	}
	for (int i = 0; i < n; i++)
		fin >> v[i].second;
	Sort(v);
	int a = 0, sum = 0;
	for (int i = 0; i < v.size(); i++)
	{
		a += v[i].first;
		sum = max(a, sum) + v[i].second;
	}
	fin.close();
	ofstream fout("output.txt");
	fout << sum;
	fout.close();
	return 0;
}

