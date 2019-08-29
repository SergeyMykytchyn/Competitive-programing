// Similar Numbers.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <string>
#include <iostream>

using namespace std;

long fact(int n)
{
	if (n < 2)
		return 1;
	return fact(n - 1)*n;
}

long CountSimilar(int* fc, int len)
{
	long res, denom = 1;
	for (int i = 0; i < 10; i++)
		denom *= fact(fc[i]);
	res = fact(len) / denom;
	if (fc[0])
		res -= fact(len - 1)*fact(fc[0]) / denom / fact(fc[0] - 1);
	return res;
}

long findSimilar(string a, string b)
{
	bool similar = true;
	int fa[10], fb[10];
	for (int i = 0; i < 10; i++)
	{
		fa[i] = 0;
		fb[i] = 0;
	}
	for (int i = 0; i < a.length(); i++)
		fa[a[i] - '0']++;
	for (int i = 0; i < b.length(); i++)
		fb[b[i] - '0']++;
	for (int i = 0; i < 10; i++)
		if (fa[i] != fb[i])
		{
			similar = false;
			break;
		}
	long res, denom = 1;
	if (similar)
		return CountSimilar(fa, a.length());
	return CountSimilar(fb, b.length());
}

int main()
{
	string a, b;
	getline(cin, a);
	getline(cin, b);
	cout << findSimilar(a, b);
	return 0;
}

