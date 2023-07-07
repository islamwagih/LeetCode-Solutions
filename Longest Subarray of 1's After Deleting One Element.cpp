class Solution
{
public:
    int longestSubarray(vector<int>& nums)
    {
        int n = nums.size();
        if(n == 1) return 0;
        vector<int> prefix(n, 0);
        int prvOnes = 0;
        for(int i=0;i<n;i++)
        {
            if(nums[i] == 0)
            {
                prefix[i] = prvOnes;
                prvOnes = 0;
            }else
            {
                prvOnes++;
            }
        }

        if(nums[n-1] == 1)
        {
            prefix[n-1] = prvOnes;
        }

        vector<int> suffix(n, 0);
        int aheadOnes = 0;
        for(int i=n-1;i>=0;i--)
        {
            if(nums[i] == 0)
            {
                suffix[i] = aheadOnes;
                aheadOnes = 0;
            }else
            {
                aheadOnes++;
            }
        }

        if(nums[0] == 1)
        {
            suffix[0] = aheadOnes;
        }

        int maxLen = 0;
        for(int i=0;i<n;i++)
        {
            if(prefix[i] + suffix[i] > maxLen)
            {
                maxLen = prefix[i] + suffix[i];
            }
        }

        if(maxLen == n) maxLen--;
        return maxLen;
    }
};
