// 1685 - Землі Антарктиди.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream file("input2.txt");
	int n;
	//cin >> n;
	file >> n;
	int* x = new int[n];
	int* y = new int[n];
	bool** graph = new bool*[n];
	bool* visited = new bool[n];
	for (int i = 0; i < n; i++)
	{
		//cin >> x[i] >> y[i];
		file >> x[i] >> y[i];
		graph[i] = new bool[n];
		visited[i] = false;
		for (int j = 0; j < n; j++)
			graph[i][j] = false;


	}
	for(int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (abs(x[i] - x[j]) <= 1 && abs(y[i] - y[j]) <= 1)
			{
				graph[i][j] = true;
				graph[j][i] = true;
			}
	/*for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << graph[i][j] << " ";
		cout << endl;
	}*/
	int v, count = 0, head, end;
	bool flag = 0;
	for (int j = 0; j < n; j++)
	{
		if (visited[j])
			continue;
		int* queue1 = new int[n];
		head = 0;
		end = 0;
		queue1[head] = j;
		do {
			v = queue1[head];
			head++;
			visited[v] = true;
			for (int i = 0; i < n; i++)
				if (graph[v][i] && !visited[i])
				{
					end++;
					flag = 0;
					for(int k=0;k<end;k++)
						if (queue1[k] == i)
						{
							flag = 1;
							break;
						}
					if (flag)
					{
						end--;
						continue;
					}
					queue1[end] = i;
				}
		} while (head <= end);
		count++;
		delete[] queue1;
	}
	cout << count;
	delete[] x;
	delete[] y;
	delete[] visited;
	for (int i = 0; i < n; i++)
		delete[] graph[i];
	delete[] graph;
 	return 0;
}

