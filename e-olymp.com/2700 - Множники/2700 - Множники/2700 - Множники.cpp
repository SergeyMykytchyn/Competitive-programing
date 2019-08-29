// 2700 - Множники.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>


using namespace std;

vector < pair<long long, long long > > d;

int check_d(long long x)
{
	for (int i = 0; i < d.size(); i++)
		if (d[i].first == x)
			return d[i].second;
	return -1;
}

int fact(long long x)
{
	bool first = true;
	if (x == 1)
		return 0;
	for (int i = 0; i < d.size(); i++)
		if (d[i].first == x)
			return d[i].second;
	int i = 2, count = 0, cnew = 0, head = d.size();
	while (x > 1)
	{
		if (x % i == 0)
		{
			while (x % i == 0)
			{
				if (!first) {

					int temp = check_d(x);
					if (temp != -1)
						return temp + count;
					else {
						cnew++;
						d.push_back(make_pair(x, count));
					}
				}
				first = false;
				x /= i;
				count++;
			}
		}
		if(i < 3)
			i++;
		else i += 2;
	}
	for (int j = head; j < head + cnew; j++)
		d[j].second = count - d[j].second;
	return count;
}

int MaxDiv(long long x)
{
	long long maxdiv = -1, div, index;
	for (long long i = x; i >= 1; i--)
	{
		div = fact(i);
		if (div > maxdiv)
		{
			maxdiv = div;
			index = i;
		}
	}
	return index;
}

int main()
{
	long long t, n;
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	fin >> t;
	for (int i = 0; i < t; i++)
	{
		fin >> n;
		fout << MaxDiv(n) << endl;
	}
	fin.close();
	fout.close();
	return 0;
}