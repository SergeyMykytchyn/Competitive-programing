#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct edge {
	int b, color;
};

vector< vector<edge> > e;

int dfs(int v, vector<int>& colors, size_t& colors_index)
{
	if (colors.size() == colors_index)
		return v;
	int color = colors[colors_index];
	for (size_t i = 0; i < e[v].size(); i++)
	{
		if (e[v][i].color == color)
		{
			colors_index++;
			return dfs(e[v][i].b, colors, colors_index);
		}
	}
	return -1;
}

int main()
{
	int n, m;
	ifstream f("INPUT.txt");
	f >> n >> m;
	e.resize(n);
	int a, b, color;
	edge ed;
	for (int i = 0; i < m; i++)
	{
		f >> a >> b >> color;
		a--; b--;
		ed.b = b;
		ed.color = color;
		e[a].push_back(ed);

		ed.b = a;
		e[b].push_back(ed);
	}
	int k;
	f >> k;
	vector<int> colors(k);
	for (int i = 0; i < k; i++)
		f >> colors[i];
	size_t colors_index = 0;
	ofstream fout("OUTPUT.txt");
	int v = dfs(0, colors, colors_index);
	if (v == -1)
		fout << "INCORRECT";
	else fout << v + 1;
	f.close();
	fout.close();
	return 0;
}