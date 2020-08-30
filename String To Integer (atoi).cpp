class Solution {
public:
    int myAtoi(string str) {
        int idx = 0;
        int sign = 1;
        while(str[idx] == ' ')idx++;
        switch(str[idx]){
        case '+':
            sign = 1;
            idx++;
            break;
        case '-':
            sign = -1;
            idx++;
            break;
        }
        int number = 0,fst = 0;
        while(str[idx] >= '0' && str[idx] <= '9'){
            int last;
            if(sign == 1)
                last = str[idx++]-48;
            else
                last = -1*(str[idx++]-48);
            if(number > INT_MAX/10 || (number == INT_MAX/10 && last > 7)) return INT_MAX;
            if(number < INT_MIN/10 || (number == INT_MIN/10 && last < -8)) return INT_MIN;
            number = number*10 + last;
        }
        return number;
    }
};
