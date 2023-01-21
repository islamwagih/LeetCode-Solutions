class Solution
{
    vector<string> ips;
    string s;
    void dotSeparator(int i, int subLen, string ip, int dots)
    {
        if(i == s.size())
        {
            if(dots == 3) ips.push_back(ip);
            return;
        }
        //extend if we can
        if(subLen < 3)
        {
            dotSeparator(i+1, subLen+1, ip+s[i], dots);
        }
        //put a dot if we can
        if(dots < 3 && subLen)
        {
            dotSeparator(i, 0, ip+'.', dots+1);
        }
    }

    int intLen(int x)
    {
        if(x == 0) return 1;
        int len = 0;
        while(x)
        {
            len++;
            x/=10;
        }
        return len;
    }
    int strToInt(int l, int r, string& s)
    {
        int x = 0;
        for(int i=l;i<=r;i++)
        {
            x *= 10;
            x += (s[i]-'0');
        }
        return x;
    }
    bool validIP(string& s)
    {
        int i = 0, n = s.size();
        while(i < n)
        {
            int j=i+1;
            while(j < n && s[j] != '.') j++;
            int val = strToInt(i, j-1, s), sLen = j-i, ilen = intLen(val);
            if(ilen != sLen || val > 255) return false;
            i = j+1;
        }
        return true;
    }
public:
    vector<string> restoreIpAddresses(string s)
    {
        int n = s.size();
        if(n < 4 || n > 12) return {};
        this->s = s;
        dotSeparator(0, 0, "", 0);
        vector<string> validIps;
        for(string& s:ips)
        {
            if(validIP(s)) validIps.push_back(s);
        }
        return validIps;
    }
};
