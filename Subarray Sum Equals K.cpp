class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> sums;
        long long currSum = 0, cnt = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            currSum+=nums[i];
            if(currSum == k) cnt++;
            if(sums.find(currSum-k) != sums.end()) cnt+=sums[currSum-k];
            sums[currSum]++;
        }
        return cnt;
    }
};
