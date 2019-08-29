#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

void InsertionSort(string* friends, int n)
{
	string key;
	int j;
	for (int i = 1; i < n; i++)
	{
		key = friends[i];
		j = i - 1;
		while (j >= 0 && key < friends[j])
		{
			friends[j + 1] = friends[j];
			j--;
		}
		friends[j + 1] = key;
	}
}

bool IsHere(string st, string* friends, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (friends[i] == st)
			return 1;
	}
	return 0;
}

void Sort(vector<string>& friends)
{
	string key;
	int j;
	for (size_t i = 1; i < friends.size(); i++)
	{
		key = friends[i];
		j = i - 1;
		while (j >= 0 && key < friends[j])
		{
			friends[j + 1] = friends[j];
			j--;
		}
		friends[j + 1] = key;
	}
}

int main()
{
	int n, m;
	ifstream fin("INPUT.txt");
	fin >> n;
	string* friends = new string[n];
	for (int i = 0; i < n; i++)
		fin >> friends[i];
	fin >> m;
	string* others = new(nothrow) string[m];
	if (others == nullptr)
		return 1;
	for (int i = 0; i < m; i++)
		fin >> others[i];
	fin.close();
	InsertionSort(friends, n);
	ofstream fout("OUTPUT.txt");
	fout << "Friends: ";
	for (int i = 0; i < n; i++)
	{
		fout << friends[i];
		if (i < n - 1)
			fout << ", ";
	}
	fout << "\n";
	vector<string> mutual;
	vector<string> also;
	for (int i = 0; i < m; i++)
	{
		if (IsHere(others[i], friends, n))
			mutual.push_back(others[i]);
		else also.push_back(others[i]);
	}
	Sort(mutual);
	Sort(also);
	fout << "Mutual Friends: ";
	for (size_t i = 0; i < mutual.size(); i++)
	{
		fout << mutual[i];
		if (i < mutual.size() - 1)
			fout << ", ";
	}
	fout << "\n";
	fout << "Also Friend of: ";
	for (size_t i = 0; i < also.size(); i++)
	{
		fout << also[i];
		if (i < also.size() - 1)
			fout << ", ";
	}
	fout << "\n";
	fout.close();
	delete[] friends;
	delete[] others;
	return 0;
}