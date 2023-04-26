class Solution {
public:
    string reverseWords(string s)
    {
        int n = s.size();
        int left = 0, right = n - 1;
        while(left < n && s[left] == ' ') left++;
        while(right >= 0 && s[right] == ' ') right--;
        int tmpLeft = left, tmpRight = right;
        while(tmpLeft < tmpRight) swap(s[tmpLeft++], s[tmpRight--]);
        string rev = "";
        for(int i=left;i<=right;i++)
        {
            if(s[i] != ' ')
            {
                rev += s[i];
            }else
            {
                if(rev.back() == ' ') continue;
                rev += s[i];
            }
        }
        int m = rev.size();
        left = 0, right = 0;
        while(left < m)
        {
            while(right < m && rev[right] != ' ') right++;
            int end = right - 1;
            while(left < end) swap(rev[left++], rev[end--]);
            right++;
            left = right;
        }
        return rev;
    }
};
