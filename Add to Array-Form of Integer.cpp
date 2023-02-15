class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num,  int k)
    {
        vector<int> sum;
        int runningSum = k, n = num.size();
        int i = n-1;
        while(i >= 0 || runningSum > 0)
        {
            if(i >= 0) runningSum += num[i];
            sum.push_back(runningSum%10);
            runningSum /= 10;
            i--;
        }
        reverse(sum.begin(), sum.end());
        return sum;
    }
};