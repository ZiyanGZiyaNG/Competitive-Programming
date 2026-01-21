class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        int cc = 0;   
        int c  = 0;   

        for (int i = 0; i < (int)nums.size(); i++)
        {
            int x = nums[i];

            if (c == 0)
            {
                cc = x;
                c = 1;
            }
            else if (x == cc)
            {
                c++;
            }
            else
            {
                c--;
            }
        }

        return cc;
    }
};
