// 44 - Одиниці.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <set>
#include <iterator>

using namespace std;

set<int> mySet;

bool prime(int x)
{
	for (int i = 2; i * i <= x; i++)
		if (x % i == 0)
			return false;
	return true;
}

int OnesHelp(int n)
{
	if (n == 1)
		return 1;
	if (n == 2)
		return 2;
	if (n == 3)
		return 3;
	int res = 0;
	if (prime(n))
	{
		int min = INT_MAX, t;
		for (int j = 1; 2 * j < n; j++)
		{
			t = OnesHelp(j) + OnesHelp(n - j);
			if (t < min)
				min = t;
		}
		return min;
	}
	int i = 2, p;
	while (n > 1)
	{
		if (n % i == 0)
		{
			p = 0;
			while (n % i == 0)
			{
				n /= i;
				p++;
			}
			res += OnesHelp(i)*p;
		}
		i++;
	}
	return res;
}

int main()
{
	int n;
	//cin >> n;
	//cout << OnesHelp(n);
    int res[5001];
	res[1] = 1;
	for (int i = 2; i <= 5000; i++)
	{
		res[i] = i;
		for (int j = 1; 2 * j < i; j++)
			if (res[j] + res[i - j] < res[i]) res[i] = res[j] + res[i - j];
		for (int j = 2; j * j <= i; j++)
			if (i % j == 0 && res[j] + res[i / j] < res[i]) res[i] = res[j] + res[i / j];
	}
	for (int i = 1; i <= 5000; i++)
	{
		int t = OnesHelp(i);
		if (t != res[i])
			cout << i << " " << t << " " << res[i] << endl;
	}
	//copy(mySet.begin(), mySet.end(), ostream_iterator<int>(cout, " "));
	return 0;
}

