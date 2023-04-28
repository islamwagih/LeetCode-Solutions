class Solution
{
    class DSU
    {
        vector<int> parent, cnt;
        public:
            DSU(int n)
            {
                parent = vector<int>(n);
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

    bool sameGroup(string& s, string& t)
    {
        int n = s.size();
        int notInPlace = 0;
        for(int i=0;i<n;i++)
        {
            if(s[i] != t[i]) notInPlace++;
        }
        return !notInPlace || notInPlace < 3;
    }
public:
    int numSimilarGroups(vector<string>& strs)
    {
        int n = strs.size();
        DSU dsu(n);
        int groups = n;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(sameGroup(strs[i], strs[j]))
                {
                    bool joined = dsu.join(i, j);
                    groups -= joined;
                }
            }
        }
        return groups;
    }
};
