// 27 - Циклические сдвиги.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> ToBinary(int n)
{
	vector<int> v;
	while (n)
	{
		v.push_back(n % 2);
		n /= 2;
	}
	reverse(v.begin(), v.end());
	return v;
}

long long int ToDecimal(vector<int> v)
{
	long long int res = 0;
	for (int i = 0; i < v.size(); i++)
		res += v[i] * pow(2, v.size() - i - 1);
	return res;
}

int main()
{
	int n;
	cin >> n;
	vector<int> nb = ToBinary(n);
	long long int max = 0, t;
	for (int i = 0; i < nb.size(); i++)
	{
		t = ToDecimal(nb);
		if (t > max)
			max = t;
		nb.push_back(nb[0]);
		nb.erase(nb.begin());
	}
	cout << max;
	return 0;
}

