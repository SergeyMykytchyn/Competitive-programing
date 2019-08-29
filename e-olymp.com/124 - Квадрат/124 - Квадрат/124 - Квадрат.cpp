// 124 - Квадрат.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	int n;
	while (fin >> n)
		fout << 4 * n << " " << n * n << "\n";
	fin.close();
	fout.close();
	return 0;
}

