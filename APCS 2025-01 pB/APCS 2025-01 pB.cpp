#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s;
	cin >> s;
	int k, len;
	cin >> k;
	len = s.length();
	for (int i = 0; i < k; i++)
	{
		int x;
		cin >> x;
		string ans = "";
		if (x == 0)
		{
			for (int j = 0; j < len; j+=2)
			{
				ans += s[j + 1];
				ans += s[j];
			}
		}
		else if (x == 1)
		{
			for (int j = 0; j < len; j+=2)
			{
				if (s[j + 1] < s[j])
				{
					ans += s[j + 1];
					ans += s[j];
				}
				else
				{
					ans += s[j];
					ans += s[j + 1];
				}
			}
		}
		else if (x == 2)
		{
			int half = len / 2;
			for (int j = 0; j < half; j++)
			{
				ans += s[j];
				ans += s[j + half];
			}
		}
		s = ans.substr(0, len);
	}
	cout << s;
}
