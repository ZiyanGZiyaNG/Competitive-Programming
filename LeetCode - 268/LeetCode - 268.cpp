class Solution {
public:
    int missingNumber(vector<int>& nums) 
    {
        int n = nums.size();
        vector<bool> c(n + 1, false);

        for (int i = 0; i < n; i++)
        {
            c[nums[i]] = true;
        }

        for (int i = 0; i <= n; i++)
        {
            if (!c[i]) return i;
        }

        return -1; 
    }
};
