class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums)
    {
        int left = 0, right = 0, sz = nums.size();
        int minLength = 1e9, sum = 0;
        while(left < sz)
        {
            while(sum < target && right < sz)
            {
                sum += nums[right++];
            }
            if(sum >= target) minLength = min(minLength, right - left);
            sum -= nums[left++];
        }

        return minLength == 1e9 ? 0 : minLength;
        
    }
};
