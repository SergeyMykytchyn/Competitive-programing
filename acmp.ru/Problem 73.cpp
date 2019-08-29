#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int in(char ch)
{
	if (ch <= '9')
		return ch - '0';
	else return ch - 'A' + 10;

}

int SumMod27(int ind, int n)
{
	for (int i = 1; i <= 27; i++)
		if ((i + ind) % 27 == n)
			return i;
}

int ch(int a)
{
	if (a == 27)
		return 32;
	return 'a' - 1 + a;
}

int main()
{
	string st;
	ifstream fin("INPUT.txt");
	fin >> st;
	fin.close();
	string result;
	for (size_t i = 0; i < st.size(); i++)
	{
		int n = in(st[i]);
		int x = SumMod27(i + 1, n);
		result.push_back(ch(x));
	}
	ofstream fout("OUTPUT.txt");
	fout << result;
	fout.close();
	return 0;
}