// 1070 - Закраска прямой.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#define MAX 300001

using namespace std;

class Point
{
	public:
	int x;
	char c; // 'b' – начало отрезка, 'e' – конец отрезка
	Point(void)
	{
		x = 0; c = '-';
	}
	Point(int x, char c) : x(x), c(c) {};
};

Point p[MAX];

int f(Point a, Point b)
{
	return a.x < b.x;
}

int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	int n, i, x, y;
	fin >> n;

	for (i = 0; i < 2 * n; i += 2)
	{
		fin >> x >> y;

		p[i] = Point(x, 'b');

		p[i + 1] = Point(y, 'e');
	}

	sort(p, p + 2 * n, f);


	int depth = 0, len = 0;

	for (i = 0; i < 2 * n - 1; i++) // двигаемся по отрезку [p[i]...p[i+1]

	{

		if (p[i].c == 'b') depth++;

		if (p[i].c == 'e') depth--;

		if (depth > 0) len += p[i + 1].x - p[i].x;

	}

	fout << len << "\n";
	return 0;
}


