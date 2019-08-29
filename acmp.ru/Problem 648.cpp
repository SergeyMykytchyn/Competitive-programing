#include <iostream>
#include <fstream>
using namespace std;

void Swap(int& a, int& b)
{
	int c = a;
	a = b;
	b = c;
}

void BubbleSort(int* a, int N)
{
	bool swapped = false;
	for (int i = 0; i < N - 1; i++)
	{
		swapped = false;
		for (int j = 0; j < N - 1 - i; j++)
			if (a[j] < a[j + 1])
			{
				Swap(a[j], a[j + 1]);
				swapped = true;
			}
		if (swapped == false)
			break;
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
	BubbleSort(a, N);
	int player_sum = 0, krupie_sum = 0;
	for (int i = 0; i < N / 2; i++)
		player_sum += a[i];
	for (int i = N / 2; i < N; i++)
		krupie_sum += a[i];
	int sum = player_sum - krupie_sum;
	ofstream fout("OUTPUT.txt");
	fout << sum;
	fout.close();
	delete[] a;
	return 0;
}