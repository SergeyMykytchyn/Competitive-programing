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
	int sum = 0, min = 0, max = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] > 0)
			sum += a[i];
		if (a[i] < a[min])
			min = i;
		if (a[i] > a[max])
			max = i;

	}
	int mul = 1;
	if (max < min)
	{
		int c = min;
		min = max;
		max = c;
	}
	for (int i = min + 1; i < max; i++)
		mul *= a[i];
	ofstream fout("OUTPUT.txt");
	fout << sum << " " << mul;
	fout.close();
	delete[] a;
	return 0;
}