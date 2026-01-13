#include <iostream>
#include <string>
#include <map>
using namespace std;
int main()
{
	int n; cin >> n;
	map<string, int> s;
	
	for (int i = 0; i < n; i++)
	{
		string x; cin >> x;
		int odd = 0;
		int even = 0;
		for (int j = 0; j <= 11; j++)
		{
			if (j % 2 == 0) 
			{
				odd += x[j] - '0';
			}
			else even += x[j] - '0';
		}
		
		int c = x[12] - '0';
		int t = (odd + (3 * even)) % 10 + c;
		if (t == 10 or t == 0)
		{
			
			string w;
			w = x.substr(0, 3);
			s[w]++;
		}
		
	}
	string loc;
	int best = 0;
	for (auto p: s)
	{
		if (p.second > best)
		{
			loc = p.first;
			best = p.second;
		}
	}
	cout << loc << " " << best;
}
