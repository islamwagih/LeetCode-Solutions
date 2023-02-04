class Solution {
    bool sameHashValue(int hash1[26], int hash2[26])
    {
        for(int i=0;i<26;i++)
        {
            if(hash1[i] != hash2[i]) return false;
        }
        return true;
    }
public:
    bool checkInclusion(string s1, string s2)
    {
        int s1hash[26] = {0};
        for(char& c:s1) s1hash[c-'a']++;
        int s2hash[26] = {0};
        int s1size = s1.size(), s2size = s2.size();
        if(s2size < s1size) return false;
        for(int i=0;i<s1size;i++) s2hash[s2[i]-'a']++;
        if(sameHashValue(s1hash, s2hash)) return true;
        for(int i=s1size;i<s2size;i++)
        {
            s2hash[s2[i]-'a']++;
            s2hash[s2[i-s1size]-'a']--;
            if(sameHashValue(s1hash, s2hash)) return true;
        }
        return false;
    }
};
