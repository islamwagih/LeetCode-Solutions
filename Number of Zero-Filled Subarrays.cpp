class Solution {
    long long numOfSubArrays(long long len)
    {
        return (len*(len+1))/2;
    }
public:
    long long zeroFilledSubarray(vector<int>& nums)
    {
        long long total = 0;
        int zerosLen = 0;
        for(int i:nums)
        {
            if(i == 0)
            {
                zerosLen++;
            }else
            {
                total += numOfSubArrays(zerosLen);
                zerosLen = 0;
            }
        }
        return total+(zerosLen == 0 ? 0:numOfSubArrays(zerosLen));
    }
};
