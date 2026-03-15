#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n; cin >> n;
	while (n--)
	{
		string s; cin >> s;
		stack<char> st;
		int cnt = 0;
		bool ok = true;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == '(') st.push('(');
			else if (s[i] == ')')
			{
				if (st.empty()) 
				{
					ok = false;
					break;	
				}
				
				else if (!st.empty())
				{
					st.pop(); cnt++;
				}
			}
		}
		if (!ok or !st.empty()) cout << 0 << '\n';
		else cout <<  cnt << '\n';
	}
}
