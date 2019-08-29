// 1096 - Очень простая задача.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

using namespace std;

int main()
{
	int N, x, M, res = 0;
	cin >> N >> x >> M;
	for (int k = 1; k <= N; k++)
		res += pow(k, x) * pow(x, k);
	cout << res % M;
	return 0;
}

