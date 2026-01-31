#include <iostream>
#include <algorithm>
using namespace std;
int n, k; 
int p[50000];
bool check(int r)
{
	int c = 0;
	int i = 0;
	while (i < n)
	{
		if (c == k) return false;
		
		int lim = p[i] + r;
		while (i < n and p[i] <= lim) i++;
		c++;
		
	}
	return true;
}

int main()
{
	int mx = 0;
	cin >> n >> k;
	for (int i = 0; i < n; i++) 
	{
		cin >> p[i];
		mx = max(mx, p[i]);
	}
	sort(p, p + n);
	
	int l = 1, r = mx;
	int ra;
	while (l <= r)
	{
		int now = (r - l) / 2 + l;
		
		if (check(now)) 
		{
			ra = now;
			r = now - 1;
		}
		else l = now + 1;
		
	}
	cout << ra;
}
