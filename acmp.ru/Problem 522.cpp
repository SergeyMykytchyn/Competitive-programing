#include <iostream>
#include <fstream>
using namespace std;

void InsertionSort(int* a, int N)
{
	int key, n = N;
	for (int i = 1; i < n; i++)
	{
		key = a[i];
		int j = i - 1;
		while (j >= 0 && key < a[j])
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = key;
	}
}

int main()
{
	int M, N;
	ifstream fin("INPUT.txt");
	fin >> M >> N;
	int* a = new int[M];
	int* b = new int[N];
	for (int i = 0; i < M; i++)
		fin >> a[i];
	for (int i = 0; i < N; i++)
		fin >> b[i];
	fin.close();
	InsertionSort(a, M);
	InsertionSort(b, N);
	ofstream fout("OUTPUT.txt");
	bool flag = false;
	int i = 0, j = 0;
	while (i < M&&j < N)
	{
		if (a[i] != b[j])
		{
			if (b[j - 1] == a[i])
			{
				i++;
			}
			else if (a[i - 1] == b[j])
				j++;
			else { flag = true; break; }

		}
		else {
			i++;
			j++;
		}
	}
	while (i < M)
	{
		if (a[i] != b[j - 1])
		{
			flag = true;
			break;
		}
		i++;
	}
	while (j < N)
	{
		if (b[j] != a[i - 1])
		{
			flag = true;
			break;
		}
		j++;
	}
	if (flag)
		fout << 0;
	else fout << 1;
	fout.close();
	delete[] a;
	delete[] b;
	return 0;
}