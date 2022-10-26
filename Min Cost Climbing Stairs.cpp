class Solution {
    vector<int> costs;
    vector<int> dp;
    int n;
    int solve(int i)
    {
        if(i >= n) return 0;
        if(dp[i] != -1) return dp[i];
        return dp[i] = min(costs[i]+solve(i+1), costs[i]+solve(i+2));
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        n = cost.size();
        costs = vector<int>(cost);
        dp = vector<int>(n, -1);
        return min(solve(0), solve(1));
    }
};
