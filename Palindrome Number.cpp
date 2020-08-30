class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return 0;
        char test[100];
        char rtest[100];
        int len = fillArray(test,rtest,x);
        reverse(rtest,len);
        if(equal(test,rtest)) return 1;
        return 0;
    }
    void reverse(char *s,int length){
        int limit = length/2,i = 0,last = length-1;
        while(i<limit){
                int temp = s[i];
                s[i++] = s[last];
                s[last--] = temp;
        }
    }
    bool equal(char *s,char *t){
        while(*s && *t){
            if(*s++ == *t++)
                continue;
            else
                return false;
        }
        return true;
    }
    int fillArray(char *s,char *t,int target){
        int count = 0;
        while(target){
            *s = *t = target%10 + 48;
            s++,t++,count++;
            target/=10;
        }
        *s = *t = 0;
        return count;
    }
};