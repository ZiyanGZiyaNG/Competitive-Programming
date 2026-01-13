#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


vector<vector<long long int>> child;
vector<long long int> parent;
long long int root;
long long int level = 0;
vector<long long> height;
long long int ht = 0;

long long int dfs(long long int u)
{
	if (height[u] != -1) return height[u];
	long long mx = -1;
	for (long long v :child[u])
	{
		mx = max(mx, dfs(v));
	}
	height[u] = mx + 1;
	ht += height[u];
	return height[u];
}

int main()
{
	long long int n; cin >> n;
	
	child.resize(n + 1);
	parent.resize(n + 1);
	for (int i = 0; i <= n; i++) parent[i] = 0;
	
	for (long long int i = 1; i <= n; i++)
	{
		long long int k; cin >> k;
		for (long long int j = 0; j < k; j++)
		{
			long long int a; cin >> a;
			child[i].push_back(a); 
        	parent[a] = i;    

		}
	}
	
	
	for (int i = 1; i <= n; i++)
	{
		if (parent[i] == 0)
		{
			root = i;
			break;
		}
	}
	
	cout << root << "\n";
	height.assign(n + 1, -1);
	dfs(root);
	
	cout << ht;
	
	
}
