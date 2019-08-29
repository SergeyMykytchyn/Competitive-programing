// 2176 - Нумерація дерев.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>

using namespace std;

ofstream fout("output.txt");

int count = 0;

void Tree(int n, bool side)
{
	if (n == 0)
	{
		count++;
		if(count == n)
		fout << '(';
		return;
	}

	Tree(n - 1, true);

	if (n == 0)
		cout << "X";

	Tree(n - 1, false);


}

int main()
{
	int n;
	ifstream fin("input.txt");
	while (fin >> n)
	{
		for (int i = 0; i < n; i++)
		{

		}
	}

	return 0;
}
