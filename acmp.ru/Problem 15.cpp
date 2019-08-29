#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream f("INPUT.txt");
	int n;
	f >> n;
	int** a = new int*[n];
	int i, c = 0;
	for (i = 0; i < n; i++)
		a[i] = new int[n];
	for (i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			f >> a[i][j];
			if (a[i][j] == 1)
				c++;
		}
	ofstream fo("OUTPUT.txt");
	fo << c / 2;
	for (i = 0; i < n; i++)
		delete[] a[i];
	delete[] a;
	return 0;
}