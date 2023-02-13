class Solution {
public:
    int countOdds(int low, int high)
    {
        if(low == high) return low & 1 ;
        int oddCount = 0;
        oddCount += low & 1;
        oddCount += high & 1;
        int others = high - low - 1;
        if(others & 1 == 0 || low & 1) return oddCount + others/2;
        return oddCount + others - others/2;    
    }
};
