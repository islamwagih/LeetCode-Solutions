class Solution 
{
    vector<int> getDivisors(int num)
    {
        vector<int> divs(1, 1);
        for(int i=2;i*i<=num;i++)
        {
            if(num%i == 0)
            {
                divs.push_back(i);
                int otherDiv = num/i;
                if(otherDiv != i) divs.push_back(otherDiv);
            }
        }
        return std::move(divs);
    }
public:
    bool repeatedSubstringPattern(string s)
    {
        if(s.size() <= 1) return false;
        vector<int> divisors = getDivisors(s.size());
        for(int divisor:divisors)
        {
            string base = "";
            for(int i=0;i<divisor;i++)
            {
                base += s[i];
            }
            string sub = base;
            cout<<sub<<endl;
            while(sub.size() < s.size())
            {
                sub += base;
            }
            if(sub == s) return true;
        }
        return false;
    }
};
