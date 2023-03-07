class Solution
{
    long long totalTrips;
    long long getTrips(vector<int>& time, long long th)
    {
        long long total = 0;
        for(int& t:time) total += th/t;
        return total;
    }
    bool ok(vector<int>& time, long long th)
    {
        return getTrips(time, th) < totalTrips;
    }
public:
    long long minimumTime(vector<int>& time, long long totalTrips)
    {
        this->totalTrips = totalTrips;
        if(time.size() == 1) return (long long)time[0] * totalTrips;
        long long  s = *min_element(time.begin(), time.end())-1, 
        e = *min_element(time.begin(), time.end())*totalTrips+1;
        while(s < e - 1)
        {
            long long m = s+(e-s)/2;
            if(ok(time, m))
            {
                s = m;
            }else
            {
                e = m;
            }
        }
        return e;
    }
};
