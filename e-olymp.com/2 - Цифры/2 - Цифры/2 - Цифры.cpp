// 2 - Цифры.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

using namespace std;

int main()
{
	int n, count = 0;
	cin >> n;
	do
	{
		n /= 10;
		count++;
	} while (n);
	cout << count;
	return 0;
}

