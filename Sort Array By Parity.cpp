class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int size = A.size();
        vector<int> B(size);
        int evenIdx = 0, i = 0, oddIdx = size-1;
        while(evenIdx <= oddIdx){
            if(A[i]%2==0){
                B[evenIdx] = A[i];
                evenIdx++;
                
            }else{
                B[oddIdx] = A[i];
                oddIdx--;
            }
            i++;
        }
        return B;
    }
};
