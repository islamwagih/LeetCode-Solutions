class Solution
{
    class DSU
    {
        vector<int> parent;
        public:
            DSU(int n)
            {
                parent = vector<int>(n);
                iota(parent.begin(), parent.end(), 0);
            }

            int getParent(int node)
            {
                if(node == parent[node]) return node;
                return parent[node] = getParent(parent[node]);
            }

            bool join(int u, int v)
            {
                u = getParent(u), v = getParent(v);
                if(u == v) // same component
                {
                    return false;
                }
                if(u > v) swap(u, v);
                parent[u] = v;
                return true;
            }
    };
public:
    int makeConnected(int n, vector<vector<int>>& connections)
    {
        if(connections.size() < n - 1) return -1;
        DSU dsu(n);
        int connectedComponents = n;
        for(auto& conn:connections)
        {
            if(dsu.join(conn[0], conn[1])) connectedComponents--;
        }
        return connectedComponents - 1;
    }
};
