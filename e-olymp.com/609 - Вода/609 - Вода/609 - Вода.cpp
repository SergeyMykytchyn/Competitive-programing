// 609 - Вода.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

bool f(int i, int j)
{
	return (i > j);
}

int main()
{
	int n, k;
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	fin >> n >> k;
	vector<int> v(n);
	for (int i = 0; i < v.size(); i++)
	{
		fin >> v[i];
		if (v[i] > k)
		{
			fout << "Impossible";
			return 0;
		}
	}
	sort(v.begin(), v.end(), f);
	int head, index, count = 0, end;
	while (v.size()>1)
	{
		head = v[0];
		v.erase(v.begin());
		end = v[v.size() - 1];
		if (head + end <= k)
			v.erase(v.begin()+v.size()-1);
		count++;
	}
	if (v.size() == 1)
		count++;
	fout << count;
	fout.close();
	fin.close();
	return 0;
}

