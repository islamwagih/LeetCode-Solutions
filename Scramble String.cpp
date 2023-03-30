class Solution
{
    unordered_map<string, bool> dp;
    bool solve(string s1, string s2)
    {
        int i, len = s1.size();
        if (len == 0) {
            return true;
        } 
        if (len == 1) {
            return s1 == s2;
        } 
        if (dp.find(s1 + s2) != dp.end()) {
            return dp[s1 + s2];
        }
        if (s1 == s2) {
           return dp[s1+s2] = true;
        } 
        bool ans = false;
        for (i = 1; i < len && !ans; i++)
        {
            ans |= (
                        solve(s1.substr(0, i), s2.substr(0, i)) && 
                        solve(s1.substr(i), s2.substr(i))
                   );
            if(ans) break;
            ans |= (
                        solve(s1.substr(0, i), s2.substr(len - i, i)) && 
                        solve(s1.substr(i), s2.substr(0, len - i))
                   );
        }
        return dp[s1 + s2] = ans;
    }
public:
    bool isScramble(string s1, string s2) {
        return solve(s1, s2);
    }
};
