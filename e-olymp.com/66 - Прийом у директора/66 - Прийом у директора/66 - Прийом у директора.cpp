// 66 - Прийом у директора.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int Str_to_Int(string st)
{
	int res = 0;
	int dec = 1;
	for (int i = st.length() - 1; i >=0; i--)
	{
		res += (st[i] - '0')*dec;
		dec *= 10;
	}
	return res;
}

void Sort(vector < pair<int, int> >& vector)
{
	bool swapped;
	for (int i = 0; i < vector.size() - 1; i++)
	{
		swapped = false;
		for (int j = 0; j < vector.size() - 1 - i; j++)
			if (vector[j].first > vector[j + 1].first)
			{
				swapped = true;
				pair<int, int> temp = vector[j];
				vector[j] = vector[j + 1];
				vector[j + 1] = temp;
			}
		if (!swapped)
			break;
	}
}

int main()
{
	int N;
	//ifstream file("input.txt");
	//file >> N;
	cin >> N;
	string st1, st2;
	vector < pair<int, int> > time(N);
	vector<vector<int>> closed(N);
	int tin, tout;
	for (int i = 0; i < N; i++) 
	{
		//file >> st1 >> st2;
		cin >> st1 >> st2;
		tin = Str_to_Int(st1.substr(0, 2)) * 60 + Str_to_Int(st1.substr(3, 5));
		tout = Str_to_Int(st2.substr(0, 2)) * 60 + Str_to_Int(st2.substr(3, 5));
		time[i] = make_pair(tin, tout);
	}
	Sort(time);
	int compare;
	for (int i = 0; i < closed.size(); i++)
	{
		compare = time[i].second;
		for (int j = i+1; j < N; j++)
		{
			if (time[j].first < compare)
				closed[i].push_back(j);
		}
		closed[i].resize(closed[i].size());
	}
	int minclosed;
	int index;
	int i = 0, count = 0;
	do {
		minclosed = closed[i].size();
		index = i;
		for (int j = 0; j < closed[i].size(); j++)
			if (closed[closed[i][j]].size() < minclosed)
			{
				minclosed = closed[closed[i][j]].size();
				index = closed[i][j];
			}
		count++;
		if(closed[index].size()>0)
			i = closed[index][closed[index].size() - 1] + 1;
		else i = index + 1;
	} while (i < N);
	cout << count;
	//file.close();
	return 0;
}

