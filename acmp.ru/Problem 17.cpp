#include <stdio.h>
#include <fstream>
using namespace std;

bool IsCycle(int* a, int n, int ind, int len)
{
	for (int j = 0; j < n; j++)
	{
		if (ind + j >= len)
			return 0;
		if (a[j] != a[ind + j])
			return 0;
	}
	if (ind + n < len - 1)
		if (IsCycle(a, n, ind + n, len))
			return 1;
		else return 0;
	else  if (ind + n == len - 1)
		return 1;
	else return 0;

}

int main()
{
	int n;
	ifstream fin("INPUT.txt");
	fin >> n;
	int* a = new int[n];
	int key;
	for (int i = 0; i < n; i++)
		fin >> a[i];
	fin.close();
	key = a[0];
	int k, i;
	for (i = 1; i < n - 1; i++)
	{
		if (a[i] == key && ((n - 1) % i == 0))
		{
			if (IsCycle(a, i, i, n))
			{
				k = i;
				break;
			}
		}
	}
	if (i == n - 1)
		k = n - 1;
	ofstream fout("OUTPUT.txt");
	fout << k;
	fout.close();
	delete[] a;
	return 0;
}