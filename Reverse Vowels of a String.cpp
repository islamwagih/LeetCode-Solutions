class Solution
{
    bool isVowel(char ch)
    {
        if(ch < 'a') ch += 32;
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
public:
    string reverseVowels(string s)
    {
        int left = 0, right = (int)s.size() - 1;
        while(left < right)
        {
            if(isVowel(s[left]) && isVowel(s[right]))
            {
                swap(s[left++], s[right--]);
            }else if(isVowel(s[left]))
            {
                right--;
            }else if(isVowel(s[right]))
            {
                left++;
            }else
            {
                left++, right--;
            }
        }
        return s;
    }
};
