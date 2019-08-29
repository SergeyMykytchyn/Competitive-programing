#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct el {
	int val;
	bool visited;
};

struct st {
	int val;
	int cnt;
	void operator = (const st& ob);
};

void st :: operator = (const st& ob)
{
	val = ob.val;
	cnt = ob.cnt;
}

void Sort(vector<int>& vec)
{
	for (size_t i = 0; i < vec.size(); i++)
	{
		int key = vec[i];
		int j = i - 1;
		while (j >= 0 && key < vec[j])
		{
			vec[j + 1] = vec[j];
			j--;
		}
		vec[j + 1] = key;
	}
}

int SortByCnt(vector<st>& v)
{
	for (size_t i = 1; i < v.size(); i++)
	{
		st key = v[i];
		int j = i - 1;
		while (j >= 0 && key.cnt > v[j].cnt)
		{
			v[j + 1] = v[j];
			j--;
		}
		v[j + 1] = key;
	}
	vector<int> vec;
	int i = 0;
	st key = v[0];
	while (key.cnt == v[i].cnt)
	{
		vec.push_back(v[i].val);
		i++;
	}
	vec.resize(vec.size());
	Sort(vec);
	for (size_t i = 0; i < vec.size(); i++)
		cout << vec[i] << " ";
	return vec[0];
}

int main()
{
	int n;
	ifstream fin("INPUT.txt");
	fin >> n;
	el* a = new el[n];
	for (int i = 0; i < n; i++)
	{
		fin >> a[i].val;
		a[i].visited = 0;
	}
	fin.close();
	vector<st> v;
	for (int i = 0; i < n; i++)
	{
		if (!a[i].visited)
		{
			st s;
			s.val = a[i].val;
			s.cnt = 0;
			for (int j = 0; j < n; j++)
			{
				if (a[i].val == a[j].val)
				{
					a[j].visited = 1;
					s.cnt++;
				}
			}
			v.push_back(s);
		}
	}
	int x = SortByCnt(v);
	int k = 0, j, i = 0;
	for (; i < n - k; i++)
	{
		if (a[i].val == x)
		{
			for (j = i; j < n - 1 - k; j++)
				a[j].val = a[j + 1].val;
			a[j].val = x;
			k++;
			i = -1;
		}
	}
	ofstream fout("OUTPUT.txt");
	for (int i = 0; i < n; i++)
		fout << a[i].val << " ";
	fout.close();
	delete[] a;
	return 0;
}