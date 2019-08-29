#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	int N;
	ifstream fin("INPUT.txt");
	fin >> N;
	int* a = new int[N];
	for (int i = 0; i < N; i++)
		fin >> a[i];
	fin.close();
	int k = 0;
	for (int i = 0; i < N - 1; i++)
		if (a[i] + 1 != a[i + 1])
			k++;
	ofstream fout("OUTPUT.txt");
	fout << k;
	fout.close();
	delete[] a;
	return 0;
}