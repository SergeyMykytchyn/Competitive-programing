// Marathon.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int minimumCost(vector<int> d, int p) 
{
	int v = 1;
	long long t = 0, t1;
	while (1) {
		for (int i = 0; i < d.size(); i++)
		{
			t1 = d[i] / v;
			t = t + ceil(t1);
		}
		if (t <= p)
			return v;
		t = 0;
		v++;
	}
}

int main()
{
	cout << sizeof(long long);
	int n;
	ifstream fin("input.txt");
	fin >> n;
	vector<int> d(n);
	int p;
	for (int i = 0; i < n; i++)
		fin >> d[i];
	fin >> p;
	cout << minimumCost(d, p);
	return 0;
}
