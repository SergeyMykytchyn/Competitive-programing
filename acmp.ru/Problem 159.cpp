#include <iostream>
#include <fstream>
using namespace std;

struct el {
	int val;
	int ind;
	void operator = (const el& ob);
};

void el :: operator = (const el& ob)
{
	val = ob.val;
	ind = ob.ind;
}

void InsertionSort(el* a, int N)
{
	for (int i = 1; i < N; i++)
	{
		el key = a[i];
		int j = i - 1;
		while (key.val < a[j].val&&j >= 0)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = key;
	}
}

int main()
{
	int N;
	ifstream fin("INPUT.txt");
	fin >> N;
	el* a = new el[N];
	for (int i = 0; i < N; i++)
	{
		fin >> a[i].val;
		a[i].ind = i + 1;
	}
	fin.close();
	InsertionSort(a, N);
	ofstream fout("OUTPUT.txt");
	for (int i = 0; i < N; i++)
		fout << a[i].ind << " ";
	fout.close();
	delete[] a;
	return 0;
}