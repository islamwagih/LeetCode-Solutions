class Solution
{
public:
    int maxSubarraySumCircular(vector<int>& nums)
    {
        int maxSubSum = nums[0], currMax = nums[0],
            currMin = nums[0], minSubSum = nums[0],
            sum = nums[0], n = nums.size();

            for(int i=1;i<n;i++)
            {
                currMax = max(currMax+nums[i], nums[i]);
                currMin = min(currMin+nums[i], nums[i]);
                maxSubSum = max(maxSubSum, currMax);
                minSubSum = min(minSubSum, currMin);
                sum += nums[i];
            }

            if(minSubSum == sum) return maxSubSum;
            return max(maxSubSum, sum-minSubSum);
    }
};
