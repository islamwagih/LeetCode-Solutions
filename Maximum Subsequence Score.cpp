class Solution
{
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k)
    {
        priority_queue<int> topKScores;
        long long topKSum = 0;
        vector<pair<int, int>> vec;
        for(int i=0;i<nums1.size();i++)
        {
            vec.push_back(make_pair(nums1[i], nums2[i]));
        }
        sort(
            vec.begin(), vec.end(), 
            [](pair<int, int>& a, pair<int, int>& b)
            {
                return a.second > b.second;
            }
        );
        long long ans = 0;
        for(int i=0;i<k;i++)
        {
            topKSum += vec[i].first;
            topKScores.push(-vec[i].first);
        }
        ans = topKSum*vec[k-1].second;
        for(int i=k;i<nums1.size();i++)
        {
            topKSum += vec[i].first - -1*topKScores.top();
            topKScores.pop();
            topKScores.push(-vec[i].first);
            ans = max(ans, topKSum * vec[i].second);
        }
        return ans;
    }
};
