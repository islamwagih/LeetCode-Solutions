class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies)
    {
        int maxCandies = *max_element(candies.begin(), candies.end());
        vector<bool> result;
        for(int& i:candies)
        {
            bool ans = false;
            if(i+extraCandies >= maxCandies) ans = true;
            result.push_back(ans);
        }
        return result;
    }
};
