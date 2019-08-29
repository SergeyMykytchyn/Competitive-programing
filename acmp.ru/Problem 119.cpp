#include <iostream>
#include <fstream>
using namespace std;

struct time {
	int h, m, s;
	void operator = (const time& t);
};

void time :: operator = (const time& t)
{
	h = t.h;
	m = t.m;
	s = t.s;
}

void InsertionSort(time* a, int N)
{
	for (int i = 1; i < N; i++)
	{
		time key = a[i];
		int j = i - 1;
		while (j >= 0 && key.h < a[j].h)
		{
			a[j + 1] = a[j];
			j--;
		}
		if (key.h == a[j].h)
		{
			while (j >= 0 && key.m < a[j].m&&key.h == a[j].h)
			{
				a[j + 1] = a[j];
				j--;
			}
			if (key.m == a[j].m)
			{
				while (j >= 0 && key.s < a[j].s&&key.m == a[j].m&&key.h == a[j].h)
				{
					a[j + 1] = a[j];
					j--;
				}
			}
		}
		a[j + 1] = key;
	}
}

int main()
{
	int N;
	ifstream fin("INPUT.txt");
	fin >> N;
	time* a = new time[N];
	for (int i = 0; i < N; i++)
		fin >> a[i].h >> a[i].m >> a[i].s;
	fin.close();
	InsertionSort(a, N);
	ofstream fout("OUTPUT.txt");
	for (int i = 0; i < N; i++)
		fout << a[i].h << " " << a[i].m << " " << a[i].s << "\n";
	fout.close();
	delete[] a;
	return 0;
}