class Solution {
public:
    int fib(int N) {
        if(N == 0)
            return 0;
        if(N < 3)
            return 1;
        int arr[2] = {1,1};
        N-=2;
        int temp;
        for(int i=0;i<N;i++){
            temp = arr[0];
            arr[0] = arr[1];
            arr[1]+=temp;
        }
        return arr[1];
    }
};
