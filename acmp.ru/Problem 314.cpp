#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

bool Greater(int a, int b)
{
	vector<int> A;
	vector<int> B;
	while (a)
	{
		A.push_back(a % 10);
		a /= 10;
	}
	while (b)
	{
		B.push_back(b % 10);
		b /= 10;
	}
	reverse(A.begin(), A.end());
	reverse(B.begin(), B.end());
	size_t i = 0, j = 0;
	while (i < A.size() && j < B.size())
	{
		if (A[i] > B[j])
			return 1;
		else if (A[i] < B[j])
			return 0;
		i++;
		j++;
	}
	if (i < A.size())
		return 1;
	else return 0;
}

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
		if (Greater(R[j], L[i]))
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
		k++;
		i++;
	}
	while (j < n2)
	{
		a[k] = R[j];
		k++;
		j++;
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

	int N, K;
	ifstream fin("INPUT.txt");
	fin >> N >> K;
	int* a = new int[N];
	for (int i = 1; i <= N; i++)
		a[i - 1] = i;
	MergeSort(a, 0, N - 1);
	ofstream fout("OUTPUT.txt");
	for (int i = 0; i < N; i++)
		if (a[i] == K)
		{
			fout << i + 1;
			break;
		}
	fout.close();
	delete[] a;
	return 0;
}