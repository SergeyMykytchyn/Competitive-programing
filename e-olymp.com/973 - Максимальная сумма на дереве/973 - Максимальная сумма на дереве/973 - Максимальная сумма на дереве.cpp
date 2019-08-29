// 973 - Максимальная сумма на дереве.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

vector< vector<int> > g;
vector<int> dp1, dp2, cost;

void dfs(int v, int parent = -1)
{
	dp1[v] = cost[v];
	dp2[v] = 0;

	for (int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];

		if (to == parent) continue;

		dfs(to, v);

		dp1[v] += dp2[to];

		dp2[v] += max(dp1[to], dp2[to]);
	}
}

int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	int n, i, u, v;
	fin >> n;
	g.resize(n + 1);
	for (i = 1; i < n; i++)
	{
		fin >> u >> v;
		g[u].push_back(v);

		g[v].push_back(u);
	}

	dp1.resize(n + 1); dp2.resize(n + 1);

	cost.resize(n + 1);

	for (i = 1; i <= n; i++)
		fin >> cost[i];

	dfs(1);

	int ans = max(dp1[1], dp2[1]);
	fout << ans << "\n";

	return 0;
}

