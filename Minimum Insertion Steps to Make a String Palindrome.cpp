class Solution
{
    string s;
    vector<vector<int>> dp;
    int solve(int l, int r)
    {
        if(l >= r) return 0;
        int& ret = dp[l][r];
        if(ret != -1) return ret;
        if(s[l] == s[r]) return ret = solve(l+1, r-1);
        return ret = 1+min(solve(l+1, r), solve(l, r-1));
    }
public:
    int minInsertions(string s)
    {
        this->s = s;
        int n = s.size();
        dp = vector<vector<int>>(n, vector<int>(n, -1));
        return solve(0, s.size()-1);
        
    }
};
