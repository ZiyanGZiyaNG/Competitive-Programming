#include <iostream>
using namespace std;
int main()
{
	int t; cin >> t;
	for (int i = 0; i < t; i++)
	{
		int n; cin >> n;
		int a[n];
		bool ss = false;
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < n; i++)
		{
			if (a[i] == 67)
			{
				ss = true;
				break;
			}	
		}
		if (ss) cout << "YES\n";
		else cout << "NO\n";
	}
}
