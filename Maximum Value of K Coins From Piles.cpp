class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k)
    {
        int n = piles.size();
        vector<vector<int>> dp(n+1, vector<int>(k+1, 0));
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=k;j++)
            {
                int currSum = 0;
                for(int z=0;z<=min((int)piles[i-1].size(), j);z++)
                {
                    if(z > 0) currSum += piles[i-1][z-1];
                    dp[i][j] = max(dp[i][j], dp[i-1][j-z]+currSum);
                }
            }
        }
        return dp[n][k];
    }
};
