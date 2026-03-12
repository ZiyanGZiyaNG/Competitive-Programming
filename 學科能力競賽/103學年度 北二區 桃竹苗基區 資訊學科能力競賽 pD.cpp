#include <bits/stdc++.h>
using namespace std;
int sum = 0;
void c(int n)
{
	if (n == 1) return;
	if (n % 2 == 0)
	{
		n = n / 2;
		c(n);
		sum++;
	}
	else if (n % 2 != 0)
	{
		n = 3 * n + 1;
		c(n);
		sum++;
	}
}
int main()
{
	int n; 
	while (cin >> n)
	{
		sum = 0;
		c(n);
		cout << sum << '\n';	
	}
}
