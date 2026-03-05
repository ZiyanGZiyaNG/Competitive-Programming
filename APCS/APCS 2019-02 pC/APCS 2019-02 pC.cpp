#include <bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	vector<string> v;
	while (cin >> s)
	{
		v.emplace_back(s);
	}
	reverse(v.begin(), v.end());
	stack<long long int> st;
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] == "f")
		{
			long long int x = st.top();
			st.pop();
			st.push(2 * x - 3);
		}
		else if (v[i] == "g")
		{
			long long int x = st.top();
			st.pop();
			long long int y = st.top();
			st.pop();
			st.push(2 * x + y - 7);
		}
		else if (v[i] == "h")
		{
			long long int x = st.top();
			st.pop();
			long long int y = st.top();
			st.pop();
			long long int z = st.top();
			st.pop();
			st.push(3 * x - 2 * y + z);
		}
		else
		{
            st.push(stoll(v[i]));
        }
	}
	auto ans = st.top();
	cout << ans;
}
