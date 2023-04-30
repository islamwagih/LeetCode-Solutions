class Solution
{
    class DSU
    {
        vector<int> parent, cnt;
        int sz;
        public:
        DSU(int n)
        {
            parent = vector<int>(n, 0);
            iota(parent.begin(), parent.end(), 0);
            cnt = vector<int>(n, 1);
            sz = n;
        }
        int find(int x)
        {
            if(parent[x] == x) return x;
            return parent[x] = find(parent[x]);
        }
        bool join(int x, int y)
        {
            x = find(x), y = find(y);
            if(x == y) return false;
            if(cnt[x] > cnt[y]) swap(x, y);
            parent[x] = y;
            cnt[y] += cnt[x];
            cnt[x] = cnt[y];
            sz--;
            return true;
        }
        bool connected()
        {
            return sz == 1;
        }
    };
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges)
    {
        DSU x(n), y(n);
        int minEdges = 0;
        for(const vector<int>& edge:edges)
        {
            if(edge[0] == 3)
            {
                minEdges += x.join(edge[1]-1, edge[2]-1) | y.join(edge[1]-1, edge[2]-1);
            }
        }

        for(const vector<int>& edge:edges)
        {
            if(edge[0] == 1)
            {
                minEdges += x.join(edge[1]-1, edge[2]-1);
            }else if(edge[0] == 2){
                minEdges += y.join(edge[1]-1, edge[2]-1);
            }
        }
        if(x.connected() && y.connected()) return edges.size() - minEdges;
        return -1;
    }
};
