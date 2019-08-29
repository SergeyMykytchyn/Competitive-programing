// 33 - Любимые числа Деда Мороза.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;

bool SantaLike(int n)
{
	string s = "";
	int t;
	while (n)
	{
		t = n % 10;
		s += '0' + t;
		n /= 10;
	}
	for (int i = 0; i < s.length(); i++)
		if (s[i] == '3' && s[i + 1] == '1')
			return false;
	return true;
}

int SantaNumbers(int a, int b)
{
	vector<bool> prime(b + 1, true);

	for (int i = 0; i < b + 1; i++)
		if (i % 2 == 0)
			prime[i] = false;

	prime[1] = false;
	prime[2] = true;
	for (int i = 3; i*i <= b; i++)
		if(prime[i])
			for (int p = i * i; p <= b; p += 2*i)
				prime[p] = false;

	int count = 0;
	for (int i = a; i <= b; i++)
		if (prime[i] && SantaLike(i))
			count++;
	return count;
}

int main()
{
	int a, b;
	cin >> a >> b;
	cout << SantaNumbers(a, b);
	return 0;
}

