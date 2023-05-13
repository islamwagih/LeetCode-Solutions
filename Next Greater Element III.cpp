class Solution 
{
    long long construct(vector<int>& digits)
    {
        long long num = 0;
        for(int digit:digits)
        {
            num *= 10;
            num += digit;
        }
        return num;
    }
public:
    int nextGreaterElement(int n)
    {
        vector<int> digits;
        int tmp = n;
        while(tmp)
        {
            digits.push_back(tmp%10);
            tmp /= 10;
        }
        sort(digits.begin(), digits.end());
        long long ans = 1e18;
        do
        {
            long long test = construct(digits);
            if(test <= INT_MAX && test > n)
            {
                ans = min(ans, test);
            }
        }while(next_permutation(digits.begin(), digits.end()));
        if(ans == 1e18) return -1;
        return ans;
    }
};
