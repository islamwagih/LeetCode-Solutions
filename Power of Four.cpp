class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n == 1) return true;
        if(n <= 0 || n&1) return false;
        int ind = 0, setBits = 0, setInd = 0;
        while(n){
            if(n&1){
                setBits++;
                setInd = ind;
            }
            if(setBits > 1) return false;
            n>>=1;
            ind++;
        }
        return !(setInd&1) ? true:false;
    }
};
