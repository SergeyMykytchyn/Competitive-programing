// 2170 - Ремонт в Ханої.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

using namespace std;

void MoveDisks(int Ndisks, int fromTower, int toTower, int name)
{
	if (Ndisks == 1)
	{
		cout << name << " " << fromTower << " " << toTower << endl;
		return;
	}
	if (fromTower == 1 && toTower == 2)
	{
		MoveDisks(Ndisks - 1, 1, 2, Ndisks - 1);
		MoveDisks(Ndisks - 1, 2, 3, Ndisks - 1);
		MoveDisks(1, 1, 2, Ndisks);
		MoveDisks(Ndisks - 1, 3, 2, Ndisks - 1);
	}
	if (fromTower == 2 && toTower == 3)
	{
		MoveDisks(Ndisks - 1, 2, 1, Ndisks - 1);
		MoveDisks(1, 2, 3, Ndisks); 
		MoveDisks(Ndisks - 1, 1, 2, Ndisks - 1);
		MoveDisks(Ndisks - 1, 2, 3, Ndisks - 1);
	}
	if (fromTower == 3 && toTower == 2)
	{
		MoveDisks(Ndisks - 1, 3, 2, Ndisks - 1);
		MoveDisks(Ndisks - 1, 2, 1, Ndisks - 1);
		MoveDisks(1, 3, 2, Ndisks);
		MoveDisks(Ndisks - 1, 1, 2, Ndisks - 1);
	}
	if (fromTower == 2 && toTower == 1)
	{
		MoveDisks(Ndisks - 1, 2, 3, Ndisks - 1);
		MoveDisks(1, 2, 1, Ndisks);
		MoveDisks(Ndisks - 1, 3, 2, Ndisks - 1);
		MoveDisks(Ndisks - 1, 2, 1, Ndisks - 1);
	}
}

int main()
{
	int n;
	cin >> n;
	MoveDisks(n, 1, 2, n);
	MoveDisks(n, 2, 3, n);
	return 0;
}

