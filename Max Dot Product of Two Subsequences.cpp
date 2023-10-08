class Solution
{
    int n, m;
    vector<int> A, B;
    int memo[2][501][501];
    int dp(int i, int j, bool taken)
    {
        if(i >= n || j >= m)
        {
            return taken ? 0:-1e9;
        }
        if(memo[taken][i][j] != -1) return memo[taken][i][j];
        return memo[taken][i][j] = max(
            {
            A[i]*B[j]+dp(i+1, j+1, 1),
            dp(i+1, j, taken),
            dp(i, j+1, taken)
            });
    }
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2)
    {
        this->n = nums1.size();
        this->A = nums1;
        this->m = nums2.size();
        this->B = nums2;
        memset(this->memo, -1, sizeof memo);
        return dp(0, 0, 0);
    }
};
