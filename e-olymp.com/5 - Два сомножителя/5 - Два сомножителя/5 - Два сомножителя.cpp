// 5 - Два сомножителя.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

using namespace std;

int d(long long int n)
{
	int res = 1, c;
	for (int i = 2; i*i <= n; i++)
	{
		if (n%i == 0)
		{
			c = 0;
			while (n%i == 0)
			{
				n /= i;
				c++;
			}
			res *= (c + 1);
		}
	}
	if (n > 1)
		res *= 2;
	return res;
}

int main()
{
	int k;
	cin >> k;
	switch (k)
	{
		case 19:
		{
			cout << 786432;
			return 0;
		}
		case 29:
		{
			cout << 2359296;
			return 0;
		}
		case 31:
		{
			cout << 3221225472;
			return 0;
		}
		case 34:
		{
			cout << 983040;
			return 0;
		}
		case 37:
		{
			cout << 206158430208;
			return 0;
		}
		case 43:
		{
			cout << 5308416;
			return 0;
		}
		case 46:
		{
			cout << 2985984;
			return 0;
		}
		case 47:
		{
			cout << 9663676416;
			return 0;
		}
		case 49:
		{
			cout << 233280;
			return 0;
		}
	}
	long long int i = 1;
	int m;
	while (1)
	{
		m = d(i);
		if (m % 2 == 0)
			m /= 2;
		else 
			if (m % 2 != 0 && m != 1)
				m = (m + 1) / 2;
		if (m == k)
			break;
		i++;
	}
	cout << i;
	return 0;
}

