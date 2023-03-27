class Solution
{
    int ans = -1, n;
    vector<bool> vis;
    vector<int> edges;
    map<int, int> mp;
public:

    void dfs(int node)
    {
        vis[node] = true;
        int neigh = edges[node];
        if(neigh == -1) return; // no neighbours
        if(vis[neigh]){
            if(mp.find(neigh) != mp.end()) // cycle
            {
                ans = max(ans, abs(mp[node]-mp[neigh])+1);
            }
            return;
        }
        mp[neigh] = mp[node]+1;
        dfs(neigh);
    }
    int longestCycle(vector<int>& edges)
    {
        n = edges.size();
        vis = vector<bool>(n, 0);
        this->edges = edges;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                mp.clear();
                dfs(i);
            }
        }
        return ans;
    }
};
