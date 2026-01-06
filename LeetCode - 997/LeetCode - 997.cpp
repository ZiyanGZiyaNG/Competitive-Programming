class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) 
    {
        vector<int> in(n + 1, 0), out(n + 1, 0);

        for (int i = 0; i < trust.size(); i++) 
        {
            int a = trust[i][0];
            int b = trust[i][1];
            out[a]++;
            in[b]++;
        }
        int index = -1;
        for (int i = 1; i <= n; i++) 
        {
            if (out[i] == 0 && in[i] == n - 1)
            {
                index = i;
            }
        }
        return index;
    }
};
