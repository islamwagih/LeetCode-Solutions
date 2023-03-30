class Solution
{
    int n;
    vector<vector<int>> dp;
    int solve(int i, int factor, vector<int>& satisfaction)
    {
        if(i >= n) return 0;
        if(dp[i][factor] != -1) return dp[i][factor];
        int ans = factor*satisfaction[i] + solve(i+1, factor+1, satisfaction);
        ans = max(ans, solve(i+1, factor, satisfaction));
        return dp[i][factor] = ans;
    }
public:
    int maxSatisfaction(vector<int>& satisfaction)
    {
        sort(satisfaction.begin(), satisfaction.end());
        this->n = satisfaction.size();
        dp = vector<vector<int>>(n, vector<int>(n+1,-1));
        return solve(0, 1, satisfaction);
    }
};
