class Solution
{
    vector<bool> vis;
    vector<vector<int>> graph;
    int dfs(int node)
    {
        vis[node] = true;
        int cnt = 1;
        for(int neigh:graph[node])
        {
            if(!vis[neigh])
            {
                cnt += dfs(neigh);
            }
        }
        return cnt;
    }
    
public:
    long long countPairs(int n, vector<vector<int>>& edges)
    {
        vis = vector<bool>(n);
        graph = vector<vector<int>>(n);
        for(auto& vec:edges)
        {
            graph[vec[0]].push_back(vec[1]);
            graph[vec[1]].push_back(vec[0]);
        }
        long long compSize = 0, pairs = 0, remaining = n;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                compSize = dfs(i);
                remaining -= compSize;
                pairs += compSize*remaining;
            }
        }
        return pairs;
    }
};
