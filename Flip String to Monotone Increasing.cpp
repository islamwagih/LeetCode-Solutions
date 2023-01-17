class Solution
{
public:
    int minFlipsMonoIncr(string s)
    {
        int leftOnes = 0, rightZeros = 0; 
        for(char c:s)
        {
            if(c == '0') rightZeros++;
        }
        int ans = leftOnes+rightZeros;
        for(char c:s)
        {
            if(c == '0') rightZeros--;
            else leftOnes++;
            ans = min(ans, leftOnes+rightZeros);
        }
        return ans;
    }
};
