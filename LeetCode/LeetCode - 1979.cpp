class Solution {
public:
    int findGCD(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        int x = nums[0];;
        int y = nums[nums.size() - 1];
        int gcd = 1;
        if (x == y) return x;
        for (int i = 2; i < y; i++)
        {
            
            if (x % i == 0 and y % i == 0)
            {
                gcd = i;
            }
        }
        return gcd;

    }
};
