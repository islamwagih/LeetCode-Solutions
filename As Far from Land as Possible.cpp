class Solution
{
    int maxManhatin(vector<pair<int, int>>& ones, int i, int j)
    {
        int maxDist = INT_MAX;
        for(auto& pr:ones)
        {
            maxDist = min(maxDist, abs(i-pr.first)+abs(j-pr.second));
        }
        return maxDist;
    }
public:
    int maxDistance(vector<vector<int>>& grid)
    {
        vector<pair<int, int>> ones;
        int n = grid.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] == 1) ones.push_back({i, j});
            }
        }
        if(ones.size() == 0 || ones.size() == n*n) return -1;
        int maxDist = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] == 0)
                {
                    maxDist = max(maxDist, maxManhatin(ones, i, j));
                }
            }
        }
        return maxDist;
    }
};
