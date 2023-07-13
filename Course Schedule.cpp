class Solution
{
    vector<bool> inStack, vis;
    vector<vector<int>> graph;
    bool dfs(int node)
    {
        inStack[node] = true;
        vis[node] = true;
        for(int neigh:graph[node])
        {
            if(inStack[neigh]) return false;
            if(!vis[neigh]) if(!dfs(neigh)) return false;
        }
        inStack[node] = false;
        return true;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
    {
        int n = numCourses;
        inStack = vector<bool>(n, false);
        vis = vector<bool>(n, false);
        graph = vector<vector<int>>(n);
        for(int i=0;i<prerequisites.size();i++)
        {
            graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                bool finish = dfs(i);
                if(!finish) return false;
            }
        }
        return true;
    }
};
