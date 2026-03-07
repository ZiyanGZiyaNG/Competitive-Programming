#include <bits/stdc++.h>
using namespace std;

struct Node
{
    vector<int> from;
    vector<int> to;
    int gate = -1;   
    int out = -1;    
};

vector<Node> v;
vector<int> dp;      
int p, q, r, m;

int dfs(int u)
{
    if (dp[u] != -1) return dp[u];


    if (u >= 1 && u <= p)
    {
        dp[u] = 0;
        return 0;
    }

    int mx = 0;
    for (int pre : v[u].from)
    {
        mx = max(mx, dfs(pre));
    }


    if (u >= p + 1 && u <= p + q)
    {
        if (v[u].gate == 1) 
        {
            v[u].out = 1;
            for (int pre : v[u].from)
            {
                if (v[pre].out == 0)
                {
                    v[u].out = 0;
                    break;
                }
            }
        }
        else if (v[u].gate == 2)
        {
            v[u].out = 0;
            for (int pre : v[u].from)
            {
                if (v[pre].out == 1)
                {
                    v[u].out = 1;
                    break;
                }
            }
        }
        else if (v[u].gate == 3) 
        {
            v[u].out = 0;
            for (int pre : v[u].from)
            {
                v[u].out ^= v[pre].out;
            }
        }
        else if (v[u].gate == 4) 
        {
			if (v[v[u].from[0]].out == 0) v[u].out = 1;
			else v[u].out = 0;
        }

        dp[u] = mx + 1; 
        return dp[u];
    }

   
    v[u].out = v[v[u].from[0]].out;
    dp[u] = mx;
    return dp[u];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> p >> q >> r >> m;

    int n = p + q + r;
    v.resize(n + 1);
    dp.assign(n + 1, -1);

   
    for (int i = 1; i <= p; i++) cin >> v[i].out;

   
    for (int i = p + 1; i <= p + q; i++) cin >> v[i].gate;

   
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        v[b].from.push_back(a);
        v[a].to.push_back(b);
    }

    int mx = 0;

   
    for (int i = p + q + 1; i <= p + q + r; i++)
    {
        mx = max(mx, dfs(i));
    }

    cout << mx << '\n';
    for (int i = p + q + 1; i <= p + q + r; i++)
    {
        cout << v[i].out;
        if (i != p + q + r) cout << ' ';
    }
    cout << '\n';

}
