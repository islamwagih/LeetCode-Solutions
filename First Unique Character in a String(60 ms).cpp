class Solution {
public:
    int firstUniqChar(string s) {
        int allChars[26] = {0};
        int size = s.size(),i=0;
        while(i<size){
            allChars[s[i]-'a']++;
            i++;
        }
        i = 0;
        while(i<size){
            if(allChars[s[i]-'a']==1)
                return i;
            i++;
        }
        return -1;      
    }
};
