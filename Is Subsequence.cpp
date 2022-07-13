class Solution {
public:
   bool isSubsequence(string s, string t) {
        if(t.size() < s.size()) return false;
        map<char, vector<int>> mp;
        int nt = t.size();
        for(int i=0;i<nt;i++) mp[t[i]].push_back(i);
        int ns = s.size(), ploc = -1;
        for(int i=0;i<ns;i++){
            char c = s[i];
            if(mp.find(c) == mp.end()) return false;
            auto it = lower_bound(mp[c].begin(), mp[c].end(), ploc+1);
            if(it == mp[c].end()) return false;
            ploc = *it;
        }
        return true;
    }
};
