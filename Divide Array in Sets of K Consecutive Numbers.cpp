class Solution
{
public:
    bool isPossibleDivide(vector<int>& nums, int k)
    {
        if(k == 1) return true;
        int n = nums.size();
        if(n%k) return false;
        unordered_map<int, set<int>> mp;
        sort(nums.begin(), nums.end());
        for(int i=0;i<n;i++) mp[nums[i]].insert(i);
        vector<int> vis(n, 0);
        for(int i=0;i<n;i++)
        {
            if(vis[i]) continue;
            for(int delta = 1; delta < k; delta++)
            {
                int toFind = nums[i] + delta;
                if
                (
                    mp.find(toFind) == mp.end() || 
                    mp[toFind].size() == 0
                ) return false;

                int nxtIdx = *(mp[toFind].begin());
                vis[nxtIdx] = true;
                mp[toFind].erase(nxtIdx);
            }
           
            vis[i] = true;
            mp[nums[i]].erase(i);
        }
        
        return true;
    }
};
