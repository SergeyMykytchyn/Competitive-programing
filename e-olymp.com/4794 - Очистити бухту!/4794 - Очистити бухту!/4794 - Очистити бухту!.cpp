// 4794 - Очистити бухту!.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <math.h>

using namespace std;

double findArea1(vector<double> x, vector<double> y)
{
	double s = 0;
	int i;
	for (i = 0; i < x.size() - 1; i++)
		s += (y[i + 1] + y[i]) * (x[i + 1] - x[i]);
	return fabs(s / 2);
}

double findArea(vector<double>& x, vector<double>& y)
{
	double s = 0;
	for (int i = 0; i < x.size() - 1; i++)
		s += (x[i] * y[i + 1] - x[i + 1] * y[i]);
	return fabs(s / 2);
}

pair<double, double> findMass(vector<double>& x, vector<double>& y)
{
	double x_c = 0, y_c = 0;
	double S = findArea1(x, y);
	for (int i = 0; i < x.size() - 1; i++)
		x_c += (x[i] + x[i + 1]) * (x[i] * y[i + 1] - x[i + 1] * y[i]);
	x_c /= 6 * S;
	for(int i = 0; i < y.size() - 1; i++)
		y_c += (y[i] + y[i + 1]) * (x[i] * y[i + 1] - x[i + 1] * y[i]);
	y_c /= 6 * S;
	return make_pair(fabs(x_c), fabs(y_c));
}

int main()
{
	ifstream fin("input.txt");
	int n;
	cin >> n;
	vector<double> x(n + 1);
	vector<double> y(n + 1);
	for(int i = 0; i < n; i++)
		cin >> x[i] >> y[i];
	x.push_back(x[0]);
	y.push_back(y[0]);
	pair<double, double> p = findMass(x, y);
	cout.precision(8);
	cout << p.first << endl;
	cout << p.second << endl;
	return 0;
}

