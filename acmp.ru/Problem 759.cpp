#include <iostream>
#include <fstream>
using namespace std;

void Swap(int& a, int& b)
{
	int c = b;
	b = a;
	a = c;
}

void SelectionSort(int* a, int N)
{
	int max_ind;
	for (int i = 0; i < N - 1; i++)
	{
		max_ind = i;
		for (int j = i + 1; j < N; j++)
			if (a[j] > a[max_ind])
				max_ind = j;
		Swap(a[i], a[max_ind]);
	}
}

int main()
{
	int N, M;
	ifstream fin("INPUT.txt");
	fin >> N >> M;
	int* a = new int[N];
	for (int i = 0; i < N; i++)
		fin >> a[i];
	fin.close();
	SelectionSort(a, N);
	int sum = 0;
	for (int i = 0; i < M; i++)
		if (a[i] > 0)
			sum += a[i];
	ofstream fout("OUTPUT.txt");
	fout << sum;
	fout.close();
	delete[] a;
	return 0;
}