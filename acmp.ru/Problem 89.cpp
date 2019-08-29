#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

struct train {
	string name;
	int tm;
	void operator = (const train& ob);
};

void train :: operator = (const train& ob)
{
	name = ob.name;
	tm = ob.tm;
}

int HowLong(int tinH, int tinM, int toffH, int toffM)
{
	int in = 60 * tinH + tinM;
	int off = 60 * toffH + toffM;
	if (off < in)
		return in - off;
	else if (off > in)
		return 24 * 60 - off + in;
	else return 24 * 60;
}

void Merge(train* a, int l, int m, int r)
{
	int n1 = m - l + 1;
	int n2 = r - m;
	train* L = new train[n1];
	train* R = new train[n2];
	for (int i = 0; i < n1; i++)
		L[i] = a[l + i];
	for (int i = 0; i < n2; i++)
		R[i] = a[m + 1 + i];
	int i = 0, j = 0, k = l;
	while (i < n1&&j < n2)
	{
		if (L[i].tm < R[j].tm)
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
		i++;
		k++;
	}
	while (j < n2)
	{
		a[k] = R[j];
		j++;
		k++;
	}
	delete[] L;
	delete[] R;
}

void MergeSort(train* a, int l, int r)
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
	int n;
	ifstream fin("INPUT.txt");
	fin >> n;
	train* a = new train[n];
	int tinH, tinM, toffH, toffM;
	char ch;
	int k = 0;
	char* name = new char[51];
	for (int i = 0; i < n; i++)
	{
		fin.get();
		k = 0;
		fin.get(name[k]);
		do {
			k++;
			fin.get(name[k]);

		} while (name[k] != '"');
		k++;
		name[k] = '\0';
		//cout << name << endl;
		a[i].name.resize(k);
		for (int j = 0; j < k; j++)
		{
			a[i].name[j] = name[j];
			//cout << a[i].name[j] << endl;
		}
		//cout << a[i].name << endl;
		fin >> toffH >> ch >> toffM >> tinH >> ch >> tinM;
		a[i].tm = HowLong(tinH, tinM, toffH, toffM);
	}
	fin.close();
	MergeSort(a, 0, n - 1);
	train fastest = a[0];
	int speed;
	//cout << fastest.time << endl;
	//cout << 650*60./fastest.time << endl;
	double speed_dec = 650 * 60. / fastest.tm - floor(650 * 60. / fastest.tm);
	//cout << floor(650*60./fastest.time) << endl;
	//cout << speed_dec <<endl;
	if (speed_dec >= 0.5)
		speed = ceil(650 * 60. / fastest.tm);
	else speed = floor(650 * 60. / fastest.tm);
	ofstream fout("OUTPUT.txt");
	fout << "The fastest train is " << fastest.name << ".\n";
	fout << "Its speed is " << speed << " km/h, approximately.";
	fout.close();
	delete[] a;
	return 0;
}