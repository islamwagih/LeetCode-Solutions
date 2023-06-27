class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr)
    {
        unordered_map<int, int> mp;
        for(const int& i:arr) mp[i]++;
        unordered_set<int> occs;
        for(const auto& pr:mp)
        {
            cout<<pr.first<<' '<<pr.second<<endl;
        }
        for(const auto& pr:mp)
        {
            if(occs.find(pr.second) != occs.end())
            {
                return false;
            }
            occs.insert(pr.second);
        }
        return true;
        
    }
};
