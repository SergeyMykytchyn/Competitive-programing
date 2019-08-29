// 796 - The Stable Marriage Problem.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
using namespace std;

ofstream fout("output.txt");


bool wPrefersM1OverM(int** prefer, int w, int m, int m1, int N)
{
	for (int i = 0; i < N; i++)
	{
		if (prefer[w][i] == m1)
			return true;

		if (prefer[w][i] == m)
			return false;
	}
}

void stableMarriage(int** prefer, map<int, char>& revdic, int N)
{
	int* wPartner = new int[N];
	bool* mFree = new bool[N];

	for (int i = 0; i < N; i++)
	{
		wPartner[i] = -1;
		mFree[i] = false;
	}
	int freeCount = N;

	while (freeCount > 0)
	{
		int m;
		for (m = 0; m < N; m++)
			if (mFree[m] == false)
				break;

		for (int i = 0; i < N && mFree[m] == false; i++)
		{
			int w = prefer[m][i];

			if (wPartner[w - N] == -1)
			{
				wPartner[w - N] = m;
				mFree[m] = true;
				freeCount--;
			}
			else  
			{
				int m1 = wPartner[w - N];

				if (wPrefersM1OverM(prefer, w, m, m1, N) == false)
				{
					wPartner[w - N] = m;
					mFree[m] = true;
					mFree[m1] = false;
				}
			}  
		} 
	} 
	int* mPartner = new int[N];
	for (int i = 0; i < N; i++)
	{
		mPartner[wPartner[i]] = i + N;
	}
	for (int i = 0; i < N; i++)
		fout << revdic[i] << " " << revdic[mPartner[i]] << "\n";
	fout << "\n";
	delete[]wPartner;
	delete[]mPartner;
	delete[]mFree;
}

int main()
{
	int nTests, N;
	ifstream fin("input.txt");
	fin >> nTests;
	char ch;
	string s;
	for (int i = 0; i < nTests; i++)
	{
		fin >> N;
		map<char, int> dic;
		map<int, char> revdic;
		int** prefer = new int*[2 * N];
		for (int j = 0; j < 2 * N; j++)
		{
			fin >> ch;
			dic.insert(make_pair(ch, j));
			revdic.insert(make_pair(j, ch));
			prefer[j] = new int[N];
		}
		for (int j = 0; j < 2 * N; j++)
		{
			fin >> s;
			for (int k = 0; k < N; k++)
				prefer[dic[s[0]]][k] = dic[s[k + 2]];
		}
		stableMarriage(prefer, revdic, N);

		for (int j = 0; j < 2*N; j++)
			delete[] prefer[j];
		delete[] prefer;
	}
	fin.close();
	fout.close();
	return 0;
}

