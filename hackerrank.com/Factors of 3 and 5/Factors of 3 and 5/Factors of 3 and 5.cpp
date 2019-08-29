// Factors of 3 and 5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

bool Ideal(long x)
{
	
	if (x % 3 != 0)
		if (x % 5 != 0 && x != 1)
			return 0;
	while (x % 3 == 0)
		x /= 3;
	while (x % 5 == 0)
		x /= 5;
	if (x == 1)
		return 1;
	return 0;
}

int main()
{
	//int n;
	//cin >> n;
	//cout << Ideal(n);
	int l, r, count = 0;
	long long t;
	cin >> l >> r;
	ofstream fout1("output1.txt");
	//vector<vector<bool>> ideal(20, vector<bool>(14, 0));
	bool flag;
	for (int i = 0; i < 20; i++)
	{
		flag = false;
		for (int j = 0; j < 14; j++)
		{
			t = pow(3, i)*pow(5, j);
			if (t <= r && t >= l)
			{
				flag = true;
				count++;
				fout1 << t << "\n";
			}
		}
		if (!flag && pow(3, i)>=l)
			break;
	}
	fout1 << "\n" << count;
	fout1.close();
	cout << "Here \n";
	ofstream fout2("output2.txt");
	count = 0;
	for (int i = l; i <= r; i++)
		if (Ideal(i))
		{
			fout2 << i << "\n";
			count++;
		}
	fout2 << "\n" << count;
	fout2.close();
	cout << count;
	return 0;
}

