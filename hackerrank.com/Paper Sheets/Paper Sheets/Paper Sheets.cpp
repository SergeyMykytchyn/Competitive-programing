// Paper Sheets.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>

using namespace std;

int minMoves(long h, long w, long h1, long w1)
{
	int count = 0;
	while (h != h1) 
	{
		double n = h / 2.;
		if (h % 2 != 0)
			n = long(n) + 1;
		if (h1 >= n)
		{
			count++;
			break;
		}
		else {
			h = n;
			count++;
		}
	}
	while (w != w1)
	{
		double n = w / 2.;
		if (w % 2 != 0)
			n = long(n) + 1;
		if (w1 >= n)
		{
			count++;
			break;
		}
		else {
			w = n;
			count++;
		}
	}
	return count;
}

int main()
{
	long h, w, h1, w1;
	cin >> h >> w >> h1 >> w1;
	cout << minMoves(h, w, h1, w1);
	return 0;
}

