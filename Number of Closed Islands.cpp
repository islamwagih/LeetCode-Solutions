class Solution
{
    int n, m;
    vector<vector<bool>> vis;
    int di[4] = {-1,+0,+0,+1};
    int dj[4] = {+0,-1,+1,+0};
    bool valid(int i, int j)
    {
        return i >= 0 && i < n && j >= 0 && j < m;
    }
    bool dfs(int i, int j, vector<vector<int>>& grid)
    {
        if(!valid(i, j)) return false;
        if(grid[i][j] == 1 || vis[i][j]) return true;
        vis[i][j] = true;
        bool closedIsland = true;
        for(int k=0;k<4;k++)
        {
            int newi = i+di[k], newj = j+dj[k];
            if(!dfs(newi, newj, grid))
            {
                closedIsland = false;
            }
        }
        return closedIsland;
    }
public:
    int closedIsland(vector<vector<int>>& grid)
    {
        n = grid.size(), m = grid[0].size();
        vis = vector<vector<bool>>(n, vector<bool>(m, 0));
        int cnt = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 0 && !vis[i][j] && dfs(i, j, grid))
                {
                   cnt++;
                }
            }
        }
        return cnt;
    }
};
