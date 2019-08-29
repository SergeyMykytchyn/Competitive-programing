// 5187 - Точка перетину висот.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

using namespace std;

int kramer(double a1, double b1, double c1, double a2, double b2, double c2, double *x, double *y)
{
	double d = a1 * b2 - a2 * b1;
	double dx = c1 * b2 - c2 * b1;
	double dy = a1 * c2 - a2 * c1;
	if (!d) return (dx == 0.0) + 1;
	*x = dx / d; *y = dy / d;
	return 0;
}

int main()
{
	double xa, ya, xb, yb, xc, yc;
	double x, y;
	cin >> xa >> ya >> xb >> yb >> xc >> yc;

	double a1 = xc - xb;
	double b1 = yc - yb;
	double c1 = xa * (xc - xb) + ya * (yc - yb);

	double a2 = xc - xa;
	double b2 = yc - ya;
	double c2 = xb * (xc - xa) + yb * (yc - ya);

	kramer(a1, b1, c1, a2, b2, c2, &x, &y);

	cout << x + 0 << " " << y + 0;
	return 0;
}


