class Solution {
public:
    vector<vector<int>> graph;
    vector<bool> vis;

    bool dfs(int s, int t)
    {
        if (s == t) return true;
        vis[s] = true;
        for (int i = 0; i < int(graph[s].size()); i++)
        {
            int v = graph[s][i];
            if (!vis[v])
            {
                if (dfs(v, t)) return true;
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) 
    {
        graph.resize(n);
        vis.resize(n, false);
        for (int i = 0; i < edges.size(); i++)
        {
            graph[edges[i][0]].emplace_back(edges[i][1]);
            graph[edges[i][1]].emplace_back(edges[i][0]);
        }
        return dfs(source, destination);
        
    }
};
