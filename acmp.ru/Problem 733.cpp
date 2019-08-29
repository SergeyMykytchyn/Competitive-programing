#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	int n;
	ifstream fin("INPUT.txt");
	fin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; i++)
		fin >> a[i];
	fin.close();
	int k = n;
	for (int i = 1; i < k - 1; i++)
	{
		if (a[i] < a[i - 1])
		{
			int c;
			for (c = i + 1; c < k; c++)
				if (a[i] < a[c])
					break;
			if (c == k)
				continue;
			int j = i;
			while (j < k - 1)
			{
				a[j] = a[j + 1];
				j++;
			}
			k--;
			i--;
		}
	}
	ofstream fout("OUTPUT.txt");
	fout << k << "\n";
	for (int i = 0; i < k; i++)
		fout << a[i] << " ";
	fout.close();
	delete[] a;
	return 0;
}