#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

string canReach(int x1, int y1, int x2, int y2)
{
	if (x1 > x2 || y1 > y2)
		return "No";
	if (x1 == x2 && y1 == y2)
		return "Yes";
	string s1 = canReach(x1 + y1, y1, x2, y2);
	string s2 = canReach(x1, y1 + x1, x2, y2);
	if (s1 == "Yes" || s2 == "Yes")
		return "Yes";
	else return "No";
}

int main()
{
	int x1, x2, y1, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	cout << canReach(x1, y1, x2, y1);
	return 0;
}
