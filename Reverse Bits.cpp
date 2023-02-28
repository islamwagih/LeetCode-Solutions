class Solution {
public:
    uint32_t reverseBits(uint32_t n)
    {
        uint32_t x = 0, pos = 0;
        while(n > 0)
        {
            x |= ((n&1) << (31-pos));
            n >>= 1;
            ++pos;
        }
        return x;
    }
};
