// Прості числа.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>

using namespace std;

int main()
{
	int m, n;
	cin >> m >> n;
	bool *prime = new bool[n + 1];
	prime[0] = prime[1] = false;
	prime[2] = true;
	for (int i = 3; i < n + 1; i++)
	{
		if (i % 2 == 0)
			prime[i] = false;
		else prime[i] = true;
	}
	for (int i = 3; i*i <= n; i++)
		if (prime[i])
			for (int j = i * i; j <= n; j += 2 * i)
				prime[j] = false;
	bool flag = 1;
	for (int i = 2; i < n + 1; i++)
		if (i >= m && prime[i])
		{
			cout << i << endl;
			flag = 0;
		}
	if (flag)
		cout << "Absent" << endl;
	delete[]prime;
	return 0;
}
