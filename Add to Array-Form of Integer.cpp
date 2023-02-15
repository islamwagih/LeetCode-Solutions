class Solution {
public:
    vector<int> getSum(vector<int>& a, vector<int>& b)
    {
        //ensure that a size will always be bigger than b size
        if(a.size() < b.size()) swap(a, b);
        vector<int> sum(a.size()+1, -1);
        for(int i=0;i<b.size();i++)
        {
            sum[i] = a[i] + b[i];
        }
        for(int i=b.size();i<a.size();i++)
        {
            sum[i] = a[i];
        }
        for(int i=0;i<a.size();i++)
        {
            if(sum[i] >= 10)
            {
                sum[i] -= 10;
                if(sum[i+1] == -1) sum[i+1] = 0;
                sum[i+1]++;
            }
        }
        if(sum[sum.size()-1] == -1) sum.pop_back();
        reverse(sum.begin(), sum.end());
        return sum;

    }
    vector<int> addToArrayForm(vector<int>& a, int k)
    {
        vector<int> b;
        while(k)
        {
            b.push_back(k%10);
            k /= 10;
        }
        reverse(a.begin(), a.end());
        return getSum(a, b);
    }
};
