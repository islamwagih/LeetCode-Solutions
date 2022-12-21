class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k)
    {
        if(k <= 1) return 0;
        int left = 0, ans = 0, prod = 1;
        for(int i=0;i<nums.size();i++)
        {
            prod *= nums[i];
            while(prod >= k) prod /= nums[left++];
            ans += i-left+1; 
        }

        return ans;
    }
};
