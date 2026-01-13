#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> mx(30, 0), mn(30, 1000);
int last;

void dfs(vector<int> p, vector<int> d, int q)
{
	for (int x: p)
	{
		auto it = find(d.begin(), d.end(), abs(q - x));
		if (it == d.end())
		{
			return;
		}
		d.erase(it);
	}
	p.emplace_back(q);
	
	if (d.empty())
	{
		sort(p.begin(), p.end());
		if (p > mx) mx = p;
		if (p < mn) mn = p;
		return;
	}
	q = d.back();
	dfs(p, d, q);
	dfs(p,d,last-q);
}

int main()
{
	int n; cin >> n;
	if (n == 1)
	{
		cout << 0 << "\n" << 0; return 0;
	}
	int m = (n * (n - 1)) / 2;
	vector<int> d(m);
	for (int i = 0; i < m; i++) cin >> d[i];
	sort(d.begin(), d.end());
	
	vector<int> point({0});
	last = d.back();
	dfs(point, d, last);
	
	for (int i = 0; i < n; i++)
	{
		cout << mn[i] << " ";
	}	
	cout << "\n";
	
	for (int i = 0; i < n; i++)
	{
		cout << mx[i] << " ";
	}
}
