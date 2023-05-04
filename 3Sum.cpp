class Solution
{
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> result; 
        for(int i=0;i<n-2;i++)
        {
            if(i == 0 || (i>0 && nums[i] != nums[i-1]))
            {
                int left = i+1;
                int right = n-1;
                while(left < right)
                {
                    int tripleSum = nums[i] + nums[left] + nums[right];
                    if(tripleSum == 0)
                    {
                        vector<int> triple{nums[i], nums[left], nums[right]};
                        result.push_back(triple);
                        while(left < right && nums[left] == nums[left+1]) left++; 
                        while(left < right && nums[right] == nums[right-1]) right--;
                        left++;
                        right--;
                    }else if(tripleSum > 0)
                    {
                        right--;
                    }else
                    {
                        left++;
                    }
                }
            }
        }
        return result;
        
    }
};
