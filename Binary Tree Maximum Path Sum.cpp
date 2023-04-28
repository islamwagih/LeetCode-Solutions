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
    int maxSum = INT_MIN;
public:
    int getMaxPathSum(TreeNode* root)
    {
        if(!root) return 0;
        int left = max(getMaxPathSum(root->left), 0);
        int right = max(getMaxPathSum(root->right), 0);
        maxSum = max(maxSum, root->val + left + right);
        return max(root->val+left, root->val+right);
    }
    int maxPathSum(TreeNode* root)
    {
       getMaxPathSum(root);
       return maxSum;
    }
};
