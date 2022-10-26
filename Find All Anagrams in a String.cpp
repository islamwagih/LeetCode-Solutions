class Solution {
    int org[26];
    int cpy[26];
    vector<int> indicies;
public:
    vector<int> findAnagrams(string s, string p) 
    {
        if(p.size() > s.size()) return vector<int>();
        for(char& c:p) org[c-'a']++;
        int low = 0, high = p.size()-1;
        for(int i=low;i<=high;i++) cpy[s[i]-'a']++;
        while(high < s.size())
        {
            //check if the substring from low to high is same as p
            bool isEqual = true;
            for(int i=0;i<26;i++)
            {
                if(cpy[i] != org[i])
                {
                    isEqual = false;
                    break;
                }
            }

            if(isEqual)
            {
                indicies.push_back(low);
            }

            cpy[s[low]-'a']--;
            low++;
            high++;
            if(high < s.size()) cpy[s[high]-'a']++;
        }
        return indicies;
    }
};
