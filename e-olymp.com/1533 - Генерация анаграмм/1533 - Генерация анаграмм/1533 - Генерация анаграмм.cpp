// 1533 - Генерация анаграмм.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
#include <fstream>

using namespace std;

ofstream fout("output.txt");

bool lt(char a, char b)
{
	if (toupper(a) != toupper(b)) 
		return (toupper(a) < toupper(b));
	return (a < b);
}

void permutations(vector<char> word, vector<char> tail)
{
	if (word.size() == 1)
	{
		for (int i = 0; i < tail.size(); i++)
			fout << tail[i];
		fout << word[0];
		fout << "\n";
		return;
	}
	vector<char> word_f;
	for (int i = 0; i < word.size(); i++)
	{
		if (i > 0)
			if (word[i] == word[i - 1])
				continue;
		word_f = word;
		word_f.erase(word_f.begin() + i);
		tail.push_back(word[i]);
		permutations(word_f, tail);
		tail.erase(tail.begin() + tail.size() - 1);
	}
}

int main()
{
	ifstream fin("input.txt");
	int tests;
	fin >> tests;
	while (tests--)
	{
		vector<char> word;
		string s;
		fin >> s;
		copy(s.begin(), s.end(), back_inserter(word));
		vector<char> tail;
		sort(word.begin(), word.end(), lt);
		permutations(word, tail);
	}
	fin.close();
	fout.close();
	return 0;
}


