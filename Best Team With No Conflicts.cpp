class Solution
{
    vector<vector<int>> dp;
    int n;
    vector<pair<int, int>> comb;
    int solve(int i, int maxSoFar)
    {
        if(i == n) return 0;
        if(dp[i][maxSoFar] != -1) return dp[i][maxSoFar];
        //take it if value of i <= minSoFar
        int op = 0;
        if(comb[i].second >= maxSoFar)
        {
            op = comb[i].first + solve(i+1, comb[i].second);
        }
        //leave it
        op = max(op, solve(i+1, maxSoFar));
        return dp[i][maxSoFar] = op;
    }
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages)
    {
        n = scores.size();
        comb = vector<pair<int, int>>(n);
        int mx = 0;
        for(int i=0;i<n;i++)
        {
            comb[i] = make_pair(scores[i], ages[i]);
            mx = max(mx, ages[i]);
        }
        dp = vector<vector<int>>(n+2, vector<int>(mx+2, -1));
        sort(comb.begin(), comb.end());
        return solve(0, 0);   
    }
};
