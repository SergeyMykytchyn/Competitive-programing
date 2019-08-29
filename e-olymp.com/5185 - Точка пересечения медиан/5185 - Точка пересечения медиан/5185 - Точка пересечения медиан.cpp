// 5185 - Точка пересечения медиан.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

using namespace std;

int main()
{
	double x1, y1, x2, y2, x3, y3;
	cin >> x1 >> y1;
	cin >> x2 >> y2;
	cin >> x3 >> y3;

	double x = (x1 + x2 + x3) / 3;
	double y = (y1 + y2 + y3) / 3;

	cout.precision(6);
	cout << fixed;
	cout << x << " " << y;

	return 0;
}


