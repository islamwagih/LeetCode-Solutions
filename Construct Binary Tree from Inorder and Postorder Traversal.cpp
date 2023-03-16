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
    TreeNode* construct(int left, int right, int ivalue, 
                       vector<int>& inorder, 
                       vector<int>& postorder)
    {
        if(left == right) return new TreeNode(inorder[left]);
        for(int i=left;i<=right;i++)
        {
            if(inorder[i] == postorder[ivalue])
            {
                TreeNode* root = new TreeNode(inorder[i]);
                int len = right - i + 1;
                root->left = construct(left, i-1, ivalue-len, inorder, postorder);
                root->right = construct(i+1, right, ivalue-1, inorder, postorder);
                return root; 
            }
        }
        return nullptr;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
    {
        return construct(0, inorder.size() - 1, postorder.size() - 1, inorder, postorder);
        
    }
};
