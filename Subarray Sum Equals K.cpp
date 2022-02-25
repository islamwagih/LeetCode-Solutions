class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0, n = nums.size(), total = 0;
        map<int, int> prefixes;
        for(int i=0;i<n;i++){
            sum += nums[i];
            if(sum == k){
                total++;
            }
            if(prefixes.find(sum-k) != prefixes.end()){
                total+=prefixes[sum-k];
            }
            prefixes[sum]++;
        }
        return total;
    }
};