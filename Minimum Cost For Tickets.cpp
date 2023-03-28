class Solution
{
    int n;
    vector<int> days, costs, dp;

    int solve(int i)
    {
        if(i >= n) return 0; //base case
        if(dp[i] != -1) return dp[i];
        //try first second and third ticket to see how much it will cost
        int minCost = 1e9;
        int oneDay = days[i] + 1; // one day pass
        int j = lower_bound(days.begin()+i, days.end(), oneDay) - days.begin();
        minCost = min(minCost, costs[0]+solve(j));
        int sevenDay = days[i] + 7; // seven day pass
        j = lower_bound(days.begin()+i, days.end(), sevenDay) - days.begin();
        minCost = min(minCost, costs[1]+solve(j));
        int thirtyDay = days[i] + 30; // thirty day pass
        j = lower_bound(days.begin()+i, days.end(), thirtyDay) - days.begin();
        minCost = min(minCost, costs[2]+solve(j));
        return dp[i] = minCost;
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs)
    {
        this->days = days;
        this->costs = costs;
        this->n = days.size();
        this->dp = vector<int>(n, -1);
        return solve(0);
    }
};
