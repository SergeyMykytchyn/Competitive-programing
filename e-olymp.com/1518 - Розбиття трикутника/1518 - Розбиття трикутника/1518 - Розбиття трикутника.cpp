// 1518 - Розбиття трикутника.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <cmath>
#include <set>
#include <vector>
#include <fstream>

using namespace std;

struct classcomp 
{
	bool operator() (const double& lhs, const double& rhs) const
	{
		return lhs > rhs;
	}
};

vector<multiset<double, classcomp>> cl;

double median(double a, double b, double c)
{
	return sqrt(2 * b * b + 2 * c * c - a * a) / 2;
}

bool Similar(multiset<double, classcomp>& tr1, multiset<double, classcomp>& tr2)
{
	double ratio1 = *tr1.begin() / *tr2.begin();
	double ratio2 = *next(tr1.begin(), 1) / *next(tr2.begin(), 1);
	double ratio3 = *next(tr1.begin(), 2) / *next(tr2.begin(), 2);
	if (fabs(ratio1 - ratio2) < 0.000001 && fabs(ratio2 - ratio3) < 0.000001)
		return true;
	return false;
}

void count_class(multiset<double, classcomp> tr)
{
	for (int i = 0; i < cl.size(); i++)
		if (Similar(cl[i], tr))
			return;
	cl.push_back(tr);

	double m_a = median(*tr.begin(), *next(tr.begin(), 1), *next(tr.begin(), 2));

	multiset<double, classcomp> tr1;
	tr1.insert(*tr.begin() / 2);
	tr1.insert(m_a);
	tr1.insert(*next(tr.begin(), 1));

	multiset<double, classcomp> tr2;
	tr2.insert(*tr.begin() / 2);
	tr2.insert(m_a);
	tr2.insert(*next(tr.begin(), 2));

	count_class(tr1);
	count_class(tr2);
}

int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	int tests;
	double a, b, c;
	multiset<double, classcomp> tr;
	fin >> tests;
	for (int i = 1; i <= tests; i++)
	{
		cl.clear();
		tr.clear();
		fin >> a >> b >> c;

		tr.insert(a);
		tr.insert(b);
		tr.insert(c);

		count_class(tr);
		fout << "Triangle " << i << ": " << cl.size() << "\n";
	}

	//for (int i = 0; i < cl.size(); i++)
		//cout << *next(cl[i].begin(), 1) / *cl[i].begin() << " " << *next(cl[i].begin(), 2) / *cl[i].begin() << endl;

	/*set<int>::iterator it;
	for (it = tr.begin(); it != tr.end(); it++)
		cout << *it << endl;*/

	return 0;
}


