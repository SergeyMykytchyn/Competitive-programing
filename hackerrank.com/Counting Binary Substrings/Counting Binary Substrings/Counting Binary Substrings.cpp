// Counting Binary Substrings.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int counting(string s) 
{
	vector<int> v;
	v.push_back(1);
	for (int i = 1; i < s.length(); i++)
		if (s[i - 1] != s[i])
			v.push_back(1);
		else
			v.back()++;
	int res = 0;
	for (int i = 1; i < v.size(); i++)
		res += min(v[i - 1], v[i]);
	return res;
}

int main()
{
	string s;
	cin >> s;
	cout << counting(s);
	return 0;
}

