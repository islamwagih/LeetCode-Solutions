class Solution {
    bool same(vector<int>& a, vector<int>& b)
    {
        for(int i=0;i<26;i++) if(a[i] != b[i]) return false;
        return true;
    }
public:
    int strStr(string haystack, string needle)
    {
        if(haystack.size() < needle.size()) return -1;
        vector<int> comp(26, 0), tmp(26, 0);
        for(char& c:needle) comp[c-'a']++;
        int nsz = needle.size(), hsz = haystack.size();
        for(int i=0;i<nsz;i++)
        {
            tmp[haystack[i]-'a']++;
        }
        if(same(tmp, comp)) if(haystack.substr(0, nsz) == needle) return 0;
        int l = 0;
        for(int i=nsz;i<hsz;i++)
        {
            tmp[haystack[i]-'a']++;
            tmp[haystack[l++]-'a']--;
            if(same(tmp, comp)) if(haystack.substr(l, nsz) == needle) return l;
        }
        return -1;
    }
};
