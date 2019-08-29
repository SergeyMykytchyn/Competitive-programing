// 2385 - Количество перестановок.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

using namespace std;

int fact(int n)
{
	if (n < 2)
		return 1;
	return fact(n - 1) * n;
}

int main()
{
	int n;
	cin >> n;
	cout << fact(n);
	return 0;
}

