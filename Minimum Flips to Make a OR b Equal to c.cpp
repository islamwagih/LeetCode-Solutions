class Solution
{
    int fix(bool bits[3])
    {
        if(bits[2])
        {
            if(bits[0] || bits[1]) return 0;
            return 1;
        }else
        {
            if(bits[0] && bits[1]) return 2;
            else if(bits[0] || bits[1]) return 1;
        }
        return  0;
    }
public:
    int minFlips(int a, int b, int c)
    {
        bool bits[3];
        int ans = 0;
        for(int i = 0; i < 32; i++)
        {
            bits[0] = a & 1;
            bits[1] = b & 1;
            bits[2] = c & 1;
            ans += fix(bits);
            a >>= 1;
            b >>= 1;
            c >>= 1;
        }
        return ans;
    }
};
