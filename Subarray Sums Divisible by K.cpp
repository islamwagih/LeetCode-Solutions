class Solution
{
public:
    int subarraysDivByK(vector<int>& nums, int k)
    {
        vector<int> rem(k, 0);
        rem[0] = 1;
        int prefix = 0, ans = 0;
        for(int& i:nums)
        {
            prefix += i;
            prefix %= k;
            prefix += k;
            prefix %= k;
            ans += rem[prefix]++;
        }
        return ans;
    }
};
