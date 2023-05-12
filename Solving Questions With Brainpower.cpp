class Solution
{
    vector<long long> dp;
public:
    long long solve(int i, vector<vector<int>>& questions)
    {
        if(i >= questions.size()) return 0;
        long long &ans = dp[i];
        if(ans != -1) return ans;
        return ans = max(
                        questions[i][0]+solve(i+questions[i][1]+1, 
                        questions), solve(i+1, questions)
                        );
    }
    long long mostPoints(vector<vector<int>>& questions)
    {
        dp = vector<long long>(questions.size()+5, -1);
        return solve(0, questions);
    }
};
