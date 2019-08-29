// 4778 - Належність точки проміжку.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int x_a, y_a, x_b, y_b, x_c, y_c;
	cin >> x_c >> y_c;
	cin >> x_a >> y_a;
	cin >> x_b >> y_b;

	if(x_c == x_b && y_c == y_b)
		cout << "YES\nYES\nYES\n";
	else if (x_c == x_a && y_c == y_a)
		cout << "YES\nNO\nYES\n";
	else {

		int AC = hypot(x_c - x_a, y_c - y_a);
		int BC = hypot(x_c - x_b, y_c - y_b);
		int AB = hypot(x_b - x_a, y_b - y_a);

		if (abs(AB + BC - AC) < 0.001 || abs(AC + BC - AB) < 0.001 || abs(AB + AC - BC) < 0.001) cout << "YES" << endl;
		else cout << "NO" << endl;

		if ((x_b - x_a) * (x_c - x_a) > 0 && (y_b - y_a) * (y_c - y_a) > 0)
			cout << "YES\n";
		else cout << "NO\n";

		if (abs(BC + AC - AB) < 0.001)
			cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}


