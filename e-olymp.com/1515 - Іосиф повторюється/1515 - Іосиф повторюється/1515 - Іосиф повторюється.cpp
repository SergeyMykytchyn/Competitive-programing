// 1515 - Іосиф повторюється.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

vector<int> jsph(30000, -1);

int joseph(int n, int k) 
{
	int res = 0;
	for (int i = 1; i <= n; ++i)
		res = (res + k) % i;
	return res + 1;
}

int joshephRecur(int& n)
{
	static int depth = 0;
	int temp = joseph(n, 2);

	if (n == temp)
	{
		n = depth;
		depth = 0;
		return temp;
	}
	depth++;
	int res = joshephRecur(temp);
	n = temp;
	return res;
}

int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	int Ntest, temp, n;
	fin >> Ntest;
	for (int i = 0; i < Ntest; i++)
	{
		fin >> n;
		temp = joshephRecur(n);
		fout << "Case " << i + 1 << ": " << n << " " << temp << "\n";
	}
	fin.close();
	fout.close();
	return 0;
}

