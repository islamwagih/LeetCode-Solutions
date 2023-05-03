class Solution
{
    void toLowerCase(char& ch)
    {
        if(ch >= 'A' && ch <= 'Z') ch += 32;
    }
    bool skip(char ch)
    {
        return !((ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z')); 
    }
public:
    bool isPalindrome(string s)
    {
        int left = 0, right = s.size()-1;
        for(int i=0;i<=right;i++) toLowerCase(s[i]);
        while(left < right)
        {
            while(left < right && skip(s[left])) left++;
            while(right > left && skip(s[right])) right--;
            if(s[left] != s[right]) return false;
            left++, right--;
        }
        return true;
    }
};
