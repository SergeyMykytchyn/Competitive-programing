#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	int N;
	ifstream fin("INPUT.txt");
	fin >> N;
	int* a = new int[N];
	int* b = new int[N];
	int k = 0, j = 0, x;
	for (int i = 0; i < N; i++)
	{
		fin >> x;
		if (x % 2 == 1)
		{
			a[k] = x;
			k++;
		}
		else
		{
			b[j] = x;
			j++;
		}
	}
	fin.close();
	ofstream fout("OUTPUT.txt");
	for (int i = 0; i < k; i++)
		fout << a[i] << " ";
	fout << "\n";
	for (int i = 0; i < j; i++)
		fout << b[i] << " ";
	fout << "\n";
	if (j >= k)
		fout << "YES \n";
	else fout << "NO \n";
	fout.close();
	delete[] a;
	delete[] b;
	return 0;
}