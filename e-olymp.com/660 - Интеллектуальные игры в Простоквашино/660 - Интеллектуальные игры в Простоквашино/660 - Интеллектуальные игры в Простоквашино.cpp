// 660 - Интеллектуальные игры в Простоквашино.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	int N, x1, y1, x2, y2;
	fin >> N;
	for (int i = 0; i < N; i++)
	{
		fin >> x1 >> y1 >> x2 >> y2;
		if ((abs(x1 - x2) % 2 == 0 && abs(y1 - y2) % 2 != 0) || (abs(x1 - x2) % 2 != 0 && abs(y1 - y2) % 2 == 0))
			fout << 1;
		else fout << 0;
	}
	fin.close();
	fout.close();
	return 0;
}

