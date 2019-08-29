#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

bool Was(vector<int>& v, int i)
{
	if (v.empty())
		return false;
	if ((*v.begin()) == i)
	{
		v.erase(v.begin());
		return true;
	}
	return false;
}

int main()
{
	int n;
	ifstream fin("INPUT.txt");
	fin >> n;
	fin.close();
	vector<int> v;
	int a = 1;
	for (int i = 2; i <= n; i++)
	{
		if (Was(v, i))
		{
			a += 3;
			v.push_back(a);
		}
		else {
			a += 2;
			v.push_back(a);
		}
	}
	ofstream fout("OUTPUT.txt");
	fout << a;
	fout.close();
	return 0;
}