// 182 - Призов до армії.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

bool f(pair<int, int> a, pair<int, int> b)
{
	return (a.first < b.first);
}

int main()
{
	int n, g, h;
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	fin >> n >> g >> h;
	if (g + h > n)
	{
		fout << -1;
		return 0;
	}
	vector<pair<int, int>> army(n);
	for (int i = 0; i < n; i++)
		fin >> army[i].first >> army[i].second;
	int power = 0;
	for(int i=0;i<n;i++)
		if (army[i].first > army[i].second)
		{
			g--;
			power += army[i].first;
		}
		else 
		{
			h--;
			power += army[i].second;
		}
	vector<pair<int, int>> v(n);
	for (int i = 0; i < n; i++)
		v[i] = make_pair(abs(army[i].first - army[i].second), i);
	sort(v.begin(), v.end(), f);
	int k = 0;
	while (g > 0)
	{
		if (army[v[k].second].first < army[v[k].second].second)
		{
			power -= army[v[k].second].second;
			power += army[v[k].second].first;
			g--;
		}
		if (army[v[k].second].first == army[v[k].second].second)
		{
			h++;
			g--;
		}
		k++;
	}
	while (h > 0)
	{
		if (army[v[k].second].first > army[v[k].second].second)
		{
			power -= army[v[k].second].first;
			power += army[v[k].second].second;
			h--;
		}
		k++;
	}
	fout << power;
	fout.close();
	fin.close();
	return 0;
}

