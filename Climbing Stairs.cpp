class Solution {
public:
    int climbStairs(int n) {
        if(n == 1 || n == 2)
            return n;
        int arr[2] = {1,2};
        n-=2;
        int temp = 0;
        for(int i=0;i<n;i++){
            temp = arr[0];
            arr[0] = arr[1];
            arr[1]+=temp;
        }
        return arr[1];
    }
};
