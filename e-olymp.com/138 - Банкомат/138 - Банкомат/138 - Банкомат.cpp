// 138 - Банкомат.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>

using namespace std;

int main()
{
	int n, count = 0, M;
	cin >> n;
	int a[6] = { 10, 20, 50, 100, 200, 500 };
	for (int i = 5; i >= 0; i--)
	{
		M = a[i];
		while (n >= M)
		{
			n -= M;
			count++;
		}
	}
	if (count&&n==0)
		cout << count;
	else
		cout << -1;
	return 0;
}

