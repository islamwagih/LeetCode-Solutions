class Solution {
    vector<vector<bool>> vis;
    int n, m;
    int dx[4] = {+1,-1,+0,+0};
    int dy[4] = {+0,+0,+1,-1};
    bool valid(int r, int c)
    {
        return r > -1 && r < n && c > -1 && c < m;
    }
    void dfs(int r, int c, vector<vector<char>>& grid){
        vis[r][c] = 1;
        for(int i=0;i<4;i++)
        {
            int newr = r+dx[i];
            int newc = c+dy[i];
            if(valid(newr, newc) && !vis[newr][newc] && grid[newr][newc] == '1') dfs(newr, newc, grid);
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vis = vector<vector<bool>>(n, vector<bool>(m,0));
        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == '1' && !vis[i][j])
                {
                    dfs(i, j, grid);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
