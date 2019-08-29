// 1519 - Коди Грея.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

vector<bool> b;

int pow(int a, int n)
{
	int r = 1;
	while (n != 0)
	{
		if (n % 2 == 1)
			r = r * a;
		n /= 2;
		if (n != 0)
			a = a * a;
	}
	return r;
}

void GrayCode(int l, int k)
{
	if (l == 1)
		return;
	int k1, t = l / 2;
	if (k < t)
	{
		b.push_back(0);
		k1 = k;
	}
	else {
		b.push_back(1);
		k1 = l - 1 - k;
	}
	GrayCode(t, k1);
}

int Todecimal(vector<bool>& b)
{
	int t = 0;
	for (int i = 0; i < b.size(); i++)
		t += b[i] * pow(2, b.size() - i - 1);
	return t;
}

int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	int n, k, N;
	fin >> N;
	for (int i = 0; i < N; i++)
	{
		fin >> n >> k;
		b.clear();
		GrayCode(pow(2, n), k);
		fout << Todecimal(b) << "\n";
	}
	fin.close();
	fout.close();
	return 0;
}
