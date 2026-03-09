#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long int n, m; cin >> n >> m;
	vector<long long int> w(n + 1);
	for (long long  i = 1; i <= n; i++) cin >> w[i];
	vector<long long> pre(n + 1); pre[0] = 0;
	for (long long i = 1; i <= n; i++) pre[i] = pre[i - 1] + w[i];
	
	for (long long i = 0; i < m; i++) 
	{
		long long L, R, a, b; cin >> L >> R >> a >> b;
		long long l = L, r = R;
		long long ans = 0;
		while (l <= r) 
		{
			long long mid = (l + r) / 2;
			if (((pre[mid] - pre[L - 1]) * (a + b)) >= (a * (pre[R] - pre[L - 1]))) 
			{
				r = mid - 1; ans = mid;
			}
				
			else l = mid + 1;
		}
		cout << ans << "\n";
		
	} 
	
}
