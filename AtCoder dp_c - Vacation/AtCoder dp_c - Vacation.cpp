#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n; cin >> n;
	int a[n], b[n], c[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i] >> b[i] >> c[i];
	}
	
	int dpa[n], dpb[n], dpc[n];
	
	dpa[0] = a[0];
	dpb[0] = b[0];
	dpc[0] = c[0];
	
	
	for (int i = 1; i < n; i++)
	{
		dpa[i] = max(dpb[i - 1], dpc[i - 1]) + a[i];
		dpb[i] = max(dpa[i - 1], dpc[i - 1]) + b[i];
		dpc[i] = max(dpa[i - 1], dpb[i - 1]) + c[i];
	}
	cout << max(dpa[n - 1], max(dpb[n - 1], dpc[n - 1]));
}
