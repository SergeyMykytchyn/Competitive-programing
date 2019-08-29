#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
using namespace std;

struct edge {
	int a, b, cost;
};
int main()
{
	ifstream f("INPUT.txt");
	int n, m, a, b, w, Nedg;
	bool flag = 0;
	f >> n >> m;
	vector<edge> e;
	Nedg = m;
	for (int j = 0; j < Nedg; j++)
	{
		f >> a >> b >> w;
		a--;
		b--;
		if (a == b)
		{
			m--;
			continue;
		}
		for (size_t i = 0; i < e.size(); i++)
			if (e[i].a == a && e[i].b == b)
			{
				if (w < e[i].cost)
					e[i].cost = w;
				m--;
				flag = 1;
				break;
			}
		if (!flag)
		{
			edge ed;
			ed.a = a;
			ed.b = b;
			ed.cost = w;
			e.push_back(ed);
		}
		flag = 0;
	}
	for (int i = 0; i < m; i++)
	{
		cout << e[i].a << " " << e[i].b << " " << e[i].cost << endl;
	}
	const int INF = INT_MAX;
	vector<int> d(n, INF);
	int v = 0;
	d[v] = 0;
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < m; j++)
			if (d[e[j].a] < INF)
				if (d[e[j].b] > d[e[j].a] + e[j].cost)
					d[e[j].b] = d[e[j].a] + e[j].cost;
	ofstream fout("OUTPUT.txt");
	for (int i = 0; i < n; i++)
	{
		if (d[i] != INF)
			fout << d[i] << " ";
		else fout << 30000 << " ";
	}
	f.close();
	fout.close();
	return 0;
}