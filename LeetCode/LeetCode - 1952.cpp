class Solution {
public:
    int c (int n)
    {
        int sum = 0;
        for (int i = 1; i < n + 1; i++)
        {
            if (n % i == 0) sum++;
        }
        return sum;
    }
    bool isThree(int n) 
    {
        int y = c(n);
        if (y == 3) return true;
        else return false;        
    }
};
