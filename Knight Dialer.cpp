class Solution 
{
    int n, m;

    int limit;

    bool valid(int i, int j)
    {
        if( i == 3 && j == 0 ) return false;
        if( i == 3 && j == 2 ) return false;
        return i >= 0 && i < n && j >= 0 && j < m;
    }

    int dx[8] = {-2,-2,-1,+1,-1,+1,+2,+2};
    int dy[8] = {+1,-1,+2,+2,-2,-2,+1,-1};

    int dp[5001][4][4];

    int mod = 1e9+7;

    int rec(int i, int j, int len)
    {
        if(len == limit) return 1;
        if(dp[len][i][j] != -1) return dp[len][i][j];
        int ans = 0;
        for(int k=0;k<8;k++)
        {
            int ni = i+dx[k];
            int nj = j+dy[k];
            if(valid(ni, nj))
            {
                ans = (ans%mod+rec(ni, nj, len+1)%mod)%mod;
            }
        }
        return dp[len][i][j] = ans;
    }

public:
    int knightDialer(int q)
    {
        this->limit = q;
        memset(dp, -1, sizeof dp);
        n = 4, m = 3;
        int ways = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!valid(i, j)) continue;
                ways = (ways%mod+rec(i, j, 1)%mod)%mod;
            }  
        }

        return ways;
    }
};
