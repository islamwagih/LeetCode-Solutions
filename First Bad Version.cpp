// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long low = 0, high = n+1LL;
        while(low < high-1){
            int mid = low+(high-low)/2;
            if(isBadVersion(mid)){
                high = mid;
            }else{
                low = mid;
            }
        }
        return high;
    }

};
