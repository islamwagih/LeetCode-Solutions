class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n)
    {
        vector<int> shuffled(2*n);
        int left = 0, right = n;
        for(int i=0;i<2*n-1;i+=2)
        {
            shuffled[i] = nums[left++];
            shuffled[i+1] = nums[right++];
        }
        return shuffled;
        
    }
};
