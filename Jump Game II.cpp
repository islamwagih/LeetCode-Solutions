class Solution
{
    vector<int> arr, dp;
    int n;
    int solve(int i)
    {
        if(i >= n-1) return 0;
        if(dp[i] != -1) return dp[i];
        int minJumps = 1e9;
        for(int j=1;j<=arr[i];j++)
        {
            minJumps = min(1+solve(i+j), minJumps);
        }
        return dp[i] = minJumps;
    }
public:
    int jump(vector<int>& nums)
    {
        n = nums.size();
        arr = nums;
        dp = vector<int>(n, -1);
        return solve(0);
    }
};
