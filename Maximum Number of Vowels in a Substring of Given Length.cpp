class Solution
{
    int cnt[5];
    bool isVowel(char& ch)
    {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
    int vowelInd(char& ch)
    {
        switch(ch)
        {
            case 'a':return 0;
            case 'e':return 1;
            case 'i':return 2;
            case 'o':return 3;
            default:return 4;
        }
        return -1;
    }

    int getCnt()
    {
        int sum = 0;
        for(int i=0;i<5;i++) sum += cnt[i];
        return sum;
    }

public:
    int maxVowels(string s, int k)
    {
        int n = s.size(), ans = 0;
        for(int i=0;i<k && i < n;i++)
        {
            if(isVowel(s[i]))
            {
                cnt[vowelInd(s[i])]++;
            }
        }
        ans = max(ans, getCnt());
        int left = 0;
        for(int i=k;i<n;i++)
        {
            if(isVowel(s[left]))
            {
                cnt[vowelInd(s[left])]--;
            }
            if(isVowel(s[i]))
            {
                cnt[vowelInd(s[i])]++;
            }
            left++;
            ans = max(ans, getCnt());
        }
        return ans;
    }
};
