#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <fstream>

using namespace std;

int main()
{
	int N, M;
	char trump;
	ifstream fin;
	fin.open("INPUT.txt");
	ofstream fout("OUTPUT.txt");
	fin >> N >> M >> trump;
	map<char, int> dic = { {'S', 0}, {'C', 1}, {'D', 2}, {'H', 3} };
	map<char, int> power = { {'6', 6}, {'7', 7}, {'8', 8}, {'9', 9}, {'T', 10}, {'J', 11}, {'Q', 12}, {'K', 13}, {'A', 14} };
	vector<vector<int>> suits(4);
	vector<pair<int, char>> enemy;
	string s;
	for (int i = 0; i < N; i++)
	{
		fin >> s;
		suits[dic[s[1]]].push_back(power[s[0]]);
	}
	for (int i = 0; i < M; i++)
	{
		fin >> s;
		enemy.push_back(make_pair(power[s[0]], s[1]));
	}
	for (int i = 0; i < 4; i++)
		sort(suits[i].begin(), suits[i].end());
	bool beaten;
	int enemySuit;
	for (int i = 0; i < M; i++)
	{
		beaten = false;
		enemySuit = dic[enemy[i].second];
		for (int j = 0; j < suits[enemySuit].size(); j++)
		{
			if (suits[enemySuit][j] > enemy[i].first)
			{
				suits[enemySuit].erase(suits[enemySuit].begin() + j);
				beaten = true;
				break;
			}
		}
		if (!beaten)
		{
			if (suits[dic[trump]].size() == 0 || enemySuit == dic[trump])
			{
				fout << "NO";
				return 0;
			}
			suits[dic[trump]].erase(suits[dic[trump]].begin());
		}
	}
	fout << "YES";
	fin.close();
	fout.close();
	return 0;
}