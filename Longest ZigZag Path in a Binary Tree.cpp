/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution 
{
    int maxLen = 0;
    void dfs(TreeNode* root, bool isLeft, int steps)
    {
        if(root == nullptr) return;
        maxLen = max(maxLen, steps);
        if(isLeft)
        {
            dfs(root->left, false, steps+1);
            dfs(root->right, true, 1);
        }else
        {
            dfs(root->right, true, steps+1);
            dfs(root->left, false, 1);
        }
    }
public:
    int longestZigZag(TreeNode* root)
    {
        dfs(root, 1, 0);
        dfs(root, 0, 0);
        return maxLen;
    }
};
