#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n; cin >> n;
	int x = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < n - i; j++) cout << " ";
		for (int j = 0; j < x; j++) 
		{
			cout << "*";
		}	
		x += 2;
		cout << "\n";
	}
}
