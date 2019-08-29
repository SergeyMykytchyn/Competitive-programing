// 2169 - Перестановки.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

void permitations(int* p, int n, vector<int> v)
{
	bool flag = true;
	for(int i = 0; i < n; i++)
		if (p[i] > 0)
		{
			flag = false;
			int* p_c = new int[n];
			for (int i = 0; i < n; i++)
				p_c[i] = p[i];
			p_c[i] = 0;
			v.push_back(i + 1);
			permitations(p_c, n, v);
			delete[] p_c;
			v.erase(v.begin() + v.size() - 1);
		}
	if (flag)
	{
		for (int i = 0; i < v.size(); i++)
			fout << v[i] << " ";
		fout << "\n";
	}
}

int main()
{
	int n;
	fin >> n;
	int* p = new int[n];
	for (int i = 0; i < n; i++)
		p[i] = i + 1;
	vector<int> v;
	permitations(p, n, v);
	delete[] p;
	fin.close();
	fout.close();
	return 0;
}

