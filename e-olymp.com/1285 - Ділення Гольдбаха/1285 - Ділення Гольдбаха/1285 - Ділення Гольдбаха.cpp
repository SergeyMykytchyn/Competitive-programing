// 1285 - Ділення Гольдбаха.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <fstream>
#define N 20000

using namespace std;

vector<bool> prime(N + 1, true);

void Eratosfen()
{
	for (int i = 0; i < N + 1; i++)
		if (i % 2 == 0)
			prime[i] = false;
	prime[1] = false;
	for (int i = 3; i * i <= N; i++)
		if (prime[i])
			for (int j = i * i; j <= N; j += 2 * i)
				prime[j] = false;
}

int EvenCount(int x)
{
	int count = 0;
	for (int i = 3; i < x / 2; i++)
		if (prime[i] && prime[x - i])
		{
			count++;
		}
	return count;
}

int OddCount(int x)
{
	int count = 0;
	for (int i = 3; i < x; i++)
		if (prime[i])
		{
			count += EvenCount(x - i);
			int k = x - i - i;
			if (k > 2 && prime[k] && k != i)
				count--;
		}
	return count / 3;
}

int main()
{
	Eratosfen();
	int n;
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	while (fin >> n)
	{
		if (n % 2 == 0)
			fout << EvenCount(n) << endl;
		else fout << OddCount(n) << endl;
	}
	fin.close();
	fout.close();
	return 0;
}

