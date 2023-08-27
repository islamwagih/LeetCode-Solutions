class Solution
{
    vector<int> stones; int n;
    vector<vector<int>> dp;
    bool canJump(int i, int k)
    {
        if(i >= n-1) return i == n-1;
        if(dp[i][k] != -1) return dp[i][k];
        bool ans = 0;
        for(int delta:{k-1, k, k+1})
        {
            int newStone = stones[i] + delta;
            auto it = lower_bound(stones.begin(), stones.end(), newStone);
            int indx = it - stones.begin();
            cout<<indx<<endl;
            if(it != stones.end() && *it == newStone && indx > i)
            {
                ans |= canJump(indx, delta);
            }
        }
        return dp[i][k] = ans;
    }
public:
    bool canCross(vector<int>& stones)
    {
        if(stones[1] - stones[0] > 1) return false;
        this->stones = stones;
        this->n = stones.size();
        this->dp = vector<vector<int>>
                    (stones.size(), vector<int>(stones.size(), -1));
        return canJump(0, 0);
    }
};
