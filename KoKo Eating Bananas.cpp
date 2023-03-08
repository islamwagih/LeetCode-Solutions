class Solution
{
    #define ll long long
    ll getHours(vector<int>& piles, ll k)
    {
        ll hours = 0;
        for(int& p:piles)
        {
            hours += ceil(p/(double)k); 
        }
        return hours;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h)
    {
        
        ll low = 0, high = 2e9;
        while(low < high - 1)
        {
            ll mid = (low+high)/2;
            ll exp = getHours(piles, mid);
            if(exp <= h)
            {
                high = mid;
            }else
            {
                low = mid;
            }
        }
        
        return high;
    }
};
