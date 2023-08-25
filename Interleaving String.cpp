class Solution
{
    string s1, s2, s3;
    vector<vector<int>> dp;
    bool interleave(int i, int j)
    {
        if(i + j == s3.size()) return true;
        if(dp[i][j] != -1) return dp[i][j];
        bool ans = false;
        if(i < s1.size() && s1[i] == s3[i+j]) ans |= interleave(i+1, j);
        if(j < s2.size() && s2[j] == s3[i+j]) ans |= interleave(i, j+1);
        return dp[i][j] = ans;
    }
public:
    bool isInterleave(string s1, string s2, string s3)
    {
        if(s1.size() + s2.size() != s3.size()) return false;
        this->s1 = s1, this->s2 = s2, this->s3 = s3;
        this->dp = vector<vector<int>>
                   (s1.size()+5, vector<int>(s2.size()+5, -1));
        return interleave(0, 0);
    }
};
