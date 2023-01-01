class Solution {
vector<string> tokenizer(string s)
{
    stringstream ss(s);
    string word;
    vector<string> words;
    while (ss >> word) {
        words.push_back(word);
    }
    return words;
}

public:
    bool wordPattern(string pattern, string s) 
    {
        vector<string> words = tokenizer(s);
        if(words.size() != pattern.size()) return false;
        map<string, char> stoc;
        map<char, string> ctos;
        for(int i=0;i<words.size();i++)
        {
            if(stoc.find(words[i]) == stoc.end()){
                stoc[words[i]] = pattern[i];
            }else
            {
                if(stoc[words[i]] != pattern[i]) return false;
            }
            if(ctos.find(pattern[i]) == ctos.end()){
                ctos[pattern[i]] = words[i];
            }else
            {
                if(ctos[pattern[i]] != words[i]) return false;
            }
        }
        return true;
    }
};
