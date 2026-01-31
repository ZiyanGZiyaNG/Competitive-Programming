#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int n; cin >> n;
	vector<string> v;
	vector<int> mn;
	int mnn = 1000000000;
	for (int i = 0; i < n; i++)
	{
		string s; cin >> s;
		v.push_back(s);
		bool y[26] = {false};
		for (int j = 0; j < s.size(); j++)
		{
			if (s[j] == 'A') y[0] = true;
			if (s[j] == 'B') y[1] = true;
			if (s[j] == 'C') y[2] = true;
			if (s[j] == 'D') y[3] = true;
			if (s[j] == 'E') y[4] = true;
			if (s[j] == 'F') y[5] = true;
			if (s[j] == 'G') y[6] = true;
			if (s[j] == 'H') y[7] = true;
			if (s[j] == 'I') y[8] = true;
			if (s[j] == 'J') y[9] = true;
			if (s[j] == 'K') y[10] = true;
			if (s[j] == 'L') y[11] = true;
			if (s[j] == 'M') y[12] = true;
			if (s[j] == 'N') y[13] = true;
			if (s[j] == 'O') y[14] = true;
			if (s[j] == 'P') y[15] = true;
			if (s[j] == 'Q') y[16] = true;
			if (s[j] == 'R') y[17] = true;
			if (s[j] == 'S') y[18] = true;
			if (s[j] == 'T') y[19] = true;
			if (s[j] == 'U') y[20] = true;
			if (s[j] == 'V') y[21] = true;
			if (s[j] == 'W') y[22] = true;
			if (s[j] == 'X') y[23] = true;
			if (s[j] == 'Y') y[24] = true;
			if (s[j] == 'Z') y[25] = true;
		}
		int c = 0;
		for (int j = 0; j < 26; j++)
		{
			if (y[j]) c++;
		}
		mnn = min(mnn, c);
		mn.push_back(c);
	}
	
	vector<string> w;
	
	for (int i = 0; i < n; i++)
	{
		if (mn[i] == mnn)
		{
			w.push_back(v[i]);
		}
	}
	sort(w.begin(), w.end());
	cout << w[0];
}
