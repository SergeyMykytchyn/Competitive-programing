// 4786 - Відрізки.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<pair<int, int>> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i].second >> v[i].first;
	sort(v.begin(), v.end());
	int c = 0, i = 0, temp;
	while (i < v.size())
	{
		c++;
		temp = v[i].first;
		while (i < v.size() && v[i].second < temp)
			i++;
	}
	cout << c;
	return 0;
}

