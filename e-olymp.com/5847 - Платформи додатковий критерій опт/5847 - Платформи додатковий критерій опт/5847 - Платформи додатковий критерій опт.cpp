// 5847 - Платформи додатковий критерій опт.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

pair<int, int> EasyWay(int head, vector<int>& plat, vector<pair<int, int>>& visited)
{
	if (visited[head].first != -1)
		return visited[head];
	if (plat.size() - head == 2)
	{
		pair<int, int> p = make_pair(abs(plat[head + 1] - plat[head]), 1);
		visited[head] = p;
		return p;
	}
	if (plat.size() - head == 3)
	{
		int w = 3 * abs(plat[head + 2] - plat[head]);
		pair<int, int> pw = make_pair(w, 1);
		pair<int, int> p = EasyWay(head + 1, plat, visited);
		p.first += abs(plat[head + 1] - plat[head]);
		p.second += 1;
		if (w <= p.first)
		{
			visited[head] = pw;
			return pw;
		}
		else
		{
			visited[head] = p;
			return p;
		}
	}
	pair<int, int> p1 = EasyWay(head + 1, plat, visited);
	p1.first += abs(plat[head + 1] - plat[head]);
	p1.second += 1;
	pair<int, int> p2 = EasyWay(head + 2, plat, visited);
	p2.first += 3 * abs(plat[head + 2] - plat[head]);
	p2.second += 1;
	if (p1.first < p2.first)
	{
		visited[head] = p1;
		return p1;
	}
	else if (p2.first < p1.first)
	{
		visited[head] = p2;
		return p2;
	}
	else if (p1.second < p2.second)
	{
		visited[head] = p1;
		return p1;
	}
	else {
		visited[head] = p2;
		return p2;
	}
}

int main()
{
	int N;
	cin >> N;
	vector<int> plat(N);
	for (int i = 0; i < N; i++)
		cin >> plat[i];
	vector<pair<int, int>> visited(N, make_pair(-1, -1));
	pair<int, int> result = EasyWay(0, plat, visited);
	cout << result.first;
	return 0;
}

