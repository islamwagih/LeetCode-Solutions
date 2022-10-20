class Solution {
public:
    static int setBits(int x){
        int ans = 0;
        while(x){
            ans++;
            x&=(x-1);
        }
        return ans;
    }
    static bool comp(int& a, int& b){
        int bitsA = setBits(a), bitsB =  setBits(b);
        if(bitsA != bitsB) return bitsA < bitsB;
        return a < b;
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), comp);
        return arr;
        
    }
};
