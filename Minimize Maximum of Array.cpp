class Solution
{
public:
    int minimizeArrayValue(vector<int>& nums)
    {
        int n = nums.size();
        long long ans = 0, prefixSum = 0;
        for(int i=0;i<n;i++)
        {
            prefixSum += nums[i];
            ans = max(ans, (long long)ceil((double)prefixSum/(i+1)));
        }
        return ans;
    }
};
