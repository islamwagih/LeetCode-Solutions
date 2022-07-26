class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minTillNow = INT_MAX, maxProfit = 0;
        for(int i:prices){
            //assume u will sell at this day with value i
            //and u already bought the stock at min cost day 
            maxProfit = max(maxProfit, i-minTillNow);
            minTillNow = min(minTillNow, i);
        }
        return maxProfit;
    }
};
