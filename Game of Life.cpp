class Solution {
    int dx[8] = {-1,+0,+1,-1,+0,+1, +1, -1};
    int dy[8] = {-1,-1,-1,+1,+1,+1, +0, +0};

    int livingCells(int i, int j, int rows, int cols, vector<vector<int>>& grid)
    {
        int cnt = 0;
        for(int k=0;k<8;k++)
        {
            int newi = i+dx[k], newj = j+dy[k];
            if(
                newi >= 0 && 
                newi < rows && 
                newj >= 0 && 
                newj < cols && 
                grid[newi][newj] & 1
               )
               {
                   cnt++;
               }
        }
        return cnt;
    }
public:
    void gameOfLife(vector<vector<int>>& board)
    {
        int rows = board.size(), cols = board[0].size();
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                int cnt = livingCells(i, j, rows, cols, board);
                if(!(board[i][j] & 1) && cnt == 3) board[i][j] |= (1<<1);
                else if(board[i][j] & 1 && (cnt == 2 || cnt == 3)) board[i][j] |= (1<<1);
            }
        }
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                board[i][j] >>= 1;
            }
        }
    }
};
