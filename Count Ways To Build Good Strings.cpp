class Solution
{
    int low, high, zero, one;
    vector<int> dp;
    int solve(int len)
    {
        if(len > high) return 0;
        if(dp[len] != -1) return dp[len];
        int ans = ((len >= low && len <= high) ? 1:0) +
                 solve(len+zero) + 
                 solve(len+one);
        ans %= (int)1e9+7;
        return dp[len] = ans;
    }
public:
    int countGoodStrings(int low, int high, int zero, int one)
    {
        this->low = low;
        this->high = high;
        this->zero = zero;
        this->one = one;
        dp = vector<int>(high+1, -1);
        return solve(0);
    }
};
