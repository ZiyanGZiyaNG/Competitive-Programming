class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size() + 1;

        vector<int> in(n + 1, 0);

        for (int i = 0; i < edges.size(); i++)
        {
            in[edges[i][0]]++;
            in[edges[i][1]]++;
        }
        int loc = -1;
        for (int i = 1; i <= n; i++)
        {
            if (in[i] == n - 1)
            {
               loc = i; 
            }
        }


        return loc;
    }
};
