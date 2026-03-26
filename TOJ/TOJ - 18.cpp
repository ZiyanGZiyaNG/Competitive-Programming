#include <bits/stdc++.h>
using namespace std;
bool check(string s)
{
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] != s[s.size() - i - 1]) return false;
	}
	return true;
}
int main()
{
	string s; 
	while (getline(cin, s))
	{
		string a;
		for (int i = 0; i < s.size(); i++)
		{
			if (65 <= int(s[i]) and int(s[i]) <= 90 or 97 <= int(s[i]) and int(s[i]) <= 122) a += s[i];
		}
		for (int i = 0; i < a.size(); i++) a[i] = tolower(a[i]);
		if (check(a)) cout << "SETUP! " << s << '\n';
		else cout << s << '\n';
	}
}
