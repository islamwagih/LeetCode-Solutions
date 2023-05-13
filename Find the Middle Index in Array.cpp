class Solution {
public:
    int findMiddleIndex(vector<int>& nums)
    {
        if(nums.size() == 1) return 0;
        vector<int> prefix(nums.size());
        prefix[0] = nums[0];
        int sum = nums[0];
        for(int i=1;i<nums.size();i++)
        {
            prefix[i] = nums[i] + prefix[i-1];
            sum += nums[i];
        }
        if(sum - prefix[0] == 0) return 0;
        for(int i=1;i<nums.size();i++)
        {
            int leftSum = prefix[i-1];
            int rightSum = sum - prefix[i];
            if(leftSum == rightSum) return i;
        }
        if(prefix[nums.size()-2] == 0) return nums.size() - 1;
        return -1;
        
    }
};
