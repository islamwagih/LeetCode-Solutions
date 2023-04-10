class Solution
{
    vector<bool> vis, inStack;
    vector<vector<int>> graph, cnt;
    string colors;
    int dfs(int node)
    {
        if(inStack[node] == true) return 1e9;
        if(vis[node] == true) return 0;
        vis[node] = true;
        inStack[node] = true;
        int colorInd = colors[node]-'a';
        cnt[node][colorInd] = 1;
        for(int neigh:graph[node])
        {
            if(dfs(neigh) == 1e9) return 1e9;
            for(int i=0;i<26;i++)
            {
                cnt[node][i] = max(cnt[node][i], cnt[neigh][i]+(i == colorInd ? 1:0));
            }
        }
        inStack[node] = false;
        return *max_element(cnt[node].begin(), cnt[node].end());
    }
public:
    int largestPathValue(string colors, vector<vector<int>>& edges)
    {
        this->colors = colors;
        int n = colors.size();
        vis = vector<bool>(n, 0);
        inStack = vector<bool>(n, 0);
        graph = vector<vector<int>>(n);
        cnt = vector<vector<int>>(n, vector<int>(26, 0));
        for(auto& vec:edges)
        {
            graph[vec[0]].push_back(vec[1]);
        }
        int ans = 0;
        for(int node=0;node<n;node++)
        {
            
            if(!vis[node])
            {
                ans = max(ans, dfs(node));
            }
        }
        return (ans == 1e9) ? -1:ans;
    }
};
