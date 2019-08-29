#include <stdio.h>
#include <fstream>
using namespace std;

void Merge(int* a, int l, int m, int r)
{
	int n1 = m - l + 1;
	int n2 = r - m;
	int* L = new int[n1];
	int* R = new int[n2];
	for (int i = 0; i < n1; i++)
		L[i] = a[l + i];
	for (int i = 0; i < n2; i++)
		R[i] = a[m + 1 + i];
	int i = 0, j = 0, k = l;
	while (i < n1&&j < n2)
	{
		if (L[i] < R[j])
		{
			a[k] = L[i];
			i++;
		}
		else {
			a[k] = R[j];
			j++;
		}
		k++;
	}
	while (i < n1)
	{
		a[k] = L[i];
		i++;
		k++;
	}
	while (j < n2)
	{
		a[k] = R[j];
		j++;
		k++;
	}
	delete[] L;
	delete[] R;
}

void MergeSort(int* a, int l, int r)
{
	if (l < r)
	{
		int m = (l + r) / 2;
		MergeSort(a, l, m);
		MergeSort(a, m + 1, r);
		Merge(a, l, m, r);
	}
}

int main()
{
	int n;
	ifstream fin("INPUT.txt");
	fin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; i++)
		fin >> a[i];
	fin.close();
	MergeSort(a, 0, n - 1);
	ofstream fout("OUTPUT.txt");
	for (int i = 0; i < n; i++)
		fout << a[i] << " ";
	fout.close();
	delete[] a;
	return 0;
}