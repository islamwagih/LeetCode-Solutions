class Solution {
public:
    int firstUniqChar(string s) {
        int allChars[26] = {0};
        int size = s.size();
        for(int i=0;i<size;i++)
            allChars[s[i]-'a']++;
        for(int i=0;i<size;i++){
            if(allChars[s[i]-'a'] == 1)
                return i;
        }
        return -1;
    }
};