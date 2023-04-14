class Solution
{
    string s;
    vector<vector<int>> dp;
    int longest(int l, int h)
    {
        if(l == h) return 1;
        if(l > h) return 0;
        if(dp[l][h] != -1) return dp[l][h];
        if(s[l] == s[h])
        {
            return dp[l][h] = 2+longest(l+1, h-1);
        }
        return dp[l][h] = max(longest(l+1, h), longest(l, h-1));
    }
public:
    int longestPalindromeSubseq(string s)
    {
        this->s = s;
        dp = vector<vector<int>>(s.size(), vector<int>(s.size(), -1));
        return longest(0, s.size()-1);
    }
};
