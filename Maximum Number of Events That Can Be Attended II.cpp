class Solution
{
    int n;
    vector<vector<int>> events;
    vector<vector<int>> dp;
    int maxValueDP(int i, int k)
    {
        if(k == 0 || i == n) return 0;
        if(dp[i][k] != -1) return dp[i][k]; 
        int op1 = maxValueDP(i+1, k);
        int op2 = events[i][2];
        //we can use binary search to get the upper bound value
        for(int j=i+1;j<n;j++)
        {
            if(events[j][0] > events[i][1])
            {
                op2 += maxValueDP(j, k-1);
                break;
            }
        }
        return dp[i][k] = max(op2, op1);
    }
public:
    int maxValue(vector<vector<int>>& events, int k)
    {
        sort(events.begin(), events.end(), 
        [](const vector<int>& a, const vector<int>& b) {
            if(a[0] != b[0]) return a[0] < b[0];
            return a[1] < b[1];
        }
        );
        this->events = events;
        this->n = events.size();
        this->dp = vector<vector<int>>(n, vector<int>(k+1, -1));
        return maxValueDP(0, k);
    }
};
