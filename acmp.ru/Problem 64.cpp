#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int ch(int a)
{
	return '0' + a;
}

void appendToString(string& st, int i)
{
	vector<int> v;
	while (i)
	{
		v.push_back(i % 10);
		i /= 10;
	}
	reverse(v.begin(), v.end());
	for (size_t i = 0; i < v.size(); i++)
		st.push_back(ch(v[i]));
}

void Sieve(int n, string& st)
{
	bool* prime = new bool[n + 1];
	prime[0] = false;
	prime[1] = false;
	prime[2] = true;
	for (int i = 3; i < n + 1; i++)
	{
		if (i % 2 == 0)
			prime[i] = false;
		else prime[i] = true;
	}
	for (int i = 3; i*i <= n; i++)
		if (prime[i])
			for (int j = i * i; j <= n; j += 2 * i)
				prime[j] = false;
	for (int i = 2; i < n + 1; i++)
		if (prime[i])
			appendToString(st, i);
	delete[] prime;
}

int main()
{
	int n;
	ifstream fin("INPUT.txt");
	fin >> n;
	int* test = new int[n];
	for (int i = 0; i < n; i++)
		fin >> test[i];
	fin.close();
	string st;
	Sieve(20219, st);
	ofstream fout("OUTPUT.txt");
	for (int i = 0; i < n; i++)
	{
		fout << st[test[i] - 1];
	}
	fout.close();
	delete[] test;
	return 0;
}