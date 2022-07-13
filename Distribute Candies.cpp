class Solution {
public:
    int distributeCandies(vector<int> candies) {
        int mx = candies.size()/2;
        set<int> st(candies.begin(), candies.end());
        if(st.size() >= mx){
            return mx;
        }
        return st.size();

    }
};
