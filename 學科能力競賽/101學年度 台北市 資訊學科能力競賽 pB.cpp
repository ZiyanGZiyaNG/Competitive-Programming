#include <iostream>
#include <string>
using namespace std;
int main()
{
	int n; cin >> n;
	for (int i = 0; i < n; i++)
	{
		int ans = 0;
		int p = 0;
		string s; cin >> s;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == 'p') p++;
			if (s[i] == 'q') 
			{
				if (p > 0) 
				{
					p--;
					ans++;
				}
			}
		}
		cout << ans << "\n";
	}
}
