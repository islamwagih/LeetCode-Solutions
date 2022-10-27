class Solution {
    static bool comp(const pair<int, string>& a, pair<int, string>& b)
    {
        if(a.first != b.first) return a.first > b.first;
        return a.second < b.second;
    }
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> mp;
        for(string& word:words) mp[word]++;
        vector<pair<int, string>> ret;
        for(auto& pr:mp)
        {
            ret.push_back({pr.second, pr.first});
        }
        sort(ret.begin(), ret.end(), comp);
        vector<string> strRet(k);
        for(int i=0;i<k;i++){
            strRet[i] = ret[i].second;
        }
        return strRet;
    }
};
