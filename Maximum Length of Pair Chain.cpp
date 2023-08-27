class Solution
{
    vector<vector<int>> pairs; int n;
    vector<int> dp;
    int lis(int i)
    {
        if(i >= n) return 0;
        if(dp[i] != -1) return dp[i];
        int ans = 1;
        for(int j=i+1;j<n;j++)
        {
            if(pairs[j][0] > pairs[i][1])
            {
                ans = max(ans, 1+lis(j));
            }
        }
        return dp[i] = ans;
    }
public:
    int findLongestChain(vector<vector<int>>& pairs)
    {
        this->n = pairs.size();
        if(n <= 1) return n;
        dp = vector<int>(n+1, -1);
        sort(pairs.begin(), pairs.end());
        this->pairs = pairs;
        int maxLen = 0;
        for(int i=0;i<n;i++)
        {
            maxLen = max(maxLen, lis(i));
        }
        return maxLen;
    }
};
