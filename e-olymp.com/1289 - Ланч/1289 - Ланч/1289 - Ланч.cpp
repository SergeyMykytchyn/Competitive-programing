// 1289 - Ланч.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

using namespace std;

int main()
{
	long long a, b, c;
	cin >> a >> b >> c;
	cout << a * b + b * c + a * c;
	return 0;
}
