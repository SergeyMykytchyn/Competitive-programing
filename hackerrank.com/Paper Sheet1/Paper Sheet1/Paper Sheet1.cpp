// Paper Sheet1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>

using namespace std;

void Fold(long f, long f1, int& count)
{
	while (f1 < f)
	{
		f1 *= 2;
		count++;
	}
}

int minMoves(long h, long w, long h1, long w1)
{
	int count = 0;
	Fold(h, h1, count);
	Fold(w, w1, count);
	return count;
}

int main()
{
	long h, w, h1, w1;
	cin >> h >> w >> h1 >> w1;
	cout << minMoves(h, w, h1, w1);
	return 0;
}

