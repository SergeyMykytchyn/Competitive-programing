#include <iostream>
#include <fstream>
using namespace std;

class Graph {
private:
	int** E;
	int n, m;
public:
	Graph();
	~Graph();
	bool InitGraph(int n, int m);
	void addEdge(int v1, int v2);
	void Work();
};

bool operator >> (ifstream& f, Graph& g);

int main()
{
	Graph g;
	ifstream f("INPUT.txt");
	f >> g;
	g.Work();
	return 0;
}

Graph::Graph() : E(nullptr), n(0), m(0) {}

Graph :: ~Graph()
{
	for (int i = 0; i < n; i++)
		if (E[i] != nullptr)
			delete[] E[i];
	if (E != nullptr)
		delete[] E;
}

bool Graph::InitGraph(int n, int m)
{
	this->n = n;
	this->m = m;
	E = new(nothrow) int*[n];
	if (E == nullptr)
		return false;
	for (int i = 0; i < n; i++)
	{
		E[i] = new(nothrow) int[n];
		if (E[i] == nullptr)
			return false;
		for (int j = 0; j < n; j++)
			E[i][j] = 0;
	}
	return true;
}

void Graph::addEdge(int v1, int v2)
{
	E[v1][v2] = 1;
	E[v2][v1] = 1;
}

bool operator >> (ifstream& f, Graph& g)
{
	int n, m, v1, v2;
	f >> n >> m;
	g.InitGraph(n, m);
	for (int i = 0; i < m; i++)
	{
		f >> v1 >> v2;
		g.addEdge(v1 - 1, v2 - 1);
	}
	f.close();
	return true;
}

void Graph::Work()
{
	int* p = new int[n];
	for (int i = 0; i < n; i++)
		p[i] = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (E[i][j] == 1)
				p[i]++;
	ofstream f("OUTPUT.txt");
	for (int i = 0; i < n; i++)
		f << p[i] << ' ';
	delete[] p;
	f.close();
}