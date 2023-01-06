class Solution {
    int dx[4] = {+1,-1,+0,+0};
    int dy[4] = {+0,+0,+1,-1};
    vector<vector<int>> dist;
    bool valid(int i, int j, int r, int c)
    {
        return i >= 0 && j >= 0 && i < r && j < c;
    }
    void bfs(vector<vector<int>>& grid)
    {
        queue<pair<int, int>> toVis;
        int rows = grid.size(), cols = grid[0].size();
        dist = vector<vector<int>>(rows, vector<int>(cols, INT_MAX));
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                if(grid[i][j] == 0)
                {
                    dist[i][j] = 0;
                    toVis.push({i, j});
                }
            }
        }
        while(toVis.size())
        {
            pair<int, int> curr = toVis.front(); toVis.pop();
            for(int k=0;k<4;k++)
            {
                int newI = curr.first+dx[k], newJ = curr.second+dy[k];
                if
                (
                   valid(newI, newJ, rows, cols) && 
                   dist[newI][newJ] > dist[curr.first][curr.second]+1
                )
                {
                    dist[newI][newJ] = dist[curr.first][curr.second]+1;
                    toVis.push({newI, newJ});
                }
            }
        }
    }


public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat)
    {
       bfs(mat);
       return dist;
    }
};
