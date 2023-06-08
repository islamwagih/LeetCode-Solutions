class Solution {
public:
    int countNegatives(vector<vector<int>>& grid)
    {
        int n = grid.size(), m = grid[0].size(), cnt = 0;
        int r = 0, c = m-1;
        while(r < n && c >= 0)
        {
            if(grid[r][c] < 0)
            {
                cnt += n-r;
                //go left if left is negative 
                if(c-1 >= 0 && grid[r][c-1] < 0) c--;
                //go left down otherwise
                else
                {
                    c--;
                    r++;
                }
            }else
            {
                 r++;
            }
        }
        return cnt;
    }
};
