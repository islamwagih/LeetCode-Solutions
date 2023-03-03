class Solution {
public:
    int compress(vector<char>& chars)
    {
        int l = 0, r = 0, j = 0, n = chars.size();
        while(l < n)
        {
            while(r < n && chars[r] == chars[l])
            {
                r++;
            }
            chars[j++] = chars[l];
            int len = r - l;
            if(len > 1)
            {
                string lenStr = to_string(len);
                for(char& c:lenStr) chars[j++] = c;
            }
            l = r;
        }
        return j;
    }
};
