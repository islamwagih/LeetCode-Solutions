class Solution
{
    vector<int> dp;
    string s;
    int k, mod = 1e9 + 7;
    int dfs(int i)
    {
        if(i == s.size()) return 1;
        if(s[i] == '0') return 0;
        if(dp[i] != -1) return dp[i];
        int ans = 0;
        long long num = 0;
        for(int j=i;j<s.size();j++)
        {
            num *= 10;
            num += s[j] - '0';
            if(num > k) break;
            ans += dfs(j+1);
            ans %= mod;
        }
        return dp[i] = ans;
    }
public:
    int numberOfArrays(string s, int k)
    {
        this->s = s;
        this->k = k;
        dp = vector<int>(s.size(), -1);
        return dfs(0);
    }
};
