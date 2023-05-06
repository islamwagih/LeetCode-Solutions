class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        vector<int> cnt(26, 0);
        int n = s.size(), ans = 0;
        int left = 0, largestCnt = 0;
        for(int right=0;right<n;right++)
        {
            largestCnt = max(largestCnt, ++cnt[s[right]-'A']);
            int len = right-left+1;
            if(len - largestCnt > k)
            {
                ans = max(ans, right - left);
                --cnt[s[left++]-'A'];
            }
        }
        return max(ans, n - left);
    }
};
