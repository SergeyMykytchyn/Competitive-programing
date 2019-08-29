// 43 - Количество участников олимпиады.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int k, n, m, d;
	double eps = 1e-4;
	cin >> k >> n >> m >> d;
	double N;
	N = d / (1. - (1. / k + 1. / m + 1. / n));
	if (fabs((N - round(N))) < eps)
		cout << round(N);
	else cout << -1;
	return 0;
}

