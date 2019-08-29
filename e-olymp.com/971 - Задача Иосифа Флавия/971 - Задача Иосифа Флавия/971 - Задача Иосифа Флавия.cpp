// 971 - Задача Иосифа Флавия.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n, k, i = 0, t = 0;
	cin >> n >> k;
	vector<int> killed(n);
	for(int i = 0; i < n; i++)
		killed[i] = i + 1;

	while (i < n)
	{
		t++;
		if (t == k)
		{
			killed.erase(killed.begin() + i);
			i--;
			t = 0;
		}
		i++;
		if (i == killed.size())
		{
			i = 0;
		}
		if (killed.size() == 1)
			break;
	}
	cout << killed[0];
	return 0;
}

