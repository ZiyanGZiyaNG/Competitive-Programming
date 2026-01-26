#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	long long int n, m; cin >> n >> m;
	long long int a[m], b[m];
	long long int in[n + 1];
	memset(in, 0, sizeof(in));
	for (long long int i = 0; i < m; i++)
	{
		cin >> a[i] >> b[i];
		in[a[i]]++;
		in[b[i]]++;
	}
	for (long long int i = 1; i <= n; i++)
	{
		long long int sum = n - in[i] - 1;
		if (sum < 3) cout << 0 << " ";
		else
		{
			cout << (sum * (sum - 1) * (sum - 2)) / 6 << " ";
		}
	}	
	
	
}
