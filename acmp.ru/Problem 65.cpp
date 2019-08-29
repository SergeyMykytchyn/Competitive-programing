#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct st {
	int index;
	int min;
	void operator = (const st& ob);
};

void st:: operator = (const st& ob)
{
	index = ob.index;
	min = ob.min;
}

void Swap(st& a, st& b)
{
	st c = b;
	b = a;
	a = c;
}

void StableSelectionSort(st* a, int n)
{
	int min_ind;
	for (int i = 0; i < n - 1; i++)
	{
		min_ind = i;
		for (int j = i + 1; j < n; j++)
			if (a[j].min < a[min_ind].min)
				min_ind = j;
		st key = a[min_ind];
		while (min_ind > i)
		{
			a[min_ind] = a[min_ind - 1];
			min_ind--;
		}
		a[i] = key;
	}
}

int main()
{
	string message;
	ifstream fin("INPUT.txt");
	fin >> message;
	int n;
	fin >> n;
	ofstream fout("OUTPUT.txt");
	if (n == 0)
	{
		fout << n;
		fout.close();
		fin.close();
		return 0;
	}
	string* mes = new string[n];
	for (int i = 0; i < n; i++)
		fin >> mes[i];
	fin.close();
	st* a = new st[n];
	for (int j = 0; j < n; j++)
	{
		int k = 0;
		for (size_t i = 0; i < message.size(); i++)
			if (message[i] != mes[j][i])
				k++;
		a[j].min = k;
		a[j].index = j + 1;
	}
	StableSelectionSort(a, n);
	int c = 0;
	for (int i = 0; i < n; i++)
		if (a[i].min == a[0].min)
			c++;
	fout << c << "\n";
	int i = 0;
	while (a[i].min == a[0].min)
	{
		fout << a[i].index << " ";
		i++;
	}
	fout.close();
	delete[] mes;
	delete[] a;
	return 0;
}