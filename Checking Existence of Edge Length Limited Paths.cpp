class Solution
{
    class DSU
    {
        vector<int> parent, cnt;
        public:
            DSU(int n)
            {
                parent = vector<int>(n, 0);
                iota(parent.begin(), parent.end(), 0);
                cnt = vector<int>(n, 1);
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
                return true;
            }
    };
    static bool comp(const vector<int>& A, const vector<int>& B)
    {
        return A[2] < B[2];
    }
public:
    vector<bool> distanceLimitedPathsExist
    (
        int n, 
        vector<vector<int>>& edgeList, 
        vector<vector<int>>& queries
    ){
        DSU dsu(n);
        sort(edgeList.begin(), edgeList.end(), Solution::comp);
        for(int i=0;i<queries.size();i++)
        {
            queries[i].push_back(i);
        }
        sort(queries.begin(), queries.end(), Solution::comp);
        int i = 0, j = 0;
        vector<bool> ans(queries.size(), 0);
        for(int q=0;q<queries.size();q++)
        {
            int limit = queries[q][2];
            int ind = queries[q][3];
            for(i=j;i<edgeList.size();i++)
            {
                if(edgeList[i][2] < limit)
                {
                    dsu.join(edgeList[i][0], edgeList[i][1]);
                }else
                {
                    j = i;
                    break;
                }

            }
            if(dsu.find(queries[q][0]) == dsu.find(queries[q][1]))
            {
                ans[queries[q][3]] = true;
            }
        }
        return ans;
    }
};
