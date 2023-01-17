class Solution 
{
    bool overlap(vector<int>& first, vector<int>& second)
    {
        return second[0] <= first[1] && second[1] >= first[0];
    }

    vector<int> merge(vector<int>& first, vector<int>& second)
    {
        vector<int> merged(2);
        merged[0] = min(first[0], second[0]);
        merged[1] = max(first[1], second[1]);
        return merged;
    }

public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval)
    {
        bool merging = 0;
        for(auto& interval:intervals)
        {
            if(overlap(interval, newInterval))
            {
                merging = 1;
                vector<int> merged = merge(interval, newInterval);
                interval = merged;
                break;
            }
        }
        if(!merging)
        {
            intervals.push_back(newInterval);
            int n = intervals.size();
            int i = n-2;
            while(i >= 0 && intervals[i][0] > intervals[i+1][0])
            {
                swap(intervals[i], intervals[i+1]);
                i--;
            }
            return intervals;
        }
        vector<vector<int>> intrs;
        int n = intervals.size(), i = 0;
        while(i < n)
        {
            int j = i+1;
            vector<int> currInt = intervals[i];
            while(j < n && overlap(currInt, intervals[j]))
            {   
                currInt = merge(currInt, intervals[j]);
                j++;
            }
            intrs.push_back(currInt);
            i = j;
        }
        return intrs;
    }
};
