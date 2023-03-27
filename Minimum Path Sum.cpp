class Solution
{
    int n, m;
    vector<vector<int>> dp;
    int solve(int i, int j, vector<vector<int>>& grid)
    {
        if(i >= n || j >= m) return 1e9;
        if(i == n-1 && j == m-1) return grid[i][j];
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = grid[i][j]+min(solve(i+1, j, grid), solve(i, j+1, grid));
    }

    void buildTable(vector<vector<int>>& grid, vector<vector<int>>& dp)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                dp[i][j] = grid[i][j];
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i-1 >= 0 && j-1 >= 0) dp[i][j] += min(dp[i-1][j], dp[i][j-1]);
                else if (i-1 >= 0) dp[i][j] += dp[i-1][j];
                else if(j-1 >= 0) dp[i][j] += dp[i][j-1];
            }
        }
    }
public:
    int minPathSum(vector<vector<int>>& grid) 
    {
        n = grid.size(), m = grid[0].size();
        dp = vector<vector<int>>(n, vector<int>(m, -1));
        buildTable(grid, dp);
        return dp[n-1][m-1];
    }
};
