#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long int n; cin >> n;
	vector<long long int> a;
	vector<long long int> b;
	vector<long long int> c;
	a.resize(n);
	b.resize(n);
	c.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i] >> b[i] >> c[i];
	}
	
	
	
	
	vector<long long int> dpa;
	
	vector<long long int> dpb;
	vector<long long int> dpc;
	
	
	dpa.resize(n);
	dpb.resize(n);
	dpc.resize(n);
	dpa[0] = a[0];
	dpb[0] = 2e15;
	dpc[0] = 2e15;
	for (int i = 1; i < n; i++)
	{
		dpa[i] = dpa[i - 1] + a[i];
		dpb[i] = min(dpa[i - 1], dpb[i - 1]) + b[i];
		dpc[i] = min(dpb[i - 1], dpc[i - 1]) + c[i]; 
	}
	cout << dpc[n - 1];
	
}
