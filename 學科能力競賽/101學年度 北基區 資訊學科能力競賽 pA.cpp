#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;
int main()
{
	int n, m; cin >> n >> m;
	vector<pair<int, int>> v;
	vector<double> d;
	
	for (int i = 0; i < m; i++)
	{
		int x, y; cin >> x >> y;
		v.push_back({x, y});
	}
	
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v.size(); j++)
		{
			if (i != j)
			{
				int x1 = v[i].first;
				int y1 = v[i].second;
				int x2 = v[j].first;
				int y2 = v[j].second;
				
				int x = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
				d.push_back(x);
			}
		}
	}
	sort(d.begin(), d.end());
	cout << fixed << setprecision(4);
	cout << sqrt(d[0]);
}
