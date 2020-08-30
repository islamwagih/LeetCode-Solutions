class Solution {
public:
    int reverse(int x) {
       int reversed = 0;
        while(x){
            int last = x%10;
            if((reversed > INT_MAX/10)||(reversed == INT_MAX/10 && last > 7)) return 0;
            if((reversed < INT_MIN/10)||(reversed == INT_MIN/10 && last < -8)) return 0;
            reversed = reversed*10 + last;
            x/=10;
        }
        return reversed;
    }
};
