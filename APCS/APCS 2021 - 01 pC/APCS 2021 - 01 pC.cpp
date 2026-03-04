#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n, l; cin >> n >> l;
	vector<pair<int, int>> v;
	for (int i = 0; i < n; i++)
	{
		int x, time; cin >> x >> time;
		v.push_back({time, x});
	}
	long long ans = 0;
	sort(v.begin(), v.end());
	set<int> st;
	st.insert(0);
	st.insert(l);
	for (int i = 0; i < n; i++)
	{
		auto it = st.lower_bound(v[i].second);
		int left = *prev(it), right = *it;
		ans += right - left;
		st.insert(v[i].second);
	}
	cout << ans;
}
