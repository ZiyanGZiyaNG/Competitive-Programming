#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	map<char, int> num;
	int n; cin >> n;
	cin.ignore();
	for (int j = 0; j < n; j++)
	{
		string x;
		getline(cin, x);
		for (int i = 0; i < x.size(); i++)
		{
			if (x[i] == 'A' or x[i] == 'a') num['A']++;
			if (x[i] == 'B' or x[i] == 'b') num['B']++;
			if (x[i] == 'C' or x[i] == 'c') num['C']++;
			if (x[i] == 'D' or x[i] == 'd') num['D']++;
			if (x[i] == 'E' or x[i] == 'e') num['E']++;
			if (x[i] == 'F' or x[i] == 'f') num['F']++;
			if (x[i] == 'G' or x[i] == 'g') num['G']++;
			if (x[i] == 'H' or x[i] == 'h') num['H']++;
			if (x[i] == 'I' or x[i] == 'i') num['I']++;
			if (x[i] == 'J' or x[i] == 'j') num['J']++;
			if (x[i] == 'K' or x[i] == 'k') num['K']++;
			if (x[i] == 'L' or x[i] == 'l') num['L']++;
			if (x[i] == 'M' or x[i] == 'm') num['M']++;	
			if (x[i] == 'N' or x[i] == 'n') num['N']++;
			if (x[i] == 'O' or x[i] == 'o') num['O']++;
			if (x[i] == 'P' or x[i] == 'p') num['P']++;
			if (x[i] == 'Q' or x[i] == 'q') num['Q']++;
			if (x[i] == 'R' or x[i] == 'r') num['R']++;
			if (x[i] == 'S' or x[i] == 's') num['S']++;			
			if (x[i] == 'T' or x[i] == 't') num['T']++;
			if (x[i] == 'U' or x[i] == 'u') num['U']++;
			if (x[i] == 'V' or x[i] == 'v') num['V']++;
			if (x[i] == 'W' or x[i] == 'w') num['W']++;
			if (x[i] == 'X' or x[i] == 'x') num['X']++;
			if (x[i] == 'Y' or x[i] == 'y') num['Y']++;
			if (x[i] == 'Z' or x[i] == 'z') num['Z']++;
			
		}
	}
	vector<pair<char, int>> q;
	
	for (auto p: num)
	{
		q.emplace_back(p);
	}
	sort(q.begin(), q.end(), [](const pair<char,int>& a, const pair<char,int>& b)
	{
    	if (a.second != b.second) return a.second > b.second;
    	return a.first < b.first;
	});
	for (auto p: q)
	{
		cout << p.first << " " << p.second << "\n";
	}
}
