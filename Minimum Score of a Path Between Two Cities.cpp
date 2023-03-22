class Solution
{
    int n;
    vector<vector<pair<int, int>>> graph;
    vector<bool> vis;
    void dfs(int node, int& ans)
    {
        vis[node] = 1;
        for(auto& pr:graph[node])
        {
            ans = min(ans, pr.second);
            if(!vis[pr.first])
            {
                dfs(pr.first, ans);
            }
        }
    }
public:
    int minScore(int n, vector<vector<int>>& roads)
    {
        this->n = n;
        graph = vector<vector<pair<int, int>>>(n);
        vis = vector<bool>(n, 0);
        for(auto& road:roads)
        {
            graph[road[0]-1].push_back({road[1]-1, road[2]});
            graph[road[1]-1].push_back({road[0]-1, road[2]});
        }
        int ans = 1e9;
        dfs(0, ans);
        return ans;
    }
};
