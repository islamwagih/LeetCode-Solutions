class Solution
{
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k)
    {
        #define tri pair<int, pair<int, int>>
        priority_queue<tri, vector<tri>, greater<tri>> pq;
        set<pair<int, int>> visited;
        vector<vector<int>> ans;
        pq.push({nums1[0]+nums2[0], {0, 0}});
        visited.insert({0, 0});
        
        while(k-- && pq.size())
        {
            tri bestPair = pq.top(); pq.pop();
            int i = bestPair.second.first, j = bestPair.second.second;
            vector<int> pr(2);
            pr[0] = nums1[i], pr[1] = nums2[j];
            ans.push_back(pr);
            if(i+1 < nums1.size() && visited.find({i+1, j}) == visited.end())
            {
                tri toPush;
                toPush.first = nums1[i+1] + nums2[j];
                toPush.second.first = i+1;
                toPush.second.second = j;
                pq.push(toPush);
                visited.insert({i+1, j});
            }
            if(j+1 < nums2.size() && visited.find({i, j+1}) == visited.end())
            {
                tri toPush;
                toPush.first = nums1[i] + nums2[j+1];
                toPush.second.first = i;
                toPush.second.second = j+1;
                pq.push(toPush);
                visited.insert({i, j+1});
            }
        }
    
        return ans;
    }
};
