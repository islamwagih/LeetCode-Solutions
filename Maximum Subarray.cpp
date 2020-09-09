class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSub,currSub,i=1;
        maxSub = currSub = nums[0];
        int last = nums.size();
        while(i < last){
            currSub = max(currSub+nums[i],nums[i]);
            maxSub = max(maxSub,currSub);
            i++;
        }
        return maxSub;
    }
};
