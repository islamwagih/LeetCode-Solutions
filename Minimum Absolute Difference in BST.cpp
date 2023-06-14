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
    TreeNode* prv;
    int minDiff = INT_MAX;
    void inorder(TreeNode* root)
    {
        if(root == nullptr) return;
        inorder(root->left);
        if(prv) minDiff = min(minDiff, abs(prv->val - root->val));
        prv = root;
        inorder(root->right);
    }
public:
    int getMinimumDifference(TreeNode* root)
    {
        inorder(root);
        return minDiff;
    }
};
