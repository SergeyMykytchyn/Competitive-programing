#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Graph {
private:
	int n, m;
	vector< vector<int> > g;
public:
	void make_graph(int N, int M);
	void Work(vector<bool>& land);
	void dfs(int v, vector<bool>& land, vector<bool>& visited);
};

int main()
{
	Graph g;
	ifstream f("INPUT.txt");
	int N, M;
	char ch;
	f >> N >> M;
	g.make_graph(N, M);
	vector<bool> land(N*M, 0);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			f >> ch;
			if (ch == '#')
			{
				int v = i * M + j;
				land[v] = 1;
			}
		}
	f.close();
	g.Work(land);
	return 0;
}

void Graph::make_graph(int N, int M)
{
	n = N * M;
	m = (M - 1)*N + (N - 1)*M;
	g.resize(n);
	int t = 0, i, k = 1;
	for (int j = 0; j < N - 1; j++)
	{
		for (i = t; i < k*M - 1; i++)
		{
			g[i].push_back(i + 1);
			g[i + 1].push_back(i);

			g[M + i].push_back(i);
			g[i].push_back(M + i);
		}
		g[M + i].push_back(i);
		g[i].push_back(M + i);
		t += M;
		k++;
	}
	for (i = t; i < k*M - 1; i++)
	{
		g[i].push_back(i + 1);
		g[i + 1].push_back(i);
	}
}

void Graph::Work(vector<bool>& land)
{
	vector<bool> visited(n, 0);
	ofstream f("OUTPUT.txt");
	int c = 0;
	for (int i = 0; i < n; i++)
		if (land[i] == 1 && !visited[i])
		{
			dfs(i, land, visited);
			c++;
		}
	f << c;
	f.close();
}

void Graph::dfs(int v, vector<bool>& land, vector<bool>& visited)
{
	visited[v] = 1;
	for (size_t i = 0; i < g[v].size(); i++)
	{
		if (!visited[g[v][i]] && land[g[v][i]] == 1)
			dfs(g[v][i], land, visited);
	}
}