class Solution
{
    int dis(vector<int>& point)
    {
        return point[0]*point[0] + point[1]*point[1];
    }
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k)
    {
        priority_queue<pair<int, vector<int>>> pq;
        for(auto& point:points)
        {
            pq.push({-dis(point), point});
        }
        vector<vector<int>> resultPoints;
        while(k--)
        {
            resultPoints.push_back(pq.top().second);
            pq.pop();
        }
        return resultPoints;
    }
};
