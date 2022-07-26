class Solution {
    map<int, int> mp;
public:
    int longestPalindrome(string s) {
        for(char c:s) mp[c]++;
        int oddChars = 0;
        for(auto pr:mp) if(pr.second%2) oddChars++;
        int n = s.size();
        if(oddChars)
            return n-oddChars+1;
        return n;
    }
};
