// 3662 - Делители числа N! по модулю.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#define N 1000

using namespace std;

vector<bool> prime(N + 1, true);

void Eratosfen()
{
	for (int i = 0; i <= N; i++)
		if (i % 2 == 0)
			prime[i] = false;
	prime[1] = false;
	prime[2] = true;

	for (int i = 3; i * i <= N; i++)
		if (prime[i])
			for (int j = i * i; j <= N; j += 2 * i)
				prime[j] = false;
}

void fact(int x, vector<int>& p)
{
	int i = 2, count;
	while (x > 1)
	{
		if (x % i == 0)
		{
			count = 0;
			while (x % i == 0)
			{
				x /= i;
				count++;
			}
			p[i] += count;
		}
		i++;
	}
}

int main()
{
	Eratosfen();
	int n;
	cin >> n;
	vector<int> p(n + 1, -1);
	for (int i = 2; i <= n; i++)
		if (prime[i])
			p[i] = 0;
	for (int i = 2; i <= n; i++)
		fact(i, p);

	unsigned long long div = 1;
	for (int i = 2; i <= n; i++)
		if (p[i] > 0)
			div = (div * (p[i] + 1)) % 1000000009;
	cout << div;
	return 0;
}

