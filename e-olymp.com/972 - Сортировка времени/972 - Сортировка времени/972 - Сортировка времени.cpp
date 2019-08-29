// 972 - Сортировка времени.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

struct MyTime
{
	int hour, min, sec;
};

MyTime lst[100];

int f(MyTime a, MyTime b)
{
	if ((a.hour == b.hour) && (a.min == b.min)) return a.sec < b.sec;
	if (a.hour == b.hour) return a.min < b.min;
	return a.hour < b.hour;
}

int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	int n, i;
	fin >> n;

	for (i = 0; i < n; i++)
		fin >> lst[i].hour >> lst[i].min >> lst[i].sec;

	sort(lst, lst + n, f);

	for (i = 0; i < n; i++)
		fout << lst[i].hour << " " << lst[i].min << " " << lst[i].sec << "\n";

	return 0;
}


