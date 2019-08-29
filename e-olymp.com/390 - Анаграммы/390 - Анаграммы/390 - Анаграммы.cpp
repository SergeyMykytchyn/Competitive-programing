// 390 - Анаграммы.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

int fact(int n)
{
	if (n < 2)
		return 1;
	return fact(n - 1) * n;
}

int main()
{
	string s;
	getline(cin, s);
	int n = s.length();
	int head = 0, j;
	char* ch = new char[n];
	int* ch_n = new int[n];
	ch[0] = s[0];
	ch_n[0] = 1;
	head++;
	for (int i = 1; i < n; i++)
	{
		for(j = 0; j < head; j++)
			if (s[i] == ch[j])
			{
				ch_n[j]++;
				break;
			}
		if (j == head)
		{
			ch[head] = s[i];
			ch_n[head] = 1;
			head++;
		}
	}
	int res = fact(n);
	for (int i = 0; i < head; i++)
		res /= fact(ch_n[i]);
	cout << res;
	return 0;
}

