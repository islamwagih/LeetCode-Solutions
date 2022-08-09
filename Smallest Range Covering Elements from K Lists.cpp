class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        set<pair<int, pair<int, int>>> st;
        for(int i=0;i<nums.size();i++){
            pair<int, pair<int, int>> pr;
            pr.first = nums[i][0];
            pr.second.first = i;
            pr.second.second = 0;
            st.insert(pr);
        }
        int minx = 0, miny = INT_MAX;
        while(st.size()){
            pair<int, pair<int, int>> minPr = *st.begin(), maxPr = *st.rbegin();
            int minElem = minPr.first, maxElem = maxPr.first;
            int arrInd = minPr.second.first;
            int minElemInd = minPr.second.second;
            if((maxElem - minElem) < (miny-minx)){
                minx = minElem;
                miny = maxElem;
            }
            if((nums[arrInd].size()-1) == minElemInd) break;
            st.erase(minPr);
            pair<int, pair<int, int>> toPush;
            toPush.first = nums[arrInd][minElemInd+1];
            toPush.second.first = arrInd;
            toPush.second.second = minElemInd+1;
            st.insert(toPush);
        }
        vector<int> vec(2);
        vec[0] = minx;
        vec[1] = miny;
        return vec;
    }
};