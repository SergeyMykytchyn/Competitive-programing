// Image Matching.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

vector < vector<pair<int, int>>> findRegions(vector<vector<int>> grid)
{
	vector<vector<bool>> visited(grid.size(), vector<bool>(grid.size(), 0));
	vector < vector<pair<int, int>>> region(grid.size()*grid.size());
	int k = 0;
	for (int k1 = 0; k1 < grid.size(); k1++)
		for (int k2 = 0; k2 < grid.size(); k2++)
			if (!visited[k1][k2] && grid[k1][k2] == 1)
			{
				vector<pair<int, int>> queue;
				queue.push_back(make_pair(k1, k2));
				region[k].resize(grid.size()*grid.size());
				int it = 0;
				while (queue.size() > 0)
				{
					int i = queue[0].first, j = queue[0].second;
					visited[i][j] = 1;
					region[k][it] = make_pair(i, j);
					it++;
					queue.erase(queue.begin());
					if (i - 1 >= 0)
						if (grid[i - 1][j] == 1 && !visited[i - 1][j])
							queue.push_back(make_pair(i - 1, j));
					if (j - 1 >= 0)
						if (grid[i][j - 1] == 1 && !visited[i][j - 1])
							queue.push_back(make_pair(i, j - 1));
					if (j + 1 < grid.size())
						if (grid[i][j + 1] == 1 && !visited[i][j + 1])
							queue.push_back(make_pair(i, j + 1));
					if (i + 1 < grid.size())
						if (grid[i + 1][j] == 1 && !visited[i + 1][j])
							queue.push_back(make_pair(i + 1, j));
				}
				region[k].resize(it);
				k++;
			}
	region.resize(k);

	for (int i = 0; i < region.size(); i++)
	{
		for (int j = 0; j < region[i].size(); j++)
			cout << "(" << region[i][j].first << " " << region[i][j].second << ")" << " ";
		cout << "\n";
	}

	return region;
}

int main()
{
	ifstream fin("input3.txt");
	int n;
	fin >> n;
	vector<vector<int>> grid1(n);
	for (int i = 0; i < n; i++)
	{
		grid1[i].resize(n);
		for (int j = 0; j < n; j++)
			fin >> grid1[i][j];
	}
	fin >> n;
	vector<vector<int>> grid2(n);
	for (int i = 0; i < n; i++)
	{
		grid2[i].resize(n);
		for (int j = 0; j < n; j++)
			fin >> grid2[i][j];
	}
	vector < vector<pair<int, int>>> region1;
	vector < vector<pair<int, int>>> region2;
	region1 = findRegions(grid1);
	cout << "\n";
	region2 = findRegions(grid2);
	vector<bool> visited(region1.size(), 0);
	for(int i=0;i<region2.size();i++)
		for(int k=0;k<region1.size();k++)
			if (!visited[k] && region2[i].size() == region1[k].size())
			{
				int count = 0;
				bool find;
				for (int j = 0; j < region2[i].size(); j++)
				{
					find = false;
					for (int l = 0; l < region1[k].size(); l++)
						if (region2[i][j].first == region1[k][l].first && region2[i][j].second == region1[k][l].second)
						{
							count++;
							find = true;
							break;
						}
					if (!find)
						break;
				}
				if (count == region1[k].size())
					visited[k] = 1;
			}
	int res = 0;
	for (int i = 0; i < region1.size(); i++)
		if (visited[i])
			res++;
	cout << res;
	return 0;
}
