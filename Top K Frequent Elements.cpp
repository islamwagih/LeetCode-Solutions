class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        sort(nums.begin(), nums.end());
        vector<pair<int, int>> occ;
        int lst = nums[0], cnt = 1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i] == lst)
            {
                cnt++;
            }else
            {
                occ.push_back({cnt, lst});
                cnt = 1;
                lst = nums[i];
            }
        }
        if(cnt) occ.push_back({cnt, nums[nums.size()-1]});
        sort(occ.begin(), occ.end());
        vector<int> result;
        while(k--)
        {
            result.push_back(occ.back().second);
            occ.pop_back();
        }
        return result;
    }
};
