class Solution
{
public:
    vector<string> summaryRanges(vector<int>& nums)
    {
        int n = nums.size();
        int left = 0, right = 0;
        vector<string> ranges;
        while(left < n)
        {
            while
            (
                right+1 < nums.size() && 
                (long long)nums[right+1] - nums[right] <= 1
            )
            {
                right++;
            }
            //cout<<left<<' '<<right<<endl;
            //add left -> right
            string range = to_string(nums[left]);
            if(left != right)
            {
                range +=  "->" + to_string(nums[right]);
            }
            //add current range
            ranges.push_back(range);
            right++;
            left = right;
        }
        return ranges;
    }
};
