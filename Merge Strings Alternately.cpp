class Solution {
public:
    string mergeAlternately(string word1, string word2)
    {
        string merge = "";
        int l = 0, r = 0;
        while(l < word1.size() && r < word2.size())
        {
            merge += word1[l++];
            merge += word2[r++];
        }
        while(l < word1.size())
        {
            merge += word1[l++];
        }
        while(r < word2.size())
        {
            merge += word2[r++];
        }
        return merge;
    }
};
