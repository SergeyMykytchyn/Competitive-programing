// 66 - Прийом у директора1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int Str_to_Int(string st)
{
	int res = 0;
	int dec = 1;
	for (int i = st.length() - 1; i >= 0; i--)
	{
		res += (st[i] - '0')*dec;
		dec *= 10;
	}
	return res;
}

bool f(pair<int, int> a, pair<int, int> b)
{
	return (a.second < b.second);
}

int main()
{
	int N;
	ifstream file("input.txt");
	file >> N;
	string st1, st2;
	vector < pair<int, int> > time(N);
	int tin, tout;
	for (int i = 0; i < N; i++)
	{
		file >> st1 >> st2;
		tin = Str_to_Int(st1.substr(0, 2)) * 60 + Str_to_Int(st1.substr(3, 5));
		tout = Str_to_Int(st2.substr(0, 2)) * 60 + Str_to_Int(st2.substr(3, 5));
		time[i] = make_pair(tin, tout);
	}
	vector<pair<int, int> >::iterator i, j;
	sort(time.begin(), time.end(), f);
	for (i = time.begin(); i < time.end(); i++)
		for (j = i + 1; j < time.end();)
			if ((*i).second > (*j).first) 
				j = time.erase(j);
			else 
				j++;
	ofstream fout("output.txt");
	fout << time.size();
	fout.close();
	file.close();
}

