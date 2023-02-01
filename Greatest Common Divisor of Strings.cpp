class Solution
{
    bool replaced(string& base, string& sub)
    {
        string replaced = "";
        int j = 0;
        bool moved = false;
        for(int i=0;i<base.size();i++)
        {
            if(base[i] == sub[j])
            {
                j++;
                if(j == sub.size())
                {
                    moved = true;
                    j = 0;
                }
            }else
            {
                return false;
            }
           
        }
        return moved;
    }
    bool validGCD(string first, string second, string& gcd)
    {
        if(first.size() % gcd.size()) return false;
        if(second.size() % gcd.size()) return false;
        return replaced(first, gcd) && replaced(second, gcd);
    }
public:
    string gcdOfStrings(string str1, string str2)
    {
        string longestAccPrefix = "", currPrefix = "";
        int minStr = min(str1.size(), str2.size());
        for(int i=0;i<minStr;i++)
        {
            currPrefix += str1[i];
            if(validGCD(str1, str2, currPrefix))
            {
                longestAccPrefix = currPrefix;
            }
        }
        return longestAccPrefix;
        
    }
};
