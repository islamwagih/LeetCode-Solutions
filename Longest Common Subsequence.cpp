class Solution {
private:
    int dp[1005][1005];
    int n, m;
    string A, B;
    int solve(int i, int j){
        if(i == n || j == m) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(A[i] == B[j]){
            dp[i][j] = 1+solve(i+1, j+1);
            return dp[i][j];
        }
        int op1 = solve(i+1, j);
        int op2 = solve(i, j+1);
        return dp[i][j] = max(op1, op2);
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp, -1, sizeof dp);
        A = text1, B = text2;
        n = A.size(), m = B.size();
        return solve(0, 0);
    }
};
