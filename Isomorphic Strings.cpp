class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()) return false;
        set<char> usedChars;
        map<char, char> mp;
        int n=s.size();
        for(int i=0;i<n;i++) mp[s[i]] = t[i];
        string ct = "";
        for(auto& it:mp){
            if(usedChars.find(it.second) != usedChars.end()) return false;
            else{
                usedChars.insert(it.second);
            }
        }
        for(int i=0;i<n;i++) ct+=mp[s[i]];
        return ct == t;
    }
};
