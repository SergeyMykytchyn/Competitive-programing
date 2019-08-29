#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main()
{
	int n;
	ifstream fin("INPUT.txt");
	fin >> n;
	fin.close();
	vector<int> a(10001);
	vector<int> b(10001);
	a[1] = 2;
	a[2] = 3;
	a[3] = 4;
	a[4] = 7;
	b[1] = 1;
	b[2] = 5;
	b[3] = 6;
	b[4] = 8;
	int k = 5;
	for (int i = 5; i <= n; i++)
	{
		a[i] = b[i - 1] + b[i - 3];
		for (int j = a[i - 1] + 1; j < a[i] && k < 10001; j++)
		{

			if (j > 8) {
				b[k] = j;
				k++;
			}
		}
	}
	ofstream fout("OUTPUT.txt");
	fout << a[n] << "\n";
	fout << b[n];
	fout.close();
	return 0;
}