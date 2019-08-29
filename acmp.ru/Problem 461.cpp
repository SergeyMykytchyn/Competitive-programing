#include <iostream>
#include <fstream>
using namespace std;

void Swap(int& a, int& b)
{
	int c = b;
	b = a;
	a = c;
}

void SelectionSort(int* a, int n)
{
	int min;
	for (int i = 0; i < n - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < n; j++)
			if (a[j] < a[min])
				min = j;
		Swap(a[i], a[min]);
	}
}

int main()
{
	int N;
	ifstream fin("INPUT.txt");
	fin >> N;
	int* a = new int[N];
	for (int i = 0; i < N; i++)
		fin >> a[i];
	fin.close();
	SelectionSort(a, N);
	ofstream fout("OUTPUT.txt");
	int sum = 0;
	for (int i = 0; i < N / 2 + 1; i++)
		sum += a[i] / 2 + 1;
	fout << sum;
	fout.close();
	delete[] a;
	return 0;
}