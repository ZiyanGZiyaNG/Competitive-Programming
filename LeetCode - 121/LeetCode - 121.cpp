class Solution {
public:
    int maxProfit(vector<int>& p) 
    {
        int mn = 1e9;
        int ans = 0;

        for (int i = 0; i < (int)p.size(); i++)
        {
            mn = min(mn, p[i]);        
            ans = max(ans, p[i] - mn); 
        }
        return ans;
    }
};
