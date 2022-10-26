class Solution {
    int dp[103][103];
    int solve(int i, int j, int m, int n)
    {
        if(i >= m || j >= n) return 0;
        if(i == m-1 && j == n-1) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = solve(i, j+1, m, n)+solve(i+1, j, m, n);
    }
public:
    int uniquePaths(int m, int n) 
    {
        memset(dp, -1, sizeof dp);
        return solve(0, 0, m, n);
    }
};
