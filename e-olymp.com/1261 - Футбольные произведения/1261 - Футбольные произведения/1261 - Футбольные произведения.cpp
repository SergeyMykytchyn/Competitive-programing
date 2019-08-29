// 1261 - Футбольные произведения.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

using namespace std;

int main()
{
	int N, S;
	cin >> N >> S;
	int M = N, i = N;
	while (1)
	{
		if (M % S == 0)
		{
			cout << i;
			return 0;
		}

		i++;
		M *= i;
	}
	return 0;
}


