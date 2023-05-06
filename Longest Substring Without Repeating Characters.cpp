class Solution
{
    deque<char> subStr;
    bool visited(const char& ch)
    {
        int sz = subStr.size();
        for(int i=0;i<sz;i++) if(subStr[i] == ch) return true;
        return false;
    }
public:
    int lengthOfLongestSubstring(string s)
    {
        int n = s.size(), ans = 0;
        for(int i=0;i<n;i++)
        {
            if(visited(s[i]))
            {
                while(subStr.front() != s[i]) subStr.pop_front();
                subStr.pop_front();
            }
            subStr.push_back(s[i]);
            ans = max(ans, (int)subStr.size());
        }
        return ans;
        
    }
};
