// 311 - Максимальное количество фигур.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int Rook(int M, int N)
{
	if (M < N)
		return M;
	else return N;
}

int Knight(int M, int N)
{
	return ceil((M * N) / 2.);
}

int King(int M, int N)
{
	if (M % 2 != 0)
		M++;
	if (N % 2 != 0)
		N++;
	return M * N / 4;
}

int main()
{
	int T, M, N;
	char ch;
	ifstream fin("D:\\University\\2 kurs\\Alg\\e-olymp\\33 - Любимые числа Деда Мороза\\input.txt");
	ofstream fout("D:\\University\\2 kurs\\Alg\\e-olymp\\33 - Любимые числа Деда Мороза\\output.txt");
	fin >> T;
	for (int i = 0; i < T; i++)
	{
		fin >> ch;
		fin >> M >> N;
		if (ch == 'R' || ch == 'Q')
			fout << Rook(M, N) << endl;
		else if (ch == 'N')
			fout << Knight(M, N) << endl;
		else if (ch == 'K')
			fout << King(M, N) << endl;
	}
	fin.close();
	fout.close();
	return 0;
}

