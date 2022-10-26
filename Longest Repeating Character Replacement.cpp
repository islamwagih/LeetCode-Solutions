class Solution {
    int frq[26];
    int mostFrq()
    {
        int mostf = 0;
        for(int i=0;i<26;i++) mostf = max(mostf, frq[i]);
        return mostf;
    }
public:
    int characterReplacement(string s, int k) {
        int low = 0, high = 0, maxLen = 0;
        frq[s[0]-'A']++;
        int n = s.size(), mostf = 1;
        while(high < n){
            if((high-low+1)-mostf <= k)
            {
                high++;
                maxLen = max(maxLen, high-low);
                if(high != n){
                    int currFrq = ++frq[s[high]-'A'];
                    if(currFrq > mostf) mostf = currFrq;
                }
            }else
            {
                frq[s[low++]-'A']--;
                mostf = mostFrq();
            }
        }
        return maxLen;

    }
};
