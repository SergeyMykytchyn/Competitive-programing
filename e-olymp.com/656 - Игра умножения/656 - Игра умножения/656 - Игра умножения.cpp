// 656 - Игра умножения.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

using namespace std;

bool StanWins(unsigned int N)
{
	long long int P = 1;
	long long int temp;
	unsigned int i = 1;
	bool flag;
	while (P < N)
	{
		temp = P * 9;
		if (temp >= N)
			if (i % 2 != 0)
				return true;
			else
				return false;
		flag = false;
		for (long long int j = 9; j >= 2; j--)
		{
			temp = P * j * 9;
			if (temp < N)
			{
				P *= j;
				flag = true;
				break;
			}
		}
		if (!flag)
			if (i % 2 != 0)
				return false;
			else
				return true;
		i++;
	}
}

int main()
{
	unsigned int N;
	cin >> N;
	if (StanWins(N))
		cout << "Stan wins.";
	else cout << "Ollie wins.";
	return 0;
}

