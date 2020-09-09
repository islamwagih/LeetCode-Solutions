class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int size = nums.size();
        int anchor,temp;
        anchor = 0;
        for(int exp = 0;exp<size;exp++){
            if(nums[exp] != 0){
                temp = nums[exp];
                nums[exp] = nums[anchor];
                nums[anchor] = temp;
                anchor++;
            }
        }
    }
};
