class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        int n = encoded.size();
        vector<int> ret(n+1);    
        ret[0] = first;
        for(int i=1;i<=n;i++){
            ret[i] = ret[i-1]^encoded[i-1];
        }
        return ret;
    }
};
