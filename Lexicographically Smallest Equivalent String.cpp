class Solution
{
    struct DSU
    {
        int parent[26];

        DSU()
        {
            for(int i=0;i<26;i++)
            {
                parent[i] = i;
            }
        }

        int getParent(int i)
        {
            if(parent[i] == i)
            {
                return i;
            }
            return parent[i] = getParent(parent[i]);
        }


        void join(int i, int j)
        {
            i = getParent(i);
            j = getParent(j);
            if(i < j) parent[j] = i; 
            else parent[i] = j;
        }
    };


public:
    string smallestEquivalentString(string s1, string s2, string baseStr)
    {
        DSU dsu;
        for(int i=0;i<s1.size();i++)
        {
            dsu.join(s1[i]-'a', s2[i]-'a');
        }
        string best = "";
        for(char c:baseStr)
        {
            best += dsu.getParent(c-'a')+'a';
        }
        return best;
    }
};
