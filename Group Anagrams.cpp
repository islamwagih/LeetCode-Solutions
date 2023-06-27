class Solution
{
    string sortedCopy(const string& str)
    {
        int frq[26] = {0};
        for(const char& ch:str) frq[ch - 'a']++;
        string copy = "";
        for(int i=0;i<26;i++)
        {
            while(frq[i]--)
            {
                char ch = i + 'a';
                copy += ch;
            }
        }
        return copy;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        map<string, vector<string>> mp;
        for(const string& s:strs)
        {
            mp[sortedCopy(s)].push_back(s);
        }
        vector<vector<string>> angs;
        for(const auto& pr:mp)
        {
            vector<string> group;
            for(const auto& s:pr.second)
            {
                group.push_back(s);
            }
            angs.push_back(group);
        }
        return angs;
    }
};
