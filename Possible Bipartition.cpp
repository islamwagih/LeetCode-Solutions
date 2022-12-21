class Solution {
    vector<vector<int>> graph;
    vector<int> clr;
    bool dfs(int node, int nclr)
    {
        clr[node] = nclr;
        for(int neigh:graph[node])
        {
            if(clr[neigh] == -1)
            {
                bool cond = dfs(neigh, 1-nclr);
                if(!cond) return false;

            }else if(clr[neigh] == clr[node])
            {
                return false;
            }
        }
        return true;
    }
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {    
        graph = vector<vector<int>>(n+1);
        clr = vector<int>(n+1, -1);
        for(int i=0;i<dislikes.size();i++)
        {
            int a = dislikes[i][0], b = dislikes[i][1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        for(int i=1;i<=n;i++)
        {
            if(clr[i] == -1)
            {
                bool bipartite = dfs(i, 0);
                if(!bipartite) return false;
            }
        }
        return true;
    }
};
