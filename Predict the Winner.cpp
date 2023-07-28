class Solution
{
    vector<int> nums;
    vector<vector<int>> dp;
    int maxDiff(int left, int right)
    {
        if(left == right) return nums[left];
        if(dp[left][right] != -1) return dp[left][right];
        return dp[left][right] = max(
                nums[left] - maxDiff(left+1, right), 
                nums[right] - maxDiff(left, right-1));
    }
public:
    bool PredictTheWinner(vector<int>& nums)
    {
        int n = nums.size();
        dp = vector<vector<int>>(n, vector<int>(n, -1));
        this->nums = nums;
        return maxDiff(0, n-1) >= 0;
    }
};
