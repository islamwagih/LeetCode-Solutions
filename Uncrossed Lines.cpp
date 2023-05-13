class Solution
{
    vector<int> nums1, nums2;
    int n, m;
    vector<vector<int>> dp;
    int solve(int i, int j)
    {
        if(i == n || j == m) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(nums1[i] == nums2[j]) return dp[i][j] = 1+solve(i+1, j+1);
        return dp[i][j] = max(solve(i+1,j), solve(i, j+1));
    }
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2)
    {
        this->nums1 = nums1;
        this->nums2 = nums2;
        n = nums1.size(), m = nums2.size();
        dp = vector<vector<int>>(n, vector<int>(m, -1));
        return solve(0, 0);
    }
};
