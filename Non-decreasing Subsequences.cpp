class Solution 
{
    set<vector<int>> subseqs;

    void backTrack(int i, vector<int>& currSub, vector<int>& nums)
    {
        if(i == nums.size())
        {
            if(currSub.size() >= 2) subseqs.insert(currSub);
            return;
        }
        //take the element
        if(currSub.size() && currSub.back() <= nums[i])
        {
            currSub.push_back(nums[i]);
            backTrack(i+1, currSub, nums);
            currSub.pop_back();
        }
        //leave it
        backTrack(i+1, currSub, nums);
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums)
    {
        int n = nums.size();
        for(int i=0;i<n-1;i++)
        {
            vector<int> glob(1, nums[i]);
            backTrack(i+1, glob, nums);
        }
        return vector<vector<int>>(subseqs.begin(), subseqs.end());
    }
};
